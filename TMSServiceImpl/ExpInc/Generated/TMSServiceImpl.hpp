/*
 * WARNING : This file was generated. Do NOT modify it.
 */
#ifndef ingenico_TMSService_TMSServiceImpl_hpp_INCLUDED
#define ingenico_TMSService_TMSServiceImpl_hpp_INCLUDED

#include <ingenico/service.hpp>
#include "TMSServiceProxy.hpp"

namespace ingenico
{
	namespace TMSService
	{
		/** TMSServiceImpl private implementation forward declaration */
		struct __attribute__((visibility("hidden"))) TMSServiceImplPImpl;
		
		/** Forward declaration of the custom class. */
		class __attribute__((visibility("hidden"))) TMSServiceImplCustom;
		
		/** TMSServiceImpl implementation class. */
		class __attribute__((visibility("hidden"))) TMSServiceImpl : public ingenico::service::Interfacable
		{
		public:
			friend TMSServiceImplCustom;
		
			/** Constructor of the TMSServiceImpl implementation. */
			TMSServiceImpl();
			
			/** Constructor of the TMSServiceImpl implementation. This constructor allows to 
			 * bind several service implementation to one interfacable declared in the service registry.
			 * @param interfacable The interfacable to bind */
			TMSServiceImpl(ingenico::service::Interfacable* interfacable);
		
			/** Destructor of the TMSServiceImpl implementation. */
			virtual ~TMSServiceImpl();
		
			/** Gets the custom class instance.
			 * @return the custom class instance */
			::ingenico::TMSService::TMSServiceImplCustom& getCustomImpl() const;
		
		protected:
			
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
			virtual ingenico::os::Error setParam(const std::string* inTmsaddress, const std::string* inSslprofile, const google::protobuf::uint32* inTcpport, const std::string* inNetworktype, const std::string* inPhonenumber, const std::string* inGprsapn, const std::string* inPpplogin, const std::string* inPpppassword, const std::string* inContractnumber, std::string& outSetparam);
			
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
			virtual ingenico::os::Error getParam(std::string& outTmsaddress, std::string& outSslprofile, google::protobuf::uint32& outTcpport, std::string& outNetworktype, std::string& outPhonenumber, std::string& outGprsapn, std::string& outPpplogin, std::string& outPpppassword, std::string& outContractnumber);
			
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
			virtual ingenico::os::Error getDefaultParam(std::string& outTmsaddress, std::string& outSslprofile, google::protobuf::uint32& outTcpport, std::string& outNetworktype, std::string& outPhonenumber, std::string& outGprsapn, std::string& outPpplogin, std::string& outPpppassword, std::string& outContractnumber);
			
			/**
			 * Service method (@ref ingenico::service::Permissions::VERTICAL).
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			virtual ingenico::os::Error download();
		
			/** Gets the link handle
			 * @return the link handle */
			ingenico::service::Link* getLink();
		
		private:
			/** Private implementation pointer */
			TMSServiceImplPImpl* m_impl;
		
			/** Forbidden copy constructor of the TMSServiceImpl implementation. */
			TMSServiceImpl(const TMSServiceImpl& ref);
			
			/** Forbidden assignment operator of the TMSServiceImpl implementation. */
			TMSServiceImpl& operator= (const TMSServiceImpl& other);
		
			/** Internal callback for the method setParam of the service ingenico.TMSService.ITMSService. */
			enum ingenico::os::Error internalSetParam(ingenico::service::Link& link);
			
			/** Internal callback for the method getParam of the service ingenico.TMSService.ITMSService. */
			enum ingenico::os::Error internalGetParam(ingenico::service::Link& link);
			
			/** Internal callback for the method getDefaultParam of the service ingenico.TMSService.ITMSService. */
			enum ingenico::os::Error internalGetDefaultParam(ingenico::service::Link& link);
			
			/** Internal callback for the method download of the service ingenico.TMSService.ITMSService. */
			enum ingenico::os::Error internalDownload(ingenico::service::Link& link);
			
			
		};
	}
}

#endif // ingenico_TMSService_TMSServiceImpl_hpp_INCLUDED

