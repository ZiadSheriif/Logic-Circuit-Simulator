#include "NOR2.h"
#include"..\\ApplicationManager.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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


void NOR2::Operate()
{
	bool inputStatus[2];
	for (int i = 0; i < 2; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			inputStatus[i] = true;
		else
			inputStatus[i] = false;
	}

	if ((inputStatus[0] || inputStatus[1]) == false)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}



// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, getSelect());
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void NOR2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::Save(ofstream& print)
{
	print << "NOR2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

void NOR2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	NOR2* nor2 = new NOR2(gfnxinfo, NOR_GATE_2_FANOUT);
	ptr->AddComponent(nor2);
}


InputPin* NOR2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* NOR2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}