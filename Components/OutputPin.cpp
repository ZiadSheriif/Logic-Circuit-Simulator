#include "OutputPin.h"
#include "Connection.h"
#include"Component.h"


//OutputPin::OutputPin()
//{
//}

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}
void OutputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* OutputPin::getComponent()
{
	return pComp;
}
int OutputPin::getID()
{
	return pComp->GetID();
}