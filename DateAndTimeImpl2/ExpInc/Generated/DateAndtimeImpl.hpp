/*
 * WARNING : This file was generated. Do NOT modify it.
 */
#ifndef ingenico_dateAndTime_DateAndtimeImpl_hpp_INCLUDED
#define ingenico_dateAndTime_DateAndtimeImpl_hpp_INCLUDED

#include <ingenico/service.hpp>
#include "DateAndTimeProxy.hpp"

namespace ingenico
{
	namespace dateAndTime
	{
		/** DateAndtimeImpl private implementation forward declaration */
		struct __attribute__((visibility("hidden"))) DateAndtimeImplPImpl;
		
		/** Forward declaration of the custom class. */
		class __attribute__((visibility("hidden"))) DateAndtimeImplCustom;
		
		/** DateAndtimeImpl implementation class. */
		class __attribute__((visibility("hidden"))) DateAndtimeImpl : public ingenico::service::Interfacable
		{
		public:
			friend DateAndtimeImplCustom;
		
			/** Constructor of the DateAndtimeImpl implementation. */
			DateAndtimeImpl();
			
			/** Constructor of the DateAndtimeImpl implementation. This constructor allows to 
			 * bind several service implementation to one interfacable declared in the service registry.
			 * @param interfacable The interfacable to bind */
			DateAndtimeImpl(ingenico::service::Interfacable* interfacable);
		
			/** Destructor of the DateAndtimeImpl implementation. */
			virtual ~DateAndtimeImpl();
		
			/** Gets the custom class instance.
			 * @return the custom class instance */
			::ingenico::dateAndTime::DateAndtimeImplCustom& getCustomImpl() const;
		
		protected:
			
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inDatestring Input parameter (message to translate).
			 * @param outDatechanged The outDatechanged parameter.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			virtual ingenico::os::Error setDate(const std::string& inDatestring, std::string& outDatechanged);
			
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param outResultofgetdate Method result.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			virtual ingenico::os::Error getDate(std::string& outResultofgetdate);
			
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			virtual ingenico::os::Error test();
			
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inTimestring Input parameter (message to translate).
			 * @param outTimechanged The outTimechanged parameter.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			virtual ingenico::os::Error setTime(const std::string& inTimestring, std::string& outTimechanged);
		
			/** Gets the link handle
			 * @return the link handle */
			ingenico::service::Link* getLink();
		
		private:
			/** Private implementation pointer */
			DateAndtimeImplPImpl* m_impl;
		
			/** Forbidden copy constructor of the DateAndtimeImpl implementation. */
			DateAndtimeImpl(const DateAndtimeImpl& ref);
			
			/** Forbidden assignment operator of the DateAndtimeImpl implementation. */
			DateAndtimeImpl& operator= (const DateAndtimeImpl& other);
		
			/** Internal callback for the method setDate of the service ingenico.dateAndTime.ITimeAndDate. */
			enum ingenico::os::Error internalSetDate(ingenico::service::Link& link);
			
			/** Internal callback for the method getDate of the service ingenico.dateAndTime.ITimeAndDate. */
			enum ingenico::os::Error internalGetDate(ingenico::service::Link& link);
			
			/** Internal callback for the method test of the service ingenico.dateAndTime.ITimeAndDate. */
			enum ingenico::os::Error internalTest(ingenico::service::Link& link);
			
			/** Internal callback for the method setTime of the service ingenico.dateAndTime.ITimeAndDate. */
			enum ingenico::os::Error internalSetTime(ingenico::service::Link& link);
			
			
		};
	}
}

#endif // ingenico_dateAndTime_DateAndtimeImpl_hpp_INCLUDED

