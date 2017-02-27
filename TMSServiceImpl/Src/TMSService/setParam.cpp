#include "TMSServiceImpl.hpp"
#include "ingenico/software/tmscall/TmsCall.hpp"
using namespace ingenico::TMSService;
using namespace ingenico::software::tmscall;
using namespace std;


static NetworkType stringToNetworkType(const std::string sntype) {
	NetworkType ntype = ETHERNET;
	if (sntype == "ETHERNET")
		ntype = ETHERNET;
	else if (sntype == "GPRS") {
		ntype = GPRS;
	} else if (sntype == "MODEM") {
		ntype = MODEM;
	} else if (sntype == "X25") {
		ntype = X25;
	} else if (sntype == "GSM") {
		ntype = GSM;
	} else if (sntype == "MODEM_ISP") {
		ntype = MODEM_ISP;
	} else if (sntype == "WIFI") {
		ntype = WIFI;
	} else if (sntype == "PCL") {
		ntype = PCL;
	}
	return ntype;
}


/**
 * Service method (@ref ingenico::service::Permissions::VERTICAL).
 * @param inTmsaddress TMS Address
 * @param inSslprofile SSL Profile
 * @param inTcpport TCP Port
 * @param inNetworktype NetWork Type
 * @param inPhonenumber Phone Number
 * @param inGprsapn GPRS APN
 * @param inPpplogin PPP Login
 * @param inPpppassword PPP Password
 * @param inContractnumber Contact Number
 * @param outSetparam SetParam result.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error TMSServiceImpl::setParam(const std::string* inTmsaddress,
		const std::string* inSslprofile,
		const google::protobuf::uint32* inTcpport,
		const std::string* inNetworktype, const std::string* inPhonenumber,
		const std::string* inGprsapn, const std::string* inPpplogin,
		const std::string* inPpppassword, const std::string* inContractnumber,
		std::string& outSetparam) {
	TmsCall tms;
	TmsParameters::Instance tmsDefaultParameters = TmsParameters::instantiate();

	if(inGprsapn!=NULL)
	tmsDefaultParameters->set_gprsapn(*inGprsapn);
	if(inPpplogin!=NULL)
	tmsDefaultParameters->set_ppplogin(*inPpplogin);
	if(inPpppassword!=NULL)
	tmsDefaultParameters->set_ppppassword(*inPpppassword);
	if(inContractnumber!=NULL)
	tmsDefaultParameters->set_contractnumber(*inContractnumber);
	if(inTmsaddress!=NULL)
	tmsDefaultParameters->set_tmsaddress(*inTmsaddress);
	if(inSslprofile!=NULL)
	tmsDefaultParameters->set_sslprofile(*inSslprofile);
	if(inPhonenumber!=NULL)
	tmsDefaultParameters->set_phonenumber(*inPhonenumber);
	if(inNetworktype!=NULL)
	tmsDefaultParameters->set_networktype(stringToNetworkType(*inNetworktype));
	if(inTcpport!=NULL)
	tmsDefaultParameters->set_tcpport(*inTcpport);

	tms.setParameters(*tmsDefaultParameters);
	tms.setDefaultParameters(*tmsDefaultParameters);

	ingenico::os::Error result = ingenico::os::SUCCESS;
	return result;
}
