/*
 * WARNING : This file was generated. Do NOT modify it.
 */

#include "DateAndTimeProxy.hpp"
#include <list>
#include "ingenico/dateAndTime/TimeAndDate.pb.h"


using namespace ingenico::dateAndTime;

namespace ingenico
{
	namespace dateAndTime
	{
		/** Class used to bind a C function to the reception of SetDateResponse. */
		class __attribute__((visibility("hidden"))) SetDateResponseFunctionBindable : public ISetDateResponseBindable
		{
		public:
			/** Constructor
			@param function function to call */
			SetDateResponseFunctionBindable(void (*function)(std::string& outDatechanged))
			{
				this->m_function = function;
			}
		
			/** Destructor */
			virtual ~SetDateResponseFunctionBindable()
			{
				this->m_function = NULL;
			}
		
			/** Call the bound function */
			void raise(std::string& outDatechanged)
			{
				this->m_function(outDatechanged);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ISetDateResponseBindable & object)
			{
				const SetDateResponseFunctionBindable* obj = dynamic_cast<const SetDateResponseFunctionBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_function == this->m_function)
					{
						return true;
					}
				}
				return false;
			}
		
		private:
			/** Pointer to the bound function */
			void (*m_function)(std::string& outDatechanged); 
		};
		
		/** Class used to bind a C function to the reception of GetDateResponse. */
		class __attribute__((visibility("hidden"))) GetDateResponseFunctionBindable : public IGetDateResponseBindable
		{
		public:
			/** Constructor
			@param function function to call */
			GetDateResponseFunctionBindable(void (*function)(std::string& outResultofgetdate))
			{
				this->m_function = function;
			}
		
			/** Destructor */
			virtual ~GetDateResponseFunctionBindable()
			{
				this->m_function = NULL;
			}
		
			/** Call the bound function */
			void raise(std::string& outResultofgetdate)
			{
				this->m_function(outResultofgetdate);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const IGetDateResponseBindable & object)
			{
				const GetDateResponseFunctionBindable* obj = dynamic_cast<const GetDateResponseFunctionBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_function == this->m_function)
					{
						return true;
					}
				}
				return false;
			}
		
		private:
			/** Pointer to the bound function */
			void (*m_function)(std::string& outResultofgetdate); 
		};
		
		/** Class used to bind a C function to the reception of TestResponse. */
		class __attribute__((visibility("hidden"))) TestResponseFunctionBindable : public ITestResponseBindable
		{
		public:
			/** Constructor
			@param function function to call */
			TestResponseFunctionBindable(void (*function)())
			{
				this->m_function = function;
			}
		
			/** Destructor */
			virtual ~TestResponseFunctionBindable()
			{
				this->m_function = NULL;
			}
		
			/** Call the bound function */
			void raise()
			{
				this->m_function();
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ITestResponseBindable & object)
			{
				const TestResponseFunctionBindable* obj = dynamic_cast<const TestResponseFunctionBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_function == this->m_function)
					{
						return true;
					}
				}
				return false;
			}
		
		private:
			/** Pointer to the bound function */
			void (*m_function)(); 
		};
		
		/** Class used to bind a C function to the reception of SetTimeResponse. */
		class __attribute__((visibility("hidden"))) SetTimeResponseFunctionBindable : public ISetTimeResponseBindable
		{
		public:
			/** Constructor
			@param function function to call */
			SetTimeResponseFunctionBindable(void (*function)(std::string& outTimechanged))
			{
				this->m_function = function;
			}
		
			/** Destructor */
			virtual ~SetTimeResponseFunctionBindable()
			{
				this->m_function = NULL;
			}
		
			/** Call the bound function */
			void raise(std::string& outTimechanged)
			{
				this->m_function(outTimechanged);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ISetTimeResponseBindable & object)
			{
				const SetTimeResponseFunctionBindable* obj = dynamic_cast<const SetTimeResponseFunctionBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_function == this->m_function)
					{
						return true;
					}
				}
				return false;
			}
		
		private:
			/** Pointer to the bound function */
			void (*m_function)(std::string& outTimechanged); 
		};
	}
}

