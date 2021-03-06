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
 * @param outResultofgetdate Method result.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndtimeImpl::getDate(std::string& outResultofgetdate)
{
	Error result=ERR_FAILED;

	Service client; // Instance to manage a pure client to query the Settings
	ingenico::desktopenv::Settings settings; // Instance to manage the Settings
	// Connect to the buzzer service
			// Default service class name = "local.device.Settings", passing as default argument
			result = client.attachProxy(settings);
			//String dformat;
			result = settings.getDateFormat(outResultofgetdate);
				// Disconnect from the buzzer service
		    client.detachProxy(settings);
		return result;
}

