/*----------------------------------------------------------------------------
 INGENICO Technical Software Department
 ------------------------------------------------------------------------------
 Copyright (c) 2015, Ingenico.
 28-32 boulevard de Grenelle 75015 Paris, France.
 All rights reserved.
 This source program is the property of INGENICO Company and may not be copied
 in any form or by any means, whether in part or in whole, except under license
 expressly granted by INGENICO company
 All copies of this program, whether in part or in whole, and
 whether modified or not, must display this and all other
 embedded copyright and ownership notices in full. */

#include <ingenico/service.hpp>
#include <DateAndtimeImpl.hpp>

using namespace ingenico::os;
using namespace ingenico::service;
using namespace ingenico::dateAndTime;

int main(void)
{
	// Fill the manifest.
	Manifest::Instance manifest = Manifest::instantiate();
	manifest->set_serviceclass("local.service.TimeAndDate");
	manifest->set_description("DateAndtimeImpl service");
	// Warning : the name of the resource file(s) must be manually updated each time the package informations of the 
	// referenced service definition project are changed !
	manifest->add_servicedescriptor("file://param/DATA0150250.TAR");

	// Register reservation messages.
	manifest->add_servicedescriptor("file://param/SRVDIRECTOR.TAR/Reservation.desc");

	// Create a new instance of the service.
	Service service(*manifest);
	DateAndtimeImpl* serviceImpl = new DateAndtimeImpl();

	// Connect to  the service directory.
	Directory directory;
	if (directory.connect() == SUCCESS)
	{
		service.addProxy(directory);
		if (directory.add(*manifest) == SUCCESS)
		{
			service.addInterface(*serviceImpl);
			while(1)
			{
				// Treat message received
				service.dispatch();
			}
		}
	}

	// Clean up.
	if (serviceImpl != NULL)
	{
		delete serviceImpl;
	}

	return 0;
}