namespace ingenico
{
	namespace dateAndTime
	{
		/** Declaration of the proxy's private implementation */
		struct DateAndTimeProxyPImpl
		{
			typedef std::list< ingenico::dateAndTime::ISetDateResponseBindable*> SetDateResponseBinds;
		
			/** Set of all the functions or methods bound to the reception of SetDateResponse. */
			SetDateResponseBinds m_setDateResponseBindables;
		
			typedef std::list< ingenico::dateAndTime::IGetDateResponseBindable*> GetDateResponseBinds;
		
			/** Set of all the functions or methods bound to the reception of GetDateResponse. */
			GetDateResponseBinds m_getDateResponseBindables;
		
			typedef std::list< ingenico::dateAndTime::ITestResponseBindable*> TestResponseBinds;
		
			/** Set of all the functions or methods bound to the reception of TestResponse. */
			TestResponseBinds m_testResponseBindables;
		
			typedef std::list< ingenico::dateAndTime::ISetTimeResponseBindable*> SetTimeResponseBinds;
		
			/** Set of all the functions or methods bound to the reception of SetTimeResponse. */
			SetTimeResponseBinds m_setTimeResponseBindables;
		
		
			/** The reservation proxy instance */
			ingenico::service::ReservationProxy* m_reservation;
		};
	}
}

/** Constructor of the DateAndTime proxy. */
DateAndTimeProxy::DateAndTimeProxy()
{
	this->m_impl = new DateAndTimeProxyPImpl();
	this->m_impl->m_reservation = new ingenico::service::ReservationProxy();
	this->m_impl->m_reservation->setLink(this->getLink());
	// Bind the internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(SetDateResponse::messageType, this, &DateAndTimeProxy::receiveSetDateResponse, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(GetDateResponse::messageType, this, &DateAndTimeProxy::receiveGetDateResponse, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(TestResponse::messageType, this, &DateAndTimeProxy::receiveTestResponse, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(SetTimeResponse::messageType, this, &DateAndTimeProxy::receiveSetTimeResponse, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
}

/** Forbidden copy constructor of the DateAndTime proxy. */
DateAndTimeProxy::DateAndTimeProxy(const DateAndTimeProxy& ref)
{
	this->m_impl = new DateAndTimeProxyPImpl();
}

/** Forbidden assignment operator of the DateAndTime proxy. */
DateAndTimeProxy& DateAndTimeProxy::operator= (const DateAndTimeProxy& other)
{
	return *this;
}


/** Destructor of the DateAndTime proxy. */
DateAndTimeProxy::~DateAndTimeProxy()
{
	// Unbind the internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->unbind(SetDateResponse::messageType, this, &DateAndTimeProxy::receiveSetDateResponse);
	// Unbind the internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->unbind(GetDateResponse::messageType, this, &DateAndTimeProxy::receiveGetDateResponse);
	// Unbind the internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate.
	this->unbind(TestResponse::messageType, this, &DateAndTimeProxy::receiveTestResponse);
	// Unbind the internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate.
	this->unbind(SetTimeResponse::messageType, this, &DateAndTimeProxy::receiveSetTimeResponse);

	for (DateAndTimeProxyPImpl::SetDateResponseBinds::iterator it = this->m_impl->m_setDateResponseBindables.begin(); it != this->m_impl->m_setDateResponseBindables.end(); ++it)
	{
		delete *it;
	}
	for (DateAndTimeProxyPImpl::GetDateResponseBinds::iterator it = this->m_impl->m_getDateResponseBindables.begin(); it != this->m_impl->m_getDateResponseBindables.end(); ++it)
	{
		delete *it;
	}
	for (DateAndTimeProxyPImpl::TestResponseBinds::iterator it = this->m_impl->m_testResponseBindables.begin(); it != this->m_impl->m_testResponseBindables.end(); ++it)
	{
		delete *it;
	}
	for (DateAndTimeProxyPImpl::SetTimeResponseBinds::iterator it = this->m_impl->m_setTimeResponseBindables.begin(); it != this->m_impl->m_setTimeResponseBindables.end(); ++it)
	{
		delete *it;
	}

	delete this->m_impl->m_reservation;
	delete this->m_impl;
	this->m_impl = NULL;
}

