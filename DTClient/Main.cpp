// This code shows the implementation of the client to call the service translator
#include <iomanip>
#include "ingenico/graphics.hpp"
#include <ingenico/desktopenv.hpp>
#include <ingenico/service.hpp>
#include "TranslatorProxy.hpp"
#include <ingenico/emulation.hpp>
using namespace ingenico::emulation;
static BridgeTplus bridge; // Instantiate the bridge proxy
using namespace ingenico::desktopenv;
using namespace ingenico::graphics;
using namespace ingenico::service;
using namespace ingenico::os;
using namespace std;
using namespace company::service;
static GraphicLib graphicLib; // Instanciate the graphics object library only once, it takes time
static TranslatorProxy translator; // Instantiate the translate proxy

void onTranslateResponse(string & translated)
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

Error onMenuClicked(Link & link)
{
    SoftwareSelectedEvent::Instance evt = SoftwareSelectedEvent::instantiate();

    if (link.decode(*evt) == SUCCESS) // Decode the event
    {
        Manifest::Instance manifest = Manifest::instantiate(); // Instantiate the manifest
		ostringstream display;
		string msgTranslated;
    Error result = ERR_FAILED;

		string url = evt->entryurl();
		unsigned long idUrl = strtoul(url.substr(url.find("?")+1).c_str(), 0, 10);

		switch(idUrl)
		{
		case 1: // *** SYNCHRONOUS CALL ***
		    graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "hello\nTO TRANSLATE", GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);

			// Call the translate method synchronously
			result = translator.translate("hello", msgTranslated, FRENCH);
			// Display result
			display << "result=" << result << "\n""msg=" << msgTranslated;
			graphicLib.dialogMessage("ClientFr Response", display.str(), GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
		    graphicLib.closeApplicationWindow(); // Close the application window

			break;
		case 2: // *** ASYNCHRONOUS CALL ***
			graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "bye\nTO TRANSLATE", GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);

			// Call the translator method asynchronously
			translator.sendTranslateRequest("bye", FRENCH);

			// Close the application window in callback

			break;
		case 3: // *** T3 -> T+ BRIDGE ***
			graphicLib.dialogMessage("ClientFr Menu", "ITEM3", GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
			graphicLib.openApplicationWindow(); // Open the application window
			char buf[256];
			int retCode;
			// Display message sent
			strcpy(buf, "Hello T+, do you hear me?");
			display << "1-Send Data" << endl << buf;
			graphicLib.dialogMessage("Client Request", display.str(), GL_ICON_NONE,
			GL_BUTTON_NONE, 1*1000);
			display.str("");
			// Call service T+ using service call number(110) and application type(0x170)
			result = bridge.serviceCall(0x170, 110, strlen(buf)+1, buf, &retCode);
			if ((result == SUCCESS) && (retCode >= 0))
			// Display message received
			display << "2-Receive Data" << endl << buf;
			else
			display << "Processing Error" << endl << "Val=" << result;
			graphicLib.dialogMessage("Client Response", display.str(), GL_ICON_NONE,
			GL_BUTTON_CANCEL, 30*1000);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;

		case 4: // *** TRANSLATOR MANIFEST ***
			// Get the manifest of the translator service (at least one call must be done)
			*manifest = translator.getLink()->getManifest();

			// Service class name
			if (manifest->has_serviceclass() == true)
				display << "== serviceClass ==" << endl << manifest->serviceclass() << endl;
			// Service descriptor
			if (manifest->servicedescriptor_size() != 0)
			{
				display << "== serviceDescriptor(s) ==" << endl;
				for (int i=0; i<manifest->servicedescriptor_size(); i++)
					display << manifest->servicedescriptor(i) << endl;
			}
			// Service description
			if (manifest->has_description() == true)
				display << "== description ==" << endl << manifest->description() << endl;
			// Instance of connection
			if (manifest->instances_size() != 0)
			{
				display << "== instance(s) ==" << endl;
				for (int i=0; i<manifest->instances_size(); i++)
					display << manifest->instances(i) << endl;
			}
			// Service version
			if (manifest->has_version() == true)
				display << "== vv-rr-pp  ==" << endl << setfill('0') << setw(2) << manifest->version() << "-";
			// Service revision
			if (manifest->has_revision() == true)
				display << setfill('0') << setw(2) << manifest->revision() << "-";
			// Service patch
			if (manifest->has_patch() == true)
				display << setfill('0') << setw(2) << manifest->patch() << endl;
			// Interfaces supported by the service
			if (manifest->interfacenames_size() != 0)
			{
				display << "== interfaceName(s) ==" << endl;
				for (int i=0; i<manifest->interfacenames_size(); i++)
					display << manifest->interfacenames(i) << endl;
			}
			// Events supported by the service
			if (manifest->eventnames_size() != 0)
			{
				display << "== eventName(s) ==" << endl;
				for (int i=0; i<manifest->eventnames_size(); i++)
					display << manifest->eventnames(i) << endl;
			}
			// Domain and application type of the service
			if (manifest->has_appliid() == true)
				display << "== appliId  ==" << endl << hex << manifest->appliid() << endl;

			// Display manifest
			graphicLib.dialogMessage("Translator Manifest", display.str(), GL_ICON_NONE, GL_BUTTON_CANCEL, 60*GL_TIME_SECOND);
			break;
		default:
			break;
		}
    }

    return SUCCESS;
}

int main(void)
{
    Service client; // Instantiate the client
    Explorer explorer; // Instantiate the explorer proxy

    RefWidget window = graphicLib.getSkinWidget(GL_TYPE_WINDOW); // Window border
	window.setBorders(2, 2, 2, 2, GL_UNIT_PIXEL, GL_COLOR_BLUE);

    // Connect to the explorer service
    if (client.attachProxy(explorer, "local.desktopenv.explorer") == SUCCESS)
    {
        // Build menu with 4 icons
        string family = _ING_APPLI_FAMILY;
        explorer.addIcon(family+"/Synchronous?1", "skin://icons/APPLI_DEFAULT.wgu", true, 0);
        explorer.addIcon(family+"/Asynchronous?2", "skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);
        explorer.addIcon(family+"/Bridge T3 -> T+?3",  "skin://icons/APPLI_DEFAULT.wgu", true, 2);
        explorer.addIcon(family+"/Translator Manifest?4", "skin://icons/APPLI_DEFAULT.wgu", true, 3);

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
        explorer.bind(SoftwareSelectedEvent::messageType, onMenuClicked, Permissions::ALL_TELIUM_PLATFORM);

        // Connect to the translator service
        if (client.attachProxy(translator, "local.service.Translator") == SUCCESS)
        {
            // Register translate response received on the callback function
            translator.registerTranslateResponse(onTranslateResponse);
            // Register error event received on the callback function
            translator.bind(ErrorEvent::messageType, onErrorEvent, Permissions::TELIUM_PAYMENT);
            // Register counter event received on the callback function
            translator.registerCounterEvent(onCounterEvent);

            if (client.attachProxy(bridge, "local.emulation.service") == SUCCESS)
            {
            while(1)
            {
            // Dispatch all asynchronous events & responses received
            client.dispatch(1000);
            }
            }
        }
    }

    return 0;
}




