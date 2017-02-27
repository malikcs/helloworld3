/*
 * WARNING : This file was generated. Do NOT modify it.
 */
#ifndef ingenico_dateAndTime_DateAndTimeProxy_hpp_INCLUDED
#define ingenico_dateAndTime_DateAndTimeProxy_hpp_INCLUDED

#include <ingenico/service.hpp>


/**
 * @mainpage
 * @{
 * Documentation for the service DateAndTime.
 *
 * Please refer to the documentation of the proxy class \ref ingenico.dateAndTime.DateAndTimeProxy "DateAndTimeProxy".
 * - @ref DateAndTime_TimeAndDate
 * @}
 *
 * @page "TimeAndDate"
 * @{
 * @section DateAndTime_TimeAndDate TimeAndDate
 * Service definition.
 * @}
 *
 */

namespace ingenico
{
	namespace dateAndTime
	{
		/** Base interface for method and function pointer for SetDateResponse reception */
		class __attribute__((visibility("hidden"))) ISetDateResponseBindable
		{
		public:
			
			/** Destructor */
			virtual ~ISetDateResponseBindable() {}
		
			/** Call the bound method or event. */
			virtual void raise(std::string& outDatechanged) = 0;
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			virtual bool operator==(const ISetDateResponseBindable & object) = 0;
		};
		
		/** Class used to bind a C++ method to the reception of the response of SetDateResponse. */
		template<class CLASS>
		class __attribute__((visibility("hidden"))) SetDateResponseMethodBindable : public ISetDateResponseBindable
		{
		public:
			/** Constructor.
			@param object instance of a class that contains the method to call
			@param method method to call */
			SetDateResponseMethodBindable(CLASS* object, void (CLASS::*method)(std::string& outDatechanged))
			{
				this->m_object = object;
				this->m_method = method;
			}
		
			/** Destructor */
			virtual ~SetDateResponseMethodBindable()
			{
				this->m_object = NULL;
				this->m_method = NULL;
			}
		
			/** Call the bound method */
			void raise(std::string& outDatechanged)
			{
				 (this->m_object->*m_method)(outDatechanged);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ISetDateResponseBindable & object)
			{
				const SetDateResponseMethodBindable* obj = dynamic_cast<const SetDateResponseMethodBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_object == this->m_object && obj->m_method == this->m_method)
					{
						return true;
					}
				}
				return false;
			}
		private:
			/** Pointer to the bound class */
			CLASS* m_object;
		
