// This code shows the implementation of the client to call the service translator
#include <iomanip>
#include "ingenico/graphics.hpp"
#include <ingenico/desktopenv.hpp>
#include <ingenico/service.hpp>
#include "DateAndTimeProxy.hpp"
#include <ingenico/emulation.hpp>
using namespace ingenico::emulation;
static BridgeTplus bridge; // Instantiate the bridge proxy
using namespace ingenico::desktopenv;
using namespace ingenico::graphics;
using namespace ingenico::service;
using namespace ingenico::os;
using namespace std;
using namespace ingenico::dateAndTime;
static GraphicLib graphicLib; // Instanciate the graphics object library only once, it takes time
static DateAndTimeProxy timeAndDate; // Instantiate the timeanddate proxy

/* void onTranslateResponse(string & translated)
 {
 string display = "msg=";
 display += translated;
 graphicLib.dialogMessage("ClientFr Response", display, GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
 graphicLib.closeApplicationWindow(); // Close the application window
 }

 Error onErrorEvent(Link & link)
 {
 ErrorEvent::Instance event = ErrorEvent::instantiate();

 if (link.decode(*event) == SUCCESS)  // Decode event
 {
 ostringstream display;
 display << "error=" << event->error();
 graphicLib.dialogMessage("ClientFr Event", display.str(), GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
 }
 graphicLib.closeApplicationWindow(); // Close the application window

 return SUCCESS;
 }

 void onCounterEvent(unsigned int & counter)
 {
 ostringstream display;
 display << "counter=" << counter;
 graphicLib.dialogMessage("ClientFr Event", display.str(), GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
 graphicLib.closeApplicationWindow(); // Close the application window
 }
 */
Error onMenuClicked(Link & link) {
	SoftwareSelectedEvent::Instance evt = SoftwareSelectedEvent::instantiate();

	if (link.decode(*evt) == SUCCESS) // Decode the event
			{
		Manifest::Instance manifest = Manifest::instantiate(); // Instantiate the manifest
		ostringstream display;
		Error result = ERR_FAILED;
		string url = evt->entryurl();
		unsigned long idUrl = strtoul(url.substr(url.find("?") + 1).c_str(), 0,
				10);
		string str_date;
		string str_res;
		switch (idUrl) {

		case 1: // *** SYNCHRONOUS CALL ***

			graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "DateFormat",
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);

			result = timeAndDate.getDate(str_date);
			// Display result
			display << "result=" << result << endl << "msg=" << str_date;
			graphicLib.dialogMessage("ClientFr Response", display.str(),
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;

		case 2:

			graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "SetDate",
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
			result = timeAndDate.setDate("02042015", str_res);
			// Display result
			display << "result=" << result << endl << str_res;
			graphicLib.dialogMessage("Set Date", display.str(), GL_ICON_NONE,
					GL_BUTTON_NONE, GL_TIME_SECOND);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;

		case 3:

			graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "DateFormat",
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);

			result = timeAndDate.test();
			// Display result
			display << "result=" << result << endl << "test called";
			graphicLib.dialogMessage("test", display.str(), GL_ICON_NONE,
					GL_BUTTON_NONE, GL_TIME_SECOND);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;
		}
	}
	return SUCCESS;
}

int main(void) {
	Service client; // Instantiate the client
	Explorer explorer; // Instantiate the explorer proxy

	RefWidget window = graphicLib.getSkinWidget(GL_TYPE_WINDOW); // Window border
	window.setBorders(2, 2, 2, 2, GL_UNIT_PIXEL, GL_COLOR_BLUE);

	// Connect to the explorer service
	if (client.attachProxy(explorer, "local.desktopenv.explorer") == SUCCESS) {
		// Build menu with 4 icons
		string family = _ING_APPLI_FAMILY;
		explorer.addIcon(family + "/getDateFormat?1",
				"skin://icons/APPLI_DEFAULT.wgu", true, 0);
		explorer.addIcon(family + "/setDate?2",
				"skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);
		explorer.addIcon(family + "/test?3",
						"skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);

		// Add shortcut to icon1

		//   explorer.addShortcut("1111", family+"/Synchronous?1");

		// Add blacklist url to mask: Control panel, icon2 & icon3
		/*
		 list<string> mask;
		 mask.push_back("Control panel");
		 mask.push_back(family+"/Asynchronous?2");
		 mask.push_back(family+"/Bridge T3 -> T+?3");
		 explorer.addBlacklistedUrls(mask);
		 */

		// Bind explorer event received on the callback function
		explorer.bind(SoftwareSelectedEvent::messageType, onMenuClicked,
				Permissions::ALL_TELIUM_PLATFORM);

		// Connect to the translator service
		if (client.attachProxy(timeAndDate, "local.service.TimeAndDate")
				== SUCCESS) {
			/*    // Register translate response received on the callback function
			 translator.registerTranslateResponse(onTranslateResponse);
			 // Register error event received on the callback function
			 translator.bind(ErrorEvent::messageType, onErrorEvent, Permissions::TELIUM_PAYMENT);
			 // Register counter event received on the callback function
			 translator.registerCounterEvent(onCounterEvent);*/

			if (client.attachProxy(bridge, "local.emulation.service")
					== SUCCESS) {
				while (1) {
					// Dispatch all asynchronous events & responses received
					client.dispatch(1000);
				}
			}
		}
	}

	return 0;
}

