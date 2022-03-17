#include "Connection.h"
#include"..\ApplicationManager.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	

{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	ID = counter;
	counter++;
}
void Connection::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

void Connection::Paste(GraphicsInfo & gfnxinfo, ApplicationManager * ptr)
{
	Connection* connect = new Connection(gfnxinfo, SrcPin, DstPin);
	ptr->AddComponent(connect);
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo,true);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}



void Connection::Save(ofstream& print)
{
	//print << "connection" << endl;
	print<< SrcPin->getID() << "\t"<< DstPin->getID() << "\t" << DstPin->getOrder() << endl;
}

InputPin* Connection::GetInputPin()
{
	return NULL;

}
OutputPin* Connection::GetOutputPin()
{
	return NULL;

}

Connection::~Connection()
{
	DstPin->UnselectInputpin();
}
