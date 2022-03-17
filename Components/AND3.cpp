#include "AND3.h"
#include"..\\ApplicationManager.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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


void AND3::Operate()
{
	bool inputStatus[3];
	for (int i = 0; i < 3; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			inputStatus[i] = true;
		else
			inputStatus[i] = false;
	}

	if ((inputStatus[0] && inputStatus[1] && inputStatus[2]) == true)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, getSelect());
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{

	return m_OutputPin.getStatus();

}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void AND3::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	AND3* and3 = new AND3(gfnxinfo, AND_GATE_3_FANOUT);
	ptr->AddComponent(and3);

}

void AND3::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND3::Save(ofstream& print)
{
	print << "AND3\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}


InputPin* AND3::GetInputPin()
{
	return m_InputPins;
}
OutputPin* AND3::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}