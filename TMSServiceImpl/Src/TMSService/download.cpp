#include "TMSServiceImpl.hpp"
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
using namespace ingenico::TMSService;



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



/**
 * Service method (@ref ingenico::service::Permissions::VERTICAL).
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error TMSServiceImpl::download()
{
	  Error eReturn = SUCCESS;
			    //-------------------------------------------------------------------------

			    TmsCall tms;
			    	TmsParameters::Instance tmsParameters = TmsParameters::instantiate();
			    	tms.getDefaultParameters(*tmsParameters);

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
			 //   const char * addr =(tmsParameters->tmsaddress()).c_str();
			    TlvTree_AddChildString( hLayer, LL_TCPIP_T_HOST_NAME,  (tmsParameters->tmsaddress()).c_str());
			    TlvTree_AddChildInteger( hLayer, LL_TCPIP_T_PORT, tmsParameters->tcpport(), LL_TCPIP_L_PORT );
			    //-------------------------------------------------------------------------
			    // Initilize configuration parameters for download session
			    TmsDownloadParameters::Instance downloadParam  = TmsDownloadParameters::instantiate();
			    // Set LinkLayer transport
			    TmsDownload::setLinkLayerTranport(*downloadParam, hConfiguration);

			    downloadParam->set_contractnumber( tmsParameters->contractnumber());
			    //Modify more parameters if needed...
			    //-------------------------------------------------------------------------
			    DownloadCall linklayerSession( "TmsTest" );
			    eReturn = linklayerSession.call(*downloadParam);
			    //-------------------------------------------------------------------------
			    TlvTree_Release( hConfiguration );
			    return eReturn;

}

