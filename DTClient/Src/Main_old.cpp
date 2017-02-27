// This code shows the implementation of the french client to call the translator service
#if O
#include <ingenico/graphics.hpp>
#include <ingenico/service.hpp>
#include "TimeAndDateProxy.hpp"
#include <ingenico/desktopenv.hpp>
using namespace ingenico::desktopenv;
using namespace ingenico::graphics;
using namespace ingenico::service;
using namespace ingenico::os;
using namespace std;
using namespace ingenico::dateAndTime;
static GraphicLib graphicLib; // Instantiate the graphics object library only once, it takes time
static 	TimeAndDateProxy timeAndDate; // Instantiate the timeanddate proxy


Error onMenuClicked(Link & link)
{
    SoftwareSelectedEvent::Instance evt = SoftwareSelectedEvent::instantiate();

    if (link.decode(*evt) == SUCCESS) // Decode the event
    {
        Manifest::Instance manifest = Manifest::instantiate(); // Instantiate the manifest
		ostringstream display;
    Error result = ERR_FAILED;


		    graphicLib.openApplicationWindow(); // Open the application window
			graphicLib.dialogMessage("ClientFr Request", "DateFormat", GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);

				string str_date;

		     result = timeAndDate.getDate(str_date);
		    // Display result
		    			display << "result=" << result << endl << "msg=" << str_date;
		    			graphicLib.dialogMessage("ClientFr Response", display.str(),
		    					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND);
		    		    graphicLib.closeApplicationWindow(); // Close the application window

    }

    return SUCCESS;
}


int main(void) {
	Service client; // Instantiate the french client
    Explorer explorer; // Instantiate the explorer proxy

	graphicLib.openApplicationWindow(); // Open the application window
	graphicLib.setWindowSize(100, 50, GL_UNIT_PERCENT); // Window size
	graphicLib.setWindowPosition(0, 0, GL_UNIT_PERCENT); // Window position
	RefWidget window = graphicLib.getSkinWidget(GL_TYPE_WINDOW); // Window border
	window.setBorders(2, 2, 2, 2, GL_UNIT_PIXEL, GL_COLOR_BLUE);
    string family = _ING_APPLI_FAMILY;
	explorer.addIcon(family+"/Synchronous?1", "skin://icons/APPLI_DEFAULT.wgu", true, 0);
	        explorer.addIcon(family+"/Asynchronous?2", "skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);
	        explorer.addIcon(family+"/Bridge T3 -> T+?3",  "skin://icons/APPLI_DEFAULT.wgu", true, 2);

	        explorer.addIcon(family+"/Translator Manifest?4", "skin://icons/APPLI_DEFAULT.wgu", true, 3);
	        explorer.bind(SoftwareSelectedEvent::messageType, onMenuClicked, Permissions::ALL_TELIUM_PLATFORM);

// Connect to the service translator
	if (client.attachProxy(timeAndDate, "local.service.TimeAndDate")
			== SUCCESS) {
		while (1) {
// Call the translate method synchronously
		//	string str_date;
			//Error result = timeAndDate.getDate(str_date);
// Display result
			ostringstream display;
		/*	display << "result=" << result << endl << "msg=" << str_date;
			graphicLib.dialogMessage("ClientFr Response", display.str(),
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND); */
// Dispatch all asynchronous events & responses received
			client.dispatch(1000);
		}
	}
	return 0;
}
#endif
