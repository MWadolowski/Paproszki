#pragma once
#include "constans.h"
#include<SFML\Network.hpp>
using namespace sf;
class ConnectionWizard
{
public:
	ConnectionWizard();
	ConnectionWizard(IpAddress adress, String nick);
	~ConnectionWizard();
	void initialise();

private:
	String _nick;
	UdpSocket _initializer;
	unsigned short _newPort;
	IpAddress _adress;
	//UdpSocket _dataExchanger;
};

