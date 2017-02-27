#include "DateAndtimeImpl.hpp"
#include "DateAndtimeImpl.hpp"
#include "ingenico/os.hpp"
#include "ingenico/os.hpp"
#include "ingenico/service.hpp"
#include "ingenico/desktopenv.hpp"
using namespace ingenico::service;
using namespace ingenico::os;
using namespace ingenico::desktopenv;
using namespace ingenico::dateAndTime;

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param inDatestring Input parameter (message to translate).
 * @param outDatechanged The outDatechanged parameter.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndtimeImpl::setDate(const std::string& inDatestring, std::string& outDatechanged)
{
	Error result = SUCCESS;

	Service client; // Instance to manage a pure client to query the Settings
	ingenico::desktopenv::Settings settings; // Instance to manage the Settings
	// Connect to the buzzer service
	// Default service class name = "local.device.Settings", passing as default argument
	result = client.attachProxy(settings);
	int day = atoi(inDatestring.substr(0, 2).c_str());
	int month = atoi(inDatestring.substr(2, 2).c_str());
	int year = atoi(inDatestring.substr(4, 4).c_str());
    OSL_Debug("DEBUG => Debug message (year is = %d)", year);
	//String dformat;
    std::ostringstream oss;
    oss << "dateChanged" <<" "<< year<<" "<<month<<" "<<day;
	result = settings.setDate(year,month,day);
	//result = settings.setDate(2017, 01,01);

	// Disconnect from the buzzer service
	client.detachProxy(settings);
	if(result==SUCCESS)
		outDatechanged=oss.str();
	else
			outDatechanged="ErrorChangingDate";
	return result;
}