/** Gets the default service class name. 
If you create a proxy you must always implement this method with service class.
@return service class name */
const std::string DateAndTimeProxy::getServiceClass() const
{
	return _ING_DEFAULT_SERVICE_NAME;
}

/** Gets the reservation proxy.
The returned class is used to reserve the exclusive use of a service.
@return the reservation proxy */
ingenico::service::ReservationProxy& DateAndTimeProxy::getReservationProxy() const
{
	return *this->m_impl->m_reservation;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param inDatestring Input parameter (message to translate).
 * @param outDatechanged The outDatechanged parameter.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::setDate(const std::string& inDatestring, std::string& outDatechanged)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	SetDateRequest::Instance request = SetDateRequest::instantiate();
	SetDateResponse::Instance response = SetDateResponse::instantiate();

	// Fill request with input parameters.
	request->set_datestring(inDatestring);

	// Send the request and wait for the response.
	result = this->getLink()->call(*request, *response);

	// Returns output parameters extracted from the response.
	if (result == ingenico::os::SUCCESS)
	{
		outDatechanged = response->datechanged();
	}

	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param inDatestring Input parameter (message to translate).
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::sendSetDateRequest(const std::string& inDatestring)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message object.
	SetDateRequest::Instance request = SetDateRequest::instantiate();

	// Fill request with input parameters.
	request->set_datestring(inDatestring);

	// Send the request.
	result = this->getLink()->send(*request);

	return result;
}

/** Register a C function to the response of SetDateResponse.
@param function function to register */
void DateAndTimeProxy::registerSetDateResponse(void (*function)(std::string& outDatechanged))
{
	if (function != NULL)
	{
		this->internalBindSetDateResponse(new SetDateResponseFunctionBindable(function));
	}
}

/** Unregister a C function from the response of SetDateResponse.
@param function function to unregister */
void DateAndTimeProxy::unregisterSetDateResponse(void (*function)(std::string& outDatechanged))
{
	if (function != NULL)
	{
		this->internalUnbindSetDateResponse(new SetDateResponseFunctionBindable(function));
	}
}

void DateAndTimeProxy::internalBindSetDateResponse(ingenico::dateAndTime::ISetDateResponseBindable* bind)
{
	this->m_impl->m_setDateResponseBindables.push_back(bind);
}

void DateAndTimeProxy::internalUnbindSetDateResponse(ingenico::dateAndTime::ISetDateResponseBindable* bind)
{
	for (DateAndTimeProxyPImpl::SetDateResponseBinds::iterator it = this->m_impl->m_setDateResponseBindables.begin(); it != this->m_impl->m_setDateResponseBindables.end(); ++it)
	{
		if (*(*it) == *bind)
		{
			// Delete the stored bindable.
			delete *it;
			// Remove if from the container.
			this->m_impl->m_setDateResponseBindables.erase(it);
			// Stop here, if the function or method is bound several time we only remove it once.
			break;
		}
	}
	delete bind;
}

ingenico::os::Error DateAndTimeProxy::receiveSetDateResponse(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;
	SetDateResponse::Instance response = SetDateResponse::instantiate();

	result = link.decode(*response.get());
	if (result == ingenico::os::SUCCESS)
	{
		// Declare temporary variables for the response parameters.
		std::string outDatechanged;
		
		// Extract the output parameters from the response.
		outDatechanged = response->datechanged();
		// Notify listeners.
		for (DateAndTimeProxyPImpl::SetDateResponseBinds::iterator it = this->m_impl->m_setDateResponseBindables.begin(); it != this->m_impl->m_setDateResponseBindables.end(); ++it)
		{
			(*it)->raise(outDatechanged);
		}
	}
	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param outResultofgetdate Method result.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::getDate(std::string& outResultofgetdate)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	GetDateRequest::Instance request = GetDateRequest::instantiate();
	GetDateResponse::Instance response = GetDateResponse::instantiate();

	// Fill request with input parameters.
	

	// Send the request and wait for the response.
	result = this->getLink()->call(*request, *response);

	// Returns output parameters extracted from the response.
	if (result == ingenico::os::SUCCESS)
	{
		outResultofgetdate = response->resultofgetdate();
	}

	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::sendGetDateRequest()
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message object.
	GetDateRequest::Instance request = GetDateRequest::instantiate();

	// Fill request with input parameters.
	

	// Send the request.
	result = this->getLink()->send(*request);

	return result;
}