			/** Pointer to the bound method */
			void (CLASS::*m_method)(std::string& outDatechanged);
		};
		
		
		/** Base interface for method and function pointer for GetDateResponse reception */
		class __attribute__((visibility("hidden"))) IGetDateResponseBindable
		{
		public:
			
			/** Destructor */
			virtual ~IGetDateResponseBindable() {}
		
			/** Call the bound method or event. */
			virtual void raise(std::string& outResultofgetdate) = 0;
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			virtual bool operator==(const IGetDateResponseBindable & object) = 0;
		};
		
		/** Class used to bind a C++ method to the reception of the response of GetDateResponse. */
		template<class CLASS>
		class __attribute__((visibility("hidden"))) GetDateResponseMethodBindable : public IGetDateResponseBindable
		{
		public:
			/** Constructor.
			@param object instance of a class that contains the method to call
			@param method method to call */
			GetDateResponseMethodBindable(CLASS* object, void (CLASS::*method)(std::string& outResultofgetdate))
			{
				this->m_object = object;
				this->m_method = method;
			}
		
			/** Destructor */
			virtual ~GetDateResponseMethodBindable()
			{
				this->m_object = NULL;
				this->m_method = NULL;
			}
		
			/** Call the bound method */
			void raise(std::string& outResultofgetdate)
			{
				 (this->m_object->*m_method)(outResultofgetdate);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const IGetDateResponseBindable & object)
			{
				const GetDateResponseMethodBindable* obj = dynamic_cast<const GetDateResponseMethodBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_object == this->m_object && obj->m_method == this->m_method)
					{
						return true;
					}
				}
				return false;
			}
		private:
			/** Pointer to the bound class */
			CLASS* m_object;
		
			/** Pointer to the bound method */
			void (CLASS::*m_method)(std::string& outResultofgetdate);
		};
		
		
		/** Base interface for method and function pointer for TestResponse reception */
		class __attribute__((visibility("hidden"))) ITestResponseBindable
		{
		public:
			
			/** Destructor */
			virtual ~ITestResponseBindable() {}
		
			/** Call the bound method or event. */
			virtual void raise() = 0;
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			virtual bool operator==(const ITestResponseBindable & object) = 0;
		};
		
		/** Class used to bind a C++ method to the reception of the response of TestResponse. */
		template<class CLASS>
		class __attribute__((visibility("hidden"))) TestResponseMethodBindable : public ITestResponseBindable
		{
		public:
			/** Constructor.
			@param object instance of a class that contains the method to call
			@param method method to call */
			TestResponseMethodBindable(CLASS* object, void (CLASS::*method)())
			{
				this->m_object = object;
				this->m_method = method;
			}
		
			/** Destructor */
			virtual ~TestResponseMethodBindable()
			{
				this->m_object = NULL;
				this->m_method = NULL;
			}
		
			/** Call the bound method */
			void raise()
			{
				 (this->m_object->*m_method)();
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ITestResponseBindable & object)
			{
				const TestResponseMethodBindable* obj = dynamic_cast<const TestResponseMethodBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_object == this->m_object && obj->m_method == this->m_method)
					{
						return true;
					}
				}
				return false;
			}
		private:
			/** Pointer to the bound class */
			CLASS* m_object;
		
			/** Pointer to the bound method */
			void (CLASS::*m_method)();
		};
		
		
		/** Base interface for method and function pointer for SetTimeResponse reception */
		class __attribute__((visibility("hidden"))) ISetTimeResponseBindable
		{
		public:
			
			/** Destructor */
			virtual ~ISetTimeResponseBindable() {}
		
			/** Call the bound method or event. */
			virtual void raise(std::string& outTimechanged) = 0;
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			virtual bool operator==(const ISetTimeResponseBindable & object) = 0;
		};
		
		/** Class used to bind a C++ method to the reception of the response of SetTimeResponse. */
		template<class CLASS>
		class __attribute__((visibility("hidden"))) SetTimeResponseMethodBindable : public ISetTimeResponseBindable
		{
		public:
			/** Constructor.
			@param object instance of a class that contains the method to call
			@param method method to call */
			SetTimeResponseMethodBindable(CLASS* object, void (CLASS::*method)(std::string& outTimechanged))
			{
				this->m_object = object;
				this->m_method = method;
			}
		
			/** Destructor */
			virtual ~SetTimeResponseMethodBindable()
			{
				this->m_object = NULL;
				this->m_method = NULL;
			}
		
			/** Call the bound method */
			void raise(std::string& outTimechanged)
			{
				 (this->m_object->*m_method)(outTimechanged);
			}
		
			/** Compare if the current object is the same than this object
			@param object Instance to compare with the current instance 
			@return true if equal else returns false */
			bool operator==(const ISetTimeResponseBindable & object)
			{
				const SetTimeResponseMethodBindable* obj = dynamic_cast<const SetTimeResponseMethodBindable*>(&object);
				if (obj != NULL)
				{
					if (obj->m_object == this->m_object && obj->m_method == this->m_method)
					{
						return true;
					}
				}
				return false;
			}
		private:
			/** Pointer to the bound class */
			CLASS* m_object;
		
			/** Pointer to the bound method */
			void (CLASS::*m_method)(std::string& outTimechanged);
		};
		
		/** DateAndTimeProxy private implementation forward declaration */
		struct __attribute__((visibility("hidden"))) DateAndTimeProxyPImpl;
		
		/** DateAndTime proxy class. */
		class __attribute__((visibility("default"))) DateAndTimeProxy : public ingenico::service::Proxyable
		{
		public:
		
			/** Constructor of the DateAndTime proxy. */
			DateAndTimeProxy();
		
			/** Destructor of the DateAndTime proxy. */
			virtual ~DateAndTimeProxy();
		
			/** Gets the default service class name. 
			If you create a proxy you must always implement this method with service class.
			@return service class name */
			const std::string getServiceClass() const;
		
			/** Gets the reservation proxy.
			The returned class is used to reserve the exclusive use of a service.
			@return the reservation proxy */
			ingenico::service::ReservationProxy& getReservationProxy() const;
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inDatestring Input parameter (message to translate).
			 * @param outDatechanged The outDatechanged parameter.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error setDate(const std::string& inDatestring, std::string& outDatechanged);
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inDatestring Input parameter (message to translate).
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error sendSetDateRequest(const std::string& inDatestring);
		
			/** Register a C function to the response of SetDateResponse.
			@param function function to register */
			void registerSetDateResponse(void (*function)(std::string& outDatechanged));
			
			/** Unregister a C function from the response of SetDateResponse.
			@param function function to unregister */
			void unregisterSetDateResponse(void (*function)(std::string& outDatechanged));
			
			/** Register a C++ method to the response of SetDateResponse.
			@param object instance of a class that contains the method to register
			@param method method to register */
			template<class CLASS>
			void registerSetDateResponse(CLASS* object, void (CLASS::*method)(std::string& outDatechanged))
			{
				if (object != NULL && method != NULL)
				{
					this->internalBindSetDateResponse(new SetDateResponseMethodBindable<CLASS>(object, method));
				}
			}
			
			/** Unregister a C++ method from the response of SetDateResponse.
			@param object instance of a class that contains the method to unregister
			@param method method to unregister */
			template<class CLASS>
			void unregisterSetDateResponse(CLASS* object, void (CLASS::*method)(std::string& outDatechanged))
			{
				if (object != NULL && method != NULL)
				{
					this->internalUnbindSetDateResponse(new SetDateResponseMethodBindable<CLASS>(object, method));
				}
			}
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param outResultofgetdate Method result.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error getDate(std::string& outResultofgetdate);
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error sendGetDateRequest();
		
			/** Register a C function to the response of GetDateResponse.
			@param function function to register */
			void registerGetDateResponse(void (*function)(std::string& outResultofgetdate));
			
			/** Unregister a C function from the response of GetDateResponse.
			@param function function to unregister */
			void unregisterGetDateResponse(void (*function)(std::string& outResultofgetdate));
			
			/** Register a C++ method to the response of GetDateResponse.
			@param object instance of a class that contains the method to register
			@param method method to register */
			template<class CLASS>
			void registerGetDateResponse(CLASS* object, void (CLASS::*method)(std::string& outResultofgetdate))
			{
				if (object != NULL && method != NULL)
				{
					this->internalBindGetDateResponse(new GetDateResponseMethodBindable<CLASS>(object, method));
				}
			}
			
			/** Unregister a C++ method from the response of GetDateResponse.
			@param object instance of a class that contains the method to unregister
			@param method method to unregister */
			template<class CLASS>
			void unregisterGetDateResponse(CLASS* object, void (CLASS::*method)(std::string& outResultofgetdate))
			{
				if (object != NULL && method != NULL)
				{
					this->internalUnbindGetDateResponse(new GetDateResponseMethodBindable<CLASS>(object, method));
				}
			}
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error test();
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error sendTestRequest();
		
			/** Register a C function to the response of TestResponse.
			@param function function to register */
			void registerTestResponse(void (*function)());
			
			/** Unregister a C function from the response of TestResponse.
			@param function function to unregister */
			void unregisterTestResponse(void (*function)());
			
			/** Register a C++ method to the response of TestResponse.
			@param object instance of a class that contains the method to register
			@param method method to register */
			template<class CLASS>
			void registerTestResponse(CLASS* object, void (CLASS::*method)())
			{
				if (object != NULL && method != NULL)
				{
					this->internalBindTestResponse(new TestResponseMethodBindable<CLASS>(object, method));
				}
			}
			
			/** Unregister a C++ method from the response of TestResponse.
			@param object instance of a class that contains the method to unregister
			@param method method to unregister */
			template<class CLASS>
			void unregisterTestResponse(CLASS* object, void (CLASS::*method)())
			{
				if (object != NULL && method != NULL)
				{
					this->internalUnbindTestResponse(new TestResponseMethodBindable<CLASS>(object, method));
				}
			}
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inTimestring Input parameter (message to translate).
			 * @param outTimechanged The outTimechanged parameter.
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error setTime(const std::string& inTimestring, std::string& outTimechanged);
		
			/**
			 * Service method (@ref ingenico::service::Permissions::PAYMENT, @ref ingenico::service::Permissions::VERTICAL)
			 * @param inTimestring Input parameter (message to translate).
			 * @return error code SUCCESS, ERR_FAILED or ERR_TIME_OUT */
			ingenico::os::Error sendSetTimeRequest(const std::string& inTimestring);
		
			/** Register a C function to the response of SetTimeResponse.
			@param function function to register */
			void registerSetTimeResponse(void (*function)(std::string& outTimechanged));
			
			/** Unregister a C function from the response of SetTimeResponse.
			@param function function to unregister */
			void unregisterSetTimeResponse(void (*function)(std::string& outTimechanged));
			
			/** Register a C++ method to the response of SetTimeResponse.
			@param object instance of a class that contains the method to register
			@param method method to register */
			template<class CLASS>
			void registerSetTimeResponse(CLASS* object, void (CLASS::*method)(std::string& outTimechanged))
			{
				if (object != NULL && method != NULL)
				{
					this->internalBindSetTimeResponse(new SetTimeResponseMethodBindable<CLASS>(object, method));
				}
			}
			
			/** Unregister a C++ method from the response of SetTimeResponse.
			@param object instance of a class that contains the method to unregister
			@param method method to unregister */
			template<class CLASS>
			void unregisterSetTimeResponse(CLASS* object, void (CLASS::*method)(std::string& outTimechanged))
			{
				if (object != NULL && method != NULL)
				{
					this->internalUnbindSetTimeResponse(new SetTimeResponseMethodBindable<CLASS>(object, method));
				}
			}
		
		private:
		
			/** Private implementation pointer */
			DateAndTimeProxyPImpl* m_impl;
		
			/** Forbidden copy constructor of the DateAndTime proxy. */
			DateAndTimeProxy(const DateAndTimeProxy& ref);
			
			/** Forbidden assignment operator of the DateAndTime proxy. */
			DateAndTimeProxy& operator= (const DateAndTimeProxy& other);
		
			/** Internal callback for the reception of SetDateResponse messages. 
			@param link service link
			@return error code */
			ingenico::os::Error receiveSetDateResponse(ingenico::service::Link& link);
			
			/** Internal callback for the reception of GetDateResponse messages. 
			@param link service link
			@return error code */
			ingenico::os::Error receiveGetDateResponse(ingenico::service::Link& link);
			
			/** Internal callback for the reception of TestResponse messages. 
			@param link service link
			@return error code */
			ingenico::os::Error receiveTestResponse(ingenico::service::Link& link);
			
			/** Internal callback for the reception of SetTimeResponse messages. 
			@param link service link
			@return error code */
			ingenico::os::Error receiveSetTimeResponse(ingenico::service::Link& link);
		
			/** Internal bind method used for the reception of the message SetDateResponse.
			@param bind Container of bound callbacks. */
			void internalBindSetDateResponse(ingenico::dateAndTime::ISetDateResponseBindable* bind);
			
			/** Internal unbind method used for the reception of the message SetDateResponse.
			@param bind Container of bound callbacks. */
			void internalUnbindSetDateResponse(ingenico::dateAndTime::ISetDateResponseBindable* bind);
		
			/** Internal bind method used for the reception of the message GetDateResponse.
			@param bind Container of bound callbacks. */
			void internalBindGetDateResponse(ingenico::dateAndTime::IGetDateResponseBindable* bind);
			
			/** Internal unbind method used for the reception of the message GetDateResponse.
			@param bind Container of bound callbacks. */
			void internalUnbindGetDateResponse(ingenico::dateAndTime::IGetDateResponseBindable* bind);
		
			/** Internal bind method used for the reception of the message TestResponse.
			@param bind Container of bound callbacks. */
			void internalBindTestResponse(ingenico::dateAndTime::ITestResponseBindable* bind);
			
			/** Internal unbind method used for the reception of the message TestResponse.
			@param bind Container of bound callbacks. */
			void internalUnbindTestResponse(ingenico::dateAndTime::ITestResponseBindable* bind);
		
			/** Internal bind method used for the reception of the message SetTimeResponse.
			@param bind Container of bound callbacks. */
			void internalBindSetTimeResponse(ingenico::dateAndTime::ISetTimeResponseBindable* bind);
			
			/** Internal unbind method used for the reception of the message SetTimeResponse.
			@param bind Container of bound callbacks. */
			void internalUnbindSetTimeResponse(ingenico::dateAndTime::ISetTimeResponseBindable* bind);
		
		};
	}
}

#endif // ingenico_dateAndTime_DateAndTimeProxy_hpp_INCLUDED
