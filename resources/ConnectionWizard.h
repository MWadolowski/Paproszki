#pragma once
#include "constans.h"
#include<SFML\Network.hpp>
using namespace sf;
class ConnectionWizard
{
public:
	ConnectionWizard();
	ConnectionWizard(IpAddress adress);
	~ConnectionWizard();

private:
	UdpSocket _initializer;
	unsigned short _newPort;
	IpAddress _adress;
	UdpSocket _dataExchanger;
};

