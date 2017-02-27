// This code shows the implementation of the client to call the service translator
#include <iomanip>
#include "ingenico/graphics.hpp"
#include <ingenico/desktopenv.hpp>
#include <ingenico/service.hpp>
 #include <ingenico/emulation.hpp>
#include "LinkLayer.h"
//#include <ingenico/software/tmscall/TmsCall.hpp>
#include "ingenico/software/tmscall/TmsCall.hpp"
//-----------------------------------------------------------------------------
#include "TlvTree.h"
#include "ingenico/os.hpp"
#include "ingenico/service.hpp"
#include "ingenico/software/tms/TmsDownload.hpp"
#include "ingenico/software/tms/TmsDownload.pb.h"
using namespace ingenico::software::tms;
using namespace ingenico::emulation;
static BridgeTplus bridge; // Instantiate the bridge proxy
using namespace ingenico::desktopenv;
using namespace ingenico::graphics;
using namespace ingenico::service;
using namespace ingenico::os;
using namespace std;
using namespace ingenico::software::tmscall;
static GraphicLib graphicLib; // Instanciate the graphics object library only once, it takes time


//=============================================================================
/*
Error performLinkLayerCall()
{
    Error eReturn = ERR_FAILED;
    //-------------------------------------------------------------------------
    //Exemple of LinkLayer configuration tree To modify according to your needs.
    TLV_TREE_NODE hLayer;
    TLV_TREE_NODE hConfiguration;
    // Build configuration stack.
    hConfiguration = TlvTree_New( LL_TAG_LINK_LAYER_CONFIG );
    // Physical layer.
    hLayer = TlvTree_AddChild( hConfiguration, LL_TAG_PHYSICAL_LAYER_CONFIG, NULL, 0 );
    TlvTree_AddChildInteger( hLayer, LL_PHYSICAL_T_LINK, LL_PHYSICAL_V_ETHERNET, LL_PHYSICAL_L_LINK );
    // Transport layer.
    hLayer = TlvTree_AddChild( hConfiguration, LL_TAG_TRANSPORT_LAYER_CONFIG, NULL, 0 );
    TlvTree_AddChildInteger( hLayer, LL_TRANSPORT_T_PROTOCOL, LL_TRANSPORT_V_TCPIP, LL_TRANSPORT_L_PROTOCOL );
    TlvTree_AddChildString( hLayer, LL_TCPIP_T_HOST_NAME, "10.23.71.167" );
    TlvTree_AddChildInteger( hLayer, LL_TCPIP_T_PORT, 8000, LL_TCPIP_L_PORT );
    //-------------------------------------------------------------------------
    // Initilize configuration parameters for download session
    TmsDownloadParameters::Instance downloadParam  = TmsDownloadParameters::instantiate();
    // Set LinkLayer transport
    TmsDownload::setLinkLayerTranport(*downloadParam, hConfiguration);
    //Modify more parameters if needed...
    //-------------------------------------------------------------------------
    DownloadCall linklayerSession( "MyServiceName" );
    eReturn = linklayerSession.call(*downloadParam);
    //-------------------------------------------------------------------------
    TlvTree_Release( hConfiguration );
    return eReturn;
}
*/
//=============================================================================

class DownloadCall
{
public:
    // Constructor.
    DownloadCall( const std::string & serviceClass);
    // Destructor.
    virtual ~DownloadCall();
    //Start call function

    ingenico::os::Error call( ingenico::software::tms::TmsDownloadParameters    & downloadParam);
private:
    string m_serviceClass;
    //Download session
};
DownloadCall::DownloadCall( const string & serviceClass): m_serviceClass( serviceClass ){}
DownloadCall::~DownloadCall(){}
Error DownloadCall::call(TmsDownloadParameters &downloadParam)
{
    Error eDownloadStatus = ERR_DOWNLOAD_INTERNAL;
    Error testtmp = SUCCESS;
    //-------------------------------------------------------------------------
    Service service;
    TmsDownload tmsService;
    service.attachProxy(tmsService);
    //-------------------------------------------------------------------------
    if( tmsService.isConnected() )
    {

        // Download call - blocking function until download is done
        Error eError = tmsService.call(downloadParam);
    	testtmp =eError;
        if( eError == SUCCESS )
        {
        	//testtmp = SUCCESS;
            // Retrieve download status
            TmsDownloadInfo::Instance downloadInfo = TmsDownloadInfo::instantiate();
            tmsService.getDownloadInfo(*downloadInfo);
            eDownloadStatus = static_cast<ingenico::os::Error>(downloadInfo->downloadstatus());
            //Installation management
            if( eDownloadStatus == ingenico::os::SUCCESS )
            {
                tmsService.install(true);
                tmsService.getDownloadInfo(*downloadInfo);
                //Reboot management
                if(downloadInfo->rebootneeded())
                {
                    //Telium_Exit(0x666);
                 //   Sys_log( 0, "Your termminal will reboot soon" );
                }
            }
        }
        tmsService.disconnect();
    }
    return testtmp;
}



