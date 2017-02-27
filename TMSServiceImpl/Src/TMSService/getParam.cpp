#include "TMSServiceImpl.hpp"
#include "ingenico/software/tmscall/TmsCall.hpp"
#include "ingenico/software/tms/TmsDownload.hpp"
#include "ingenico/software/tms/TmsDownload.pb.h"
using namespace ingenico::TMSService;
using namespace ingenico::software::tmscall;
using namespace std;

static string networkTypeToString(const NetworkType ntype) {
	string sntype = "ETHERNET";
	if (ntype == ETHERNET)
		sntype = "ETHERNET";
	else if (ntype == GPRS) {
		sntype = "GPRS";
	} else if (ntype == MODEM) {
		sntype = "MODEM";
	} else if (ntype == X25) {
		sntype = "X25";
	} else if (ntype == GSM) {
		sntype = "GSM";
	} else if (ntype == MODEM_ISP) {
		sntype = "MODEM_ISP";
	} else if (ntype == WIFI) {
		sntype = "WIFI";
	} else if (ntype == PCL) {
		sntype = "PCL";
	}
	return sntype;
}

/**
 * Service method (@ref ingenico::service::Permissions::VERTICAL).
 * @param outTmsaddress TMS Address
 * @param outSslprofile SSL Profile
 * @param outTcpport TCP Port
 * @param outNetworktype NetWork Type
 * @param outPhonenumber Phone Number
 * @param outGprsapn GPRS APN
 * @param outPpplogin PPP Login
 * @param outPpppassword PPP Password
 * @param outContractnumber Contact Number
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error TMSServiceImpl::getParam(std::string& outTmsaddress,
		std::string& outSslprofile, google::protobuf::uint32& outTcpport,
		std::string& outNetworktype, std::string& outPhonenumber,
		std::string& outGprsapn, std::string& outPpplogin,
		std::string& outPpppassword, std::string& outContractnumber) {

	TmsCall tms;
	TmsParameters::Instance tmsParameters = TmsParameters::instantiate();
	ostringstream os;

	tms.getParameters(*tmsParameters);
	outGprsapn = tmsParameters->gprsapn();

	outPpplogin = tmsParameters->ppplogin();
	outPpppassword = tmsParameters->ppppassword();
	outContractnumber = tmsParameters->contractnumber();
	outTmsaddress = tmsParameters->tmsaddress();
	outSslprofile = tmsParameters->sslprofile();
	outPhonenumber = tmsParameters->phonenumber();
	outNetworktype = networkTypeToString(tmsParameters->networktype());
	outTcpport = tmsParameters->tcpport();
	ingenico::os::Error result = ingenico::os::SUCCESS;
	return result;
}

