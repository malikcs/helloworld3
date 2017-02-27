/*
 * WARNING : This file was generated. Do NOT modify it.
 */

#include "DateAndtimeImpl.hpp"
#include "DateAndtimeImplCustom.hpp"
#include "ingenico/dateAndTime/TimeAndDate.pb.h"


using namespace ingenico::dateAndTime;

namespace ingenico
{
	namespace dateAndTime
	{
		/** Declaration of the implementations's private implementation */
		struct DateAndtimeImplPImpl
		{
			/** The current link (can be NULL). */	 
			ingenico::service::Link* m_link;
		
			/** The interfacable used to bind callbacks when this service instance is aggregated. */
			ingenico::service::Interfacable* m_interfacable;
		
			/** The custom class instance */
			::ingenico::dateAndTime::DateAndtimeImplCustom* m_custom_impl;
		};
	}
}

/** Constructor of the DateAndtimeImpl implementation. */
DateAndtimeImpl::DateAndtimeImpl()
{
	this->m_impl = new DateAndtimeImplPImpl();
	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = NULL;
	
	// Create a new instance of the custom class.
	this->m_impl->m_custom_impl = new ::ingenico::dateAndTime::DateAndtimeImplCustom();

	// Bind the internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(SetDateRequest::messageType, this, &DateAndtimeImpl::internalSetDate, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(GetDateRequest::messageType, this, &DateAndtimeImpl::internalGetDate, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(TestRequest::messageType, this, &DateAndtimeImpl::internalTest, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate.
	this->bind(SetTimeRequest::messageType, this, &DateAndtimeImpl::internalSetTime, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);

	// Call custom initialization code.
	this->m_impl->m_custom_impl->initialize();
}

/** Constructor of the DateAndtimeImpl implementation. This constructor allows to 
 * bind several service implementation to one interfacable declared in the service registry.
 * @param interfacable The interfacable to bind */
DateAndtimeImpl::DateAndtimeImpl(ingenico::service::Interfacable* interfacable)
{
	this->m_impl = new DateAndtimeImplPImpl();
	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = interfacable;

	// Create a new instance of the custom class.
	this->m_impl->m_custom_impl = new ::ingenico::dateAndTime::DateAndtimeImplCustom();

	// Bind the internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->m_impl->m_interfacable->bind(SetDateRequest::messageType, this, &DateAndtimeImpl::internalSetDate, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate.
	this->m_impl->m_interfacable->bind(GetDateRequest::messageType, this, &DateAndtimeImpl::internalGetDate, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate.
	this->m_impl->m_interfacable->bind(TestRequest::messageType, this, &DateAndtimeImpl::internalTest, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate.
	this->m_impl->m_interfacable->bind(SetTimeRequest::messageType, this, &DateAndtimeImpl::internalSetTime, ingenico::service::Permissions::PAYMENT + ingenico::service::Permissions::VERTICAL);

	// Call custom initialization code.
	this->m_impl->m_custom_impl->initialize();
}

/** Forbidden copy constructor of the DateAndtimeImpl implementation. */
DateAndtimeImpl::DateAndtimeImpl(const DateAndtimeImpl& ref)
{
	this->m_impl = new DateAndtimeImplPImpl();
}

/** Forbidden assignment operator of the DateAndtimeImpl implementation. */
DateAndtimeImpl& DateAndtimeImpl::operator= (const DateAndtimeImpl& other)
{
	return *this;
}

/** Destructor of the DateAndtimeImpl implementation. */
DateAndtimeImpl::~DateAndtimeImpl()
{
	// Call custom finalize code.
	this->m_impl->m_custom_impl->finalize();
	delete this->m_impl->m_custom_impl;
	this->m_impl->m_custom_impl = NULL;

	ingenico::service::Interfacable* toUnbind = this;
	if (this->m_impl->m_interfacable != NULL)
	{
		toUnbind = this->m_impl->m_interfacable;
	}
	// Unbind the internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate.
	toUnbind->unbind(SetDateRequest::messageType, this, &DateAndtimeImpl::internalSetDate);
	// Unbind the internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate.
	toUnbind->unbind(GetDateRequest::messageType, this, &DateAndtimeImpl::internalGetDate);
	// Unbind the internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate.
	toUnbind->unbind(TestRequest::messageType, this, &DateAndtimeImpl::internalTest);
	// Unbind the internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate.
	toUnbind->unbind(SetTimeRequest::messageType, this, &DateAndtimeImpl::internalSetTime);

	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = NULL;
	delete this->m_impl;
	this->m_impl = NULL;
}

/** Gets the custom class instance.
@return the custom class instance */
::ingenico::dateAndTime::DateAndtimeImplCustom& DateAndtimeImpl::getCustomImpl() const
{
	return *this->m_impl->m_custom_impl;
}

/** Internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate. */
enum ingenico::os::Error DateAndtimeImpl::internalSetDate(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	SetDateRequest::Instance request = SetDateRequest::instantiate();
	SetDateResponse::Instance response = SetDateResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		std::string inDatestring;
		std::string outDatechanged;
		
		
		// Extract the input parameters from the request.
		inDatestring = request->datestring();

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->setDate(inDatestring, outDatechanged);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_datechanged(outDatechanged);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate. */
enum ingenico::os::Error DateAndtimeImpl::internalGetDate(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	GetDateRequest::Instance request = GetDateRequest::instantiate();
	GetDateResponse::Instance response = GetDateResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		std::string outResultofgetdate;
		
		
		// Extract the input parameters from the request.
		

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->getDate(outResultofgetdate);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_resultofgetdate(outResultofgetdate);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate. */
enum ingenico::os::Error DateAndtimeImpl::internalTest(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	TestRequest::Instance request = TestRequest::instantiate();
	TestResponse::Instance response = TestResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		
		
		// Extract the input parameters from the request.
		

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->test();
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate. */
enum ingenico::os::Error DateAndtimeImpl::internalSetTime(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	SetTimeRequest::Instance request = SetTimeRequest::instantiate();
	SetTimeResponse::Instance response = SetTimeResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		std::string inTimestring;
		std::string outTimechanged;
		
		
		// Extract the input parameters from the request.
		inTimestring = request->timestring();

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->setTime(inTimestring, outTimechanged);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_timechanged(outTimechanged);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}


/** Gets the link handle
@return the link handle */
ingenico::service::Link* DateAndtimeImpl::getLink()
{
	return this->m_impl->m_link;
}

