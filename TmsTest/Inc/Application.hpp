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

#ifndef Application_hpp_INCLUDED
#define Application_hpp_INCLUDED
#include <ingenico/service.hpp>
#include <ingenico/graphics.hpp>
#include <ingenico/desktopenv.hpp>
#include <ingenico/tools.hpp>
#include "MenuBindable.hpp"

/** Simple application sample */
class Application {
public:
	/** Application constructor */
	Application(const std::string & serviceClass);

	/** Application destructor */
	~Application();

	/** Opens application
	 @return error code */
	ingenico::os::Error open();

	/** Closes application
	 @return error code */
	ingenico::os::Error close();

	/** Dispatch event received */
	void dispatch();

	/** Adds icons in the explorer menu
	 @param path full path of the menu item
	 @param object instance of a class that contains the method to call
	 @param method method called when the menu item will be clicked in the menu
	 @param icon icon displayed on the explorer
	 @return error code */
	template<class CLASS> ingenico::os::Error addMenu(const std::string & path,
			CLASS * object, void (CLASS::*method)(), const std::string & icon =
					"") {
		return addMenu(path, new MenuMethodBind<CLASS>(object, method), icon);
	}

	/** Adds a menu on explorer
	 @param path full path of the menu item
	 @param function function called when the menu item will be clicked in the menu
	 @param icon icon displayed on the explorer */
	ingenico::os::Error addMenu(const std::string & path, void (*function)(),
			const std::string & icon = "");

	/** Adds a folder on explorer
	 @param path full path of the menu item
	 @param icon icon displayed on the explorer */
	ingenico::os::Error addFolder(const std::string & path,
			const std::string & icon = "");

	/** Removes menu from the explorer
	 @param path full path of the menu item */
	ingenico::os::Error removeMenu(const std::string & path);

	/** Removes a folder from explorer
	 @param path full path of the menu item
	 @param icon icon displayed on the explorer */
	ingenico::os::Error removeFolder(const std::string & path);

protected:
	/** Adds a callback method to an event
	 @param path full path of the menu item
	 @param function function called when the menu item will be clicked in the menu
	 @param icon icon displayed on the explorer */
	ingenico::os::Error addMenu(const std::string & path, MenuBindable * menu,
			const std::string & icon = "");

	/** Calls menu callback associated to the menu
	 @param path full path of the menu item */
	void callMenu(const std::string & path);

	/** Callback called when the explorer menu clicked
	 @param link information on menu clicked
	 @return error code */
	ingenico::os::Error onMenuClicked(ingenico::service::Link & link);

	/** Clean up menu */
	void cleanMenu();

	/** Service */
	ingenico::service::Service * m_service;

	/** Explorer proxy */
	ingenico::desktopenv::Explorer m_explorer;

	/** Service directory proxy */
	ingenico::service::Directory m_directory;

	/** Menu callbacks */
	typedef std::map<std::string, MenuBindable *> MenuCallback;
	MenuCallback m_menus;
};
#endif // Application_hpp_INCLUDED
