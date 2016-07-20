#include "ConnectionWizard.h"
//#include <string.h>

ConnectionWizard::ConnectionWizard() : ConnectionWizard("127.0.0.1", "User") { }

ConnectionWizard::ConnectionWizard(IpAddress adress, String nick)
{
	_adress = adress;
	_nick = nick;
}

ConnectionWizard::~ConnectionWizard() { }

void ConnectionWizard::initialise()
{
	Packet request;
	request << _nick;
	_initializer.send(request, _adress, START_PORT);
	_initializer.receive(request, _adress, _newPort);
}
