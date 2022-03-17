#include "XOR3.h"
#include"..\\ApplicationManager.h"

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	setInPutCount(3);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	setLabel("NoName");
	ID = counter;
	counter++;
}


void XOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here

	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			x++;
	}
	if (x == 1 || x == 3)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, getSelect());
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XOR3::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

void XOR3::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	XOR3*xor = new XOR3(gfnxinfo, XOR_GATE_3_FANOUT);
	ptr->AddComponent(xor);
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR3::Save(ofstream& print)
{
	print << "XOR3\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

InputPin* XOR3::GetInputPin()
{
	return m_InputPins;
}
OutputPin* XOR3::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}