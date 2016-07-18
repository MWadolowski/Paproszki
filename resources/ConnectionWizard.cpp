#include "ConnectionWizard.h"

ConnectionWizard::ConnectionWizard() : ConnectionWizard("127.0.0.1") { }

ConnectionWizard::ConnectionWizard(IpAddress adress)
{
	_adress = adress;
	Packet request;
	IpAddress myAdress = IpAddress::getLocalAddress();
	IpAddress conf("192.168.56.1");
	request;
}

ConnectionWizard::~ConnectionWizard() { }