/** Register a C function to the response of GetDateResponse.
@param function function to register */
void DateAndTimeProxy::registerGetDateResponse(void (*function)(std::string& outResultofgetdate))
{
	if (function != NULL)
	{
		this->internalBindGetDateResponse(new GetDateResponseFunctionBindable(function));
	}
}

/** Unregister a C function from the response of GetDateResponse.
@param function function to unregister */
void DateAndTimeProxy::unregisterGetDateResponse(void (*function)(std::string& outResultofgetdate))
{
	if (function != NULL)
	{
		this->internalUnbindGetDateResponse(new GetDateResponseFunctionBindable(function));
	}
}

void DateAndTimeProxy::internalBindGetDateResponse(ingenico::dateAndTime::IGetDateResponseBindable* bind)
{
	this->m_impl->m_getDateResponseBindables.push_back(bind);
}

void DateAndTimeProxy::internalUnbindGetDateResponse(ingenico::dateAndTime::IGetDateResponseBindable* bind)
{
	for (DateAndTimeProxyPImpl::GetDateResponseBinds::iterator it = this->m_impl->m_getDateResponseBindables.begin(); it != this->m_impl->m_getDateResponseBindables.end(); ++it)
	{
		if (*(*it) == *bind)
		{
			// Delete the stored bindable.
			delete *it;
			// Remove if from the container.
			this->m_impl->m_getDateResponseBindables.erase(it);
			// Stop here, if the function or method is bound several time we only remove it once.
			break;
		}
	}
	delete bind;
}

ingenico::os::Error DateAndTimeProxy::receiveGetDateResponse(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;
	GetDateResponse::Instance response = GetDateResponse::instantiate();

	result = link.decode(*response.get());
	if (result == ingenico::os::SUCCESS)
	{
		// Declare temporary variables for the response parameters.
		std::string outResultofgetdate;
		
		// Extract the output parameters from the response.
		outResultofgetdate = response->resultofgetdate();
		// Notify listeners.
		for (DateAndTimeProxyPImpl::GetDateResponseBinds::iterator it = this->m_impl->m_getDateResponseBindables.begin(); it != this->m_impl->m_getDateResponseBindables.end(); ++it)
		{
			(*it)->raise(outResultofgetdate);
		}
	}
	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::test()
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	TestRequest::Instance request = TestRequest::instantiate();
	TestResponse::Instance response = TestResponse::instantiate();

	// Fill request with input parameters.
	

	// Send the request and wait for the response.
	result = this->getLink()->call(*request, *response);

	// Returns output parameters extracted from the response.
	if (result == ingenico::os::SUCCESS)
	{
		
	}

	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::sendTestRequest()
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message object.
	TestRequest::Instance request = TestRequest::instantiate();

	// Fill request with input parameters.
	

	// Send the request.
	result = this->getLink()->send(*request);

	return result;
}

/** Register a C function to the response of TestResponse.
@param function function to register */
void DateAndTimeProxy::registerTestResponse(void (*function)())
{
	if (function != NULL)
	{
		this->internalBindTestResponse(new TestResponseFunctionBindable(function));
	}
}

/** Unregister a C function from the response of TestResponse.
@param function function to unregister */
void DateAndTimeProxy::unregisterTestResponse(void (*function)())
{
	if (function != NULL)
	{
		this->internalUnbindTestResponse(new TestResponseFunctionBindable(function));
	}
}

void DateAndTimeProxy::internalBindTestResponse(ingenico::dateAndTime::ITestResponseBindable* bind)
{
	this->m_impl->m_testResponseBindables.push_back(bind);
}

void DateAndTimeProxy::internalUnbindTestResponse(ingenico::dateAndTime::ITestResponseBindable* bind)
{
	for (DateAndTimeProxyPImpl::TestResponseBinds::iterator it = this->m_impl->m_testResponseBindables.begin(); it != this->m_impl->m_testResponseBindables.end(); ++it)
	{
		if (*(*it) == *bind)
		{
			// Delete the stored bindable.
			delete *it;
			// Remove if from the container.
			this->m_impl->m_testResponseBindables.erase(it);
			// Stop here, if the function or method is bound several time we only remove it once.
			break;
		}
	}
	delete bind;
}