Error onMenuClicked(Link & link) {
	SoftwareSelectedEvent::Instance evt = SoftwareSelectedEvent::instantiate();

	if (link.decode(*evt) == SUCCESS) // Decode the event
			{
		Manifest::Instance manifest = Manifest::instantiate(); // Instantiate the manifest
		string url = evt->entryurl();
		unsigned long idUrl = strtoul(url.substr(url.find("?") + 1).c_str(), 0,
				10);
		string str_date;
		string str_res;
		TmsCall proxy;
		 TmsParameters::Instance tmsParameters = TmsParameters::instantiate();
				    TmsParameters::Instance tmsDefaultParameters = TmsParameters::instantiate();
				    std::string str("");
				    ostringstream os;

				//    NetworkType netType = ETHERNET;
				  //  unsigned int tcpPort = 0;
		switch (idUrl) {
		case 1: // *** SYNCHRONOUS CALL ***
			graphicLib.openApplicationWindow(); // Open the application window
		//    proxy.getParameters(*tmsParameters);
		    proxy.getDefaultParameters(*tmsDefaultParameters);
		    os <<"gprsapn "<< tmsDefaultParameters->gprsapn()         ;
		    os <<" ppplogin ";
		    os << tmsDefaultParameters->ppplogin();
		    os <<" ppppassword ";
		    os << tmsDefaultParameters->ppppassword();
		    os <<" contactN ";
		    os << tmsDefaultParameters->contractnumber() ;
		    os <<" tmsaddress ";
		    os << tmsDefaultParameters->tmsaddress()  ;
		    os <<" sslprofile ";
		    os <<tmsDefaultParameters->sslprofile()   ;
		    os <<" phonenumber ";
		    os << tmsDefaultParameters->phonenumber()  ;
		    os <<"  ";
		    os <<   tmsDefaultParameters->networktype()     ;
		    os <<" tcpport ";
		    os << tmsDefaultParameters->tcpport()         ;
			// Display result
			graphicLib.dialogMessage("TMS", os.str(),
					GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND*5);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;
		case 2:

			graphicLib.openApplicationWindow(); // Open the application window
			//result = timeAndDate.setDate("02042015", str_res);
			// Display result
			tmsDefaultParameters->set_gprsapn(          "ApnString"         );
					    tmsDefaultParameters->set_ppplogin(         "PPP login"         );
					    tmsDefaultParameters->set_ppppassword(      "PPP password"      );
					    tmsDefaultParameters->set_contractnumber(   "1234567890123456"  );
					    tmsDefaultParameters->set_tmsaddress(       "12.12.12.12"       );
					    tmsDefaultParameters->set_sslprofile(       "SSL_PROFILE"       );
					    tmsDefaultParameters->set_phonenumber(      "1234567489123"     );
					    tmsDefaultParameters->set_networktype(      ETHERNET                );
					    tmsDefaultParameters->set_tcpport(          12345               );
					    proxy.setParameters(*tmsDefaultParameters);
					    proxy.setDefaultParameters(*tmsDefaultParameters);

			graphicLib.dialogMessage("TMS","Parameters Set", GL_ICON_NONE,
					GL_BUTTON_NONE, GL_TIME_SECOND*3);
			graphicLib.closeApplicationWindow(); // Close the application window
			break;
		case 3:
			 //  proxy.getParameters(*tmsParameters);
					    proxy.getParameters(*tmsDefaultParameters);
					    os <<"gprsapn "<< tmsDefaultParameters->gprsapn()         ;
					    os <<" ppplogin ";
					    os << tmsDefaultParameters->ppplogin();
					    os <<" ppppassword ";
					    os << tmsDefaultParameters->ppppassword();
					    os <<" contactN ";
					    os << tmsDefaultParameters->contractnumber() ;
					    os <<" tmsaddress ";
					    os << tmsDefaultParameters->tmsaddress()  ;
					    os <<" sslprofile ";
					    os <<tmsDefaultParameters->sslprofile()   ;
					    os <<" phonenumber ";
					    os << tmsDefaultParameters->phonenumber()  ;
					    os <<"  ";
					    os <<   tmsDefaultParameters->networktype()     ;
					    os <<" tcpport ";
					    os << tmsDefaultParameters->tcpport()         ;
						// Display result
						graphicLib.dialogMessage("TMS", os.str(),
								GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND*5);
						graphicLib.closeApplicationWindow(); // Close the application window
			break;
//TMS download
		case 4:
		    Error eReturn = ERR_FAILED;
		    //-------------------------------------------------------------------------

		    TmsCall tms;
		    	TmsParameters::Instance tmsParameters = TmsParameters::instantiate();
		    	tms.getParameters(*tmsParameters);

		    //Exemple of LinkLayer configuration tree To modify according to your needs.
		    TLV_TREE_NODE hLayer;
		    TLV_TREE_NODE hConfiguration;
		    // Build configuration stack.
		    hConfiguration = TlvTree_New( LL_TAG_LINK_LAYER_CONFIG );
		    // Physical layer.
		    hLayer = TlvTree_AddChild( hConfiguration, LL_TAG_PHYSICAL_LAYER_CONFIG, NULL, 0 );
		    TlvTree_AddChildInteger( hLayer, LL_PHYSICAL_T_LINK, LL_PHYSICAL_V_ETHERNET, LL_PHYSICAL_L_LINK );
		    // Transport layer.
		    hLayer = TlvTree_AddChild( hConfiguration, LL_TAG_TRANSPORT_LAYER_CONFIG, NULL, 0 );
		    TlvTree_AddChildInteger( hLayer, LL_TRANSPORT_T_PROTOCOL, LL_TRANSPORT_V_TCPIP, LL_TRANSPORT_L_PROTOCOL );
		    const char * addr =(tmsParameters->tmsaddress()).c_str();
		    TlvTree_AddChildString( hLayer, LL_TCPIP_T_HOST_NAME, "91.208.214.34");
		    TlvTree_AddChildInteger( hLayer, LL_TCPIP_T_PORT, 7019, LL_TCPIP_L_PORT );
		    //-------------------------------------------------------------------------
		    // Initilize configuration parameters for download session
		    TmsDownloadParameters::Instance downloadParam  = TmsDownloadParameters::instantiate();
		    // Set LinkLayer transport
		    TmsDownload::setLinkLayerTranport(*downloadParam, hConfiguration);

		    downloadParam->set_contractnumber("010218225");
		    //Modify more parameters if needed...
		    //-------------------------------------------------------------------------
		    DownloadCall linklayerSession( "TmsTest" );
		    eReturn = linklayerSession.call(*downloadParam);
		    //-------------------------------------------------------------------------
		    TlvTree_Release( hConfiguration );

		    ostringstream oss;
		    oss<<eReturn;
								graphicLib.dialogMessage("TMS", oss.str(),
										GL_ICON_NONE, GL_BUTTON_NONE, GL_TIME_SECOND*5);
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
		explorer.addIcon(family + "/getTMSDefParam?1",
				"skin://icons/APPLI_DEFAULT.wgu", true, 0);
		explorer.addIcon(family + "/getTMSParam?3",
				"skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);
		explorer.addIcon(family + "/setTMSParam?2",
						"skin://icons/APPLI_DEFAULT.wgu", true, 1, ""/*"2abc"*/);
		explorer.addIcon(family + "/TMSDownloadTest?4",
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
	//	if (client.attachProxy(timeAndDate, "local.service.TimeAndDate")
		//		== SUCCESS) {
			/*    // Register translate response received on the callback function
			 translator.registerTranslateResponse(onTranslateResponse);
			 // Register error event received on the callback function
			 translator.bind(ErrorEvent::messageType, onErrorEvent, Permissions::TELIUM_PAYMENT);
			 // Register counter event received on the callback function
			 translator.registerCounterEvent(onCounterEvent);*/

		//	if (client.attachProxy(bridge, "local.emulation.service")
			//		== SUCCESS) {
				while (1) {
					// Dispatch all asynchronous events & responses received
					client.dispatch(1000000);
				//}
			//}
		}
	}

	return 0;
}

