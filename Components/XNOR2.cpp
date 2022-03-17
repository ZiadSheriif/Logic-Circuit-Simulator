#include "XNOR2.h"
#include"..\\ApplicationManager.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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


void XNOR2::Operate()
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
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, getSelect());
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XNOR2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

void XNOR2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	XNOR2* xnor2 = new XNOR2(gfnxinfo, XNOR_GATE_2_FANOUT);
	ptr->AddComponent(xnor2);
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XNOR2::Save(ofstream& print)
{
	print << "XNOR2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

InputPin* XNOR2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* XNOR2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}