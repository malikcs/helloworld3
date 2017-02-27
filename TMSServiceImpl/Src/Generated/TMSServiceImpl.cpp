/*
 * WARNING : This file was generated. Do NOT modify it.
 */

#include "TMSServiceImpl.hpp"
#include "TMSServiceImplCustom.hpp"
#include "ingenico/TMSService/TMSService.pb.h"


using namespace ingenico::TMSService;

namespace ingenico
{
	namespace TMSService
	{
		/** Declaration of the implementations's private implementation */
		struct TMSServiceImplPImpl
		{
			/** The current link (can be NULL). */	 
			ingenico::service::Link* m_link;
		
			/** The interfacable used to bind callbacks when this service instance is aggregated. */
			ingenico::service::Interfacable* m_interfacable;
		
			/** The custom class instance */
			::ingenico::TMSService::TMSServiceImplCustom* m_custom_impl;
		};
	}
}

/** Constructor of the TMSServiceImpl implementation. */
TMSServiceImpl::TMSServiceImpl()
{
	this->m_impl = new TMSServiceImplPImpl();
	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = NULL;
	
	// Create a new instance of the custom class.
	this->m_impl->m_custom_impl = new ::ingenico::TMSService::TMSServiceImplCustom();

	// Bind the internal callback for the method setParam of the service ingenico.TMSService.ITMSService.
	this->bind(SetParamRequest::messageType, this, &TMSServiceImpl::internalSetParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getParam of the service ingenico.TMSService.ITMSService.
	this->bind(GetParamRequest::messageType, this, &TMSServiceImpl::internalGetParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getDefaultParam of the service ingenico.TMSService.ITMSService.
	this->bind(GetDefaultParamRequest::messageType, this, &TMSServiceImpl::internalGetDefaultParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method download of the service ingenico.TMSService.ITMSService.
	this->bind(DownloadRequest::messageType, this, &TMSServiceImpl::internalDownload, ingenico::service::Permissions::VERTICAL);

	// Call custom initialization code.
	this->m_impl->m_custom_impl->initialize();
}

/** Constructor of the TMSServiceImpl implementation. This constructor allows to 
 * bind several service implementation to one interfacable declared in the service registry.
 * @param interfacable The interfacable to bind */
TMSServiceImpl::TMSServiceImpl(ingenico::service::Interfacable* interfacable)
{
	this->m_impl = new TMSServiceImplPImpl();
	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = interfacable;

	// Create a new instance of the custom class.
	this->m_impl->m_custom_impl = new ::ingenico::TMSService::TMSServiceImplCustom();

	// Bind the internal callback for the method setParam of the service ingenico.TMSService.ITMSService.
	this->m_impl->m_interfacable->bind(SetParamRequest::messageType, this, &TMSServiceImpl::internalSetParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getParam of the service ingenico.TMSService.ITMSService.
	this->m_impl->m_interfacable->bind(GetParamRequest::messageType, this, &TMSServiceImpl::internalGetParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method getDefaultParam of the service ingenico.TMSService.ITMSService.
	this->m_impl->m_interfacable->bind(GetDefaultParamRequest::messageType, this, &TMSServiceImpl::internalGetDefaultParam, ingenico::service::Permissions::VERTICAL);
	// Bind the internal callback for the method download of the service ingenico.TMSService.ITMSService.
	this->m_impl->m_interfacable->bind(DownloadRequest::messageType, this, &TMSServiceImpl::internalDownload, ingenico::service::Permissions::VERTICAL);

	// Call custom initialization code.
	this->m_impl->m_custom_impl->initialize();
}

/** Forbidden copy constructor of the TMSServiceImpl implementation. */
TMSServiceImpl::TMSServiceImpl(const TMSServiceImpl& ref)
{
	this->m_impl = new TMSServiceImplPImpl();
}

/** Forbidden assignment operator of the TMSServiceImpl implementation. */
TMSServiceImpl& TMSServiceImpl::operator= (const TMSServiceImpl& other)
{
	return *this;
}

/** Destructor of the TMSServiceImpl implementation. */
TMSServiceImpl::~TMSServiceImpl()
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
	// Unbind the internal callback for the method setParam of the service ingenico.TMSService.ITMSService.
	toUnbind->unbind(SetParamRequest::messageType, this, &TMSServiceImpl::internalSetParam);
	// Unbind the internal callback for the method getParam of the service ingenico.TMSService.ITMSService.
	toUnbind->unbind(GetParamRequest::messageType, this, &TMSServiceImpl::internalGetParam);
	// Unbind the internal callback for the method getDefaultParam of the service ingenico.TMSService.ITMSService.
	toUnbind->unbind(GetDefaultParamRequest::messageType, this, &TMSServiceImpl::internalGetDefaultParam);
	// Unbind the internal callback for the method download of the service ingenico.TMSService.ITMSService.
	toUnbind->unbind(DownloadRequest::messageType, this, &TMSServiceImpl::internalDownload);

	this->m_impl->m_link = NULL;
	this->m_impl->m_interfacable = NULL;
	delete this->m_impl;
	this->m_impl = NULL;
}

/** Gets the custom class instance.
@return the custom class instance */
::ingenico::TMSService::TMSServiceImplCustom& TMSServiceImpl::getCustomImpl() const
{
	return *this->m_impl->m_custom_impl;
}

/** Internal callback for the method setParam of the service ingenico.TMSService.ITMSService. */
enum ingenico::os::Error TMSServiceImpl::internalSetParam(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	SetParamRequest::Instance request = SetParamRequest::instantiate();
	SetParamResponse::Instance response = SetParamResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		const std::string* inTmsaddress;
		const std::string* inSslprofile;
		const google::protobuf::uint32* inTcpport;
		const std::string* inNetworktype;
		const std::string* inPhonenumber;
		const std::string* inGprsapn;
		const std::string* inPpplogin;
		const std::string* inPpppassword;
		const std::string* inContractnumber;
		std::string outSetparam;
		
		
		// Extract the input parameters from the request.
		std::string tmsaddressTmp; 
		if (request->has_tmsaddress())
		{
			tmsaddressTmp = request->tmsaddress();
			inTmsaddress = &tmsaddressTmp;
		}
		else
		{
			inTmsaddress = NULL;
		}
		
		
		std::string sslprofileTmp; 
		if (request->has_sslprofile())
		{
			sslprofileTmp = request->sslprofile();
			inSslprofile = &sslprofileTmp;
		}
		else
		{
			inSslprofile = NULL;
		}
		
		
		google::protobuf::uint32 tcpportTmp; 
		if (request->has_tcpport())
		{
			tcpportTmp = request->tcpport();
			inTcpport = &tcpportTmp;
		}
		else
		{
			inTcpport = NULL;
		}
		
		
		std::string networktypeTmp; 
		if (request->has_networktype())
		{
			networktypeTmp = request->networktype();
			inNetworktype = &networktypeTmp;
		}
		else
		{
			inNetworktype = NULL;
		}
		
		
		std::string phonenumberTmp; 
		if (request->has_phonenumber())
		{
			phonenumberTmp = request->phonenumber();
			inPhonenumber = &phonenumberTmp;
		}
		else
		{
			inPhonenumber = NULL;
		}
		
		
		std::string gprsapnTmp; 
		if (request->has_gprsapn())
		{
			gprsapnTmp = request->gprsapn();
			inGprsapn = &gprsapnTmp;
		}
		else
		{
			inGprsapn = NULL;
		}
		
		
		std::string ppploginTmp; 
		if (request->has_ppplogin())
		{
			ppploginTmp = request->ppplogin();
			inPpplogin = &ppploginTmp;
		}
		else
		{
			inPpplogin = NULL;
		}
		
		
		std::string ppppasswordTmp; 
		if (request->has_ppppassword())
		{
			ppppasswordTmp = request->ppppassword();
			inPpppassword = &ppppasswordTmp;
		}
		else
		{
			inPpppassword = NULL;
		}
		
		
		std::string contractnumberTmp; 
		if (request->has_contractnumber())
		{
			contractnumberTmp = request->contractnumber();
			inContractnumber = &contractnumberTmp;
		}
		else
		{
			inContractnumber = NULL;
		}

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->setParam(inTmsaddress, inSslprofile, inTcpport, inNetworktype, inPhonenumber, inGprsapn, inPpplogin, inPpppassword, inContractnumber, outSetparam);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_setparam(outSetparam);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method getParam of the service ingenico.TMSService.ITMSService. */
enum ingenico::os::Error TMSServiceImpl::internalGetParam(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	GetParamRequest::Instance request = GetParamRequest::instantiate();
	GetParamResponse::Instance response = GetParamResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		std::string outTmsaddress;
		std::string outSslprofile;
		google::protobuf::uint32 outTcpport;
		std::string outNetworktype;
		std::string outPhonenumber;
		std::string outGprsapn;
		std::string outPpplogin;
		std::string outPpppassword;
		std::string outContractnumber;
		
		
		// Extract the input parameters from the request.
		

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->getParam(outTmsaddress, outSslprofile, outTcpport, outNetworktype, outPhonenumber, outGprsapn, outPpplogin, outPpppassword, outContractnumber);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_tmsaddress(outTmsaddress);
			response->set_sslprofile(outSslprofile);
			response->set_tcpport(outTcpport);
			response->set_networktype(outNetworktype);
			response->set_phonenumber(outPhonenumber);
			response->set_gprsapn(outGprsapn);
			response->set_ppplogin(outPpplogin);
			response->set_ppppassword(outPpppassword);
			response->set_contractnumber(outContractnumber);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method getDefaultParam of the service ingenico.TMSService.ITMSService. */
enum ingenico::os::Error TMSServiceImpl::internalGetDefaultParam(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	GetDefaultParamRequest::Instance request = GetDefaultParamRequest::instantiate();
	GetDefaultParamResponse::Instance response = GetDefaultParamResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		std::string outTmsaddress;
		std::string outSslprofile;
		google::protobuf::uint32 outTcpport;
		std::string outNetworktype;
		std::string outPhonenumber;
		std::string outGprsapn;
		std::string outPpplogin;
		std::string outPpppassword;
		std::string outContractnumber;
		
		
		// Extract the input parameters from the request.
		

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->getDefaultParam(outTmsaddress, outSslprofile, outTcpport, outNetworktype, outPhonenumber, outGprsapn, outPpplogin, outPpppassword, outContractnumber);
		this->m_impl->m_link = NULL;

		if (result == ingenico::os::SUCCESS)
		{
			// Put the output parameters in the response.
			response->set_tmsaddress(outTmsaddress);
			response->set_sslprofile(outSslprofile);
			response->set_tcpport(outTcpport);
			response->set_networktype(outNetworktype);
			response->set_phonenumber(outPhonenumber);
			response->set_gprsapn(outGprsapn);
			response->set_ppplogin(outPpplogin);
			response->set_ppppassword(outPpppassword);
			response->set_contractnumber(outContractnumber);
	
			// Send the response.
			result = link.send(*response);
		}
	}

	return result;
}

/** Internal callback for the method download of the service ingenico.TMSService.ITMSService. */
enum ingenico::os::Error TMSServiceImpl::internalDownload(ingenico::service::Link& link)
{
	ingenico::os::Error result = ingenico::os::SUCCESS;

	// Create message objects.
	DownloadRequest::Instance request = DownloadRequest::instantiate();
	DownloadResponse::Instance response = DownloadResponse::instantiate();

	result = link.decode(*request);
	if (result == ingenico::os::SUCCESS)
	{
		// Create temporary variables for the input and output parameters.
		
		
		// Extract the input parameters from the request.
		

		// Pre allocate output parameter if needed.

		// Invoke the user defined method.
		this->m_impl->m_link = &link;
		result = this->download();
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


/** Gets the link handle
@return the link handle */
ingenico::service::Link* TMSServiceImpl::getLink()
{
	return this->m_impl->m_link;
}