ingenico::os::Error DateAndTimeProxy::receiveTestResponse(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;
	TestResponse::Instance response = TestResponse::instantiate();

	result = link.decode(*response.get());
	if (result == ingenico::os::SUCCESS)
	{
		// Declare temporary variables for the response parameters.
		
		// Extract the output parameters from the response.
		
		// Notify listeners.
		for (DateAndTimeProxyPImpl::TestResponseBinds::iterator it = this->m_impl->m_testResponseBindables.begin(); it != this->m_impl->m_testResponseBindables.end(); ++it)
		{
			(*it)->raise();
		}
	}
	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param inTimestring Input parameter (message to translate).
 * @param outTimechanged The outTimechanged parameter.
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::setTime(const std::string& inTimestring, std::string& outTimechanged)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	SetTimeRequest::Instance request = SetTimeRequest::instantiate();
	SetTimeResponse::Instance response = SetTimeResponse::instantiate();

	// Fill request with input parameters.
	request->set_timestring(inTimestring);

	// Send the request and wait for the response.
	result = this->getLink()->call(*request, *response);

	// Returns output parameters extracted from the response.
	if (result == ingenico::os::SUCCESS)
	{
		outTimechanged = response->timechanged();
	}

	return result;
}

/**
 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
 * @param inTimestring Input parameter (message to translate).
 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
ingenico::os::Error DateAndTimeProxy::sendSetTimeRequest(const std::string& inTimestring)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message object.
	SetTimeRequest::Instance request = SetTimeRequest::instantiate();

	// Fill request with input parameters.
	request->set_timestring(inTimestring);

	// Send the request.
	result = this->getLink()->send(*request);

	return result;
}

/** Register a C function to the response of SetTimeResponse.
@param function function to register */
void DateAndTimeProxy::registerSetTimeResponse(void (*function)(std::string& outTimechanged))
{
	if (function != NULL)
	{
		this->internalBindSetTimeResponse(new SetTimeResponseFunctionBindable(function));
	}
}

/** Unregister a C function from the response of SetTimeResponse.
@param function function to unregister */
void DateAndTimeProxy::unregisterSetTimeResponse(void (*function)(std::string& outTimechanged))
{
	if (function != NULL)
	{
		this->internalUnbindSetTimeResponse(new SetTimeResponseFunctionBindable(function));
	}
}

void DateAndTimeProxy::internalBindSetTimeResponse(ingenico::dateAndTime::ISetTimeResponseBindable* bind)
{
	this->m_impl->m_setTimeResponseBindables.push_back(bind);
}

void DateAndTimeProxy::internalUnbindSetTimeResponse(ingenico::dateAndTime::ISetTimeResponseBindable* bind)
{
	for (DateAndTimeProxyPImpl::SetTimeResponseBinds::iterator it = this->m_impl->m_setTimeResponseBindables.begin(); it != this->m_impl->m_setTimeResponseBindables.end(); ++it)
	{
		if (*(*it) == *bind)
		{
			// Delete the stored bindable.
			delete *it;
			// Remove if from the container.
			this->m_impl->m_setTimeResponseBindables.erase(it);
			// Stop here, if the function or method is bound several time we only remove it once.
			break;
		}
	}
	delete bind;
}

ingenico::os::Error DateAndTimeProxy::receiveSetTimeResponse(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;
	SetTimeResponse::Instance response = SetTimeResponse::instantiate();

	result = link.decode(*response.get());
	if (result == ingenico::os::SUCCESS)
	{
		// Declare temporary variables for the response parameters.
		std::string outTimechanged;
		
		// Extract the output parameters from the response.
		outTimechanged = response->timechanged();
		// Notify listeners.
		for (DateAndTimeProxyPImpl::SetTimeResponseBinds::iterator it = this->m_impl->m_setTimeResponseBindables.begin(); it != this->m_impl->m_setTimeResponseBindables.end(); ++it)
		{
			(*it)->raise(outTimechanged);
		}
	}
	return result;
}

