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
 * @param inTimestring Input parameter (message to translate).
 * @param outTimechanged The outTimechanged parameter.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndtimeImpl::setTime(const std::string& inTimestring, std::string& outTimechanged)
{
	Error result = SUCCESS;

		Service client; // Instance to manage a pure client to query the Settings
		ingenico::desktopenv::Settings settings; // Instance to manage the Settings
		// Connect to the buzzer service
		// Default service class name = "local.device.Settings", passing as default argument
		result = client.attachProxy(settings);
		int hour = atoi(inTimestring.substr(0, 2).c_str());
		int minute = atoi(inTimestring.substr(3, 2).c_str());
		//int year = atoi(inTimestring.substr(4, 4).c_str());
	    OSL_Debug("DEBUG => Debug message (year is = %d)", hours);
		//String dformat;
	    std::ostringstream oss;
	    oss << "TimeChanged" <<" "<< hour<<" "<<minute;
	    bool timeFormt;
		settings.getTimeFormat(timeFormt);
		if(!timeFormt)
		result = settings.setTimeFormat(true);//(hour, minute, 0);//setDate(year,month,day);
		result = settings.setTime(hour, minute, 0);//setDate(year,month,day);
		//result = settings.setDate(2017, 01,01);

		// Disconnect from the buzzer service
		client.detachProxy(settings);
		if(result==SUCCESS){
			outTimechanged=oss.str();
		}
		else
			outTimechanged="ErrorChangingTime";
		return result;
}

