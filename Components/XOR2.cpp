#include "XOR2.h"
#include"..\\ApplicationManager.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	setInPutCount(2);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	setLabel("NoName");
	ID = counter;
	counter++;
}


void XOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	int x = 0;
	for (int i = 0; i < 2; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			x++;
	}
	if (x == 1)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, getSelect());
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XOR2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

void XOR2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	XOR2*xor = new XOR2(gfnxinfo, XOR_GATE_2_FANOUT);
	ptr->AddComponent(xor);
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR2::Save(ofstream& print)
{
	print << "XOR2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

InputPin* XOR2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* XOR2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}