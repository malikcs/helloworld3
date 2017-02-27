/*----------------------------------------------------------------------------
 INGENICO Technical Software Department
 ------------------------------------------------------------------------------
 Copyright (c) 2015, Ingenico.
 28-32 boulevard de Grenelle 75015 Paris, France.
 All rights reserved.
 This source program is the property of INGENICO Company and may not be copied
 in any form or by any means, whether in part or in whole, except under license
 expressly granted by INGENICO company
 All copies of this program, whether in part or in whole, and
 whether modified or not, must display this and all other
 embedded copyright and ownership notices in full. */

#include "Application.hpp"

using namespace std;
using namespace ingenico::service;
using namespace ingenico::os;
using namespace ingenico::graphics;
using namespace ingenico::desktopenv;

/** Application constructor */
Application::Application(const std::string & serviceClass) {
	Manifest::Instance manifest = Manifest::instantiate();
	unsigned long version = strtoul(_ING_APPLI_TELIUM_TETRA_PACKAGE_VERSION, 0,
			10);

	// Initializes the service class of application
	manifest->set_serviceclass(serviceClass);

	// Sets the description of application
	manifest->set_description(_ING_APPLI_FAMILY);

	// Sets the version of application
	manifest->set_version(version / 10000);

	// Sets the revision of application
	manifest->set_revision((version / 100) % 100);

	// Sets the version of application
	manifest->set_patch(version % 100);

	// Instantiate the service
	m_service = new Service(*manifest);

	// open
	open();
}

/** Destructor of application */
Application::~Application() {
	// Unplug all proxy
	close();

	delete m_service;
}

/** Opens application
 @return error code */
Error Application::open() {
	Error result = ERR_FAILED;

	// Connection to the service directory
	result = m_directory.connect();

	// The connection successful
	if (result == SUCCESS) {
		// Plug application to the explorer service
		result = m_service->attachProxy(m_explorer);

		// Bind the callback on explorer event
		if (result == SUCCESS) {
			// bind menu
			m_explorer.bind(SoftwareSelectedEvent::messageType, this,
					&Application::onMenuClicked,
					Permissions::ALL_TELIUM_PLATFORM + Permissions::PAYMENT);
		}
	}

	return result;
}

/** Plugs all service from the application
 @return error code */
Error Application::close() {
	Error result = ERR_FAILED;

	// Clean up all menu registered in the explorer
	cleanMenu();

	// Unbind explorer callback
	m_explorer.unbind(SoftwareSelectedEvent::messageType, this,
			&Application::onMenuClicked);

	// Unplugs the explorer service from the application
	result = m_service->detachProxy(m_explorer);

	// If unplugAll successful
	if (result == SUCCESS) {
		// Disconnect service directory
		result = m_directory.disconnect();
	}
	return result;
}

/** Adds a callback method to an event
 @param path full path of the menu item
 @param function function called when the menu item will be clicked in the menu
 @param icon icon displayed on the explorer */
Error Application::addMenu(const std::string & path, void (*function)(),
		const std::string & icon) {
	return addMenu(path, new MenuFunctionBind(function), icon);
}

/** Adds a callback method to an event
 @param path full path of the menu item
 @param function function called when the menu item will be clicked in the menu
 @param icon icon displayed on the explorer */
Error Application::addMenu(const std::string & path, MenuBindable * menu,
		const std::string & icon) {
	Error result = ERR_FAILED;
	MenuCallback::iterator i;

	// Search if the path
	i = m_menus.find(path);

	// If the path not yet registered
	if (i == m_menus.end()) {
		// Adds an icon on the explorer
		result = m_explorer.addIcon(path,
				(icon == "" ? "skin://icons/APPLI_DEFAULT.wgu" : icon), true,
				0);

		// If the icon added
		if (result == SUCCESS) {
			// Binds the url name to the menu method of this current application
			m_menus[path] = menu;
		}
	} else {
		// Remove allocated menu
		delete menu;
	}

	return result;
}

/** Removes icons from the explorer menu
 @param path full path of the menu item
 @return error code */
Error Application::removeMenu(const string & path) {
	Error result;

	// Removes the icon in the explorer
	result = m_explorer.removeIcon(path);

	// If the icon added
	if (result == SUCCESS) {
		MenuCallback::iterator i;

		// Search the callback
		i = m_menus.find(path);

		// If the item found
		if (i != m_menus.end()) {
			// Destroy menu bind
			delete i->second;

			// Remove callback registered
			m_menus.erase(i);
		}
	}
	return result;
}

/** Calls menu callback associated to the menu
 @param path full path of the menu item */
void Application::callMenu(const string & path) {
	MenuCallback::iterator i;

	// Search the callback
	i = m_menus.find(path);

	// If the item found
	if (i != m_menus.end()) {
		// Call menu callback bound to explorer click
		i->second->raise();
	}
}

/** Clean up menu */
void Application::cleanMenu() {
	MenuCallback::iterator i = m_menus.begin();

	// While a menu item existing
	while (i != m_menus.end()) {
		// Remove explorer menu
		removeMenu(i->first);

		// Select the first menu
		i = m_menus.begin();
	}
}

/** Callback called when the explorer menu clicked
 @param link information on menu clicked
 @return error code */
Error Application::onMenuClicked(ingenico::service::Link & link) {
	// Instanciate event used in the decodage
	SoftwareSelectedEvent::Instance evt = SoftwareSelectedEvent::instantiate();

	// Decode the event
	if (link.decode(*evt) == SUCCESS) {
		// Call the method bound to the menu clicked
		callMenu(evt->entryurl());
	}
	return SUCCESS;
}

/** Dispatch event received */
void Application::dispatch() {
	m_service->dispatch();
}

