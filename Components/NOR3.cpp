#include "NOR3.h"
#include"..\\ApplicationManager.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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


void NOR3::Operate()
{
	bool inputStatus[3];
	for (int i = 0; i < 3; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			inputStatus[i] = true;
		else
			inputStatus[i] = false;
	}

	if ((inputStatus[0] || inputStatus[1] || inputStatus[2]) == false)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, getSelect());
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void NOR3::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR3::Save(ofstream& print)
{
	print << "NOR3\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

void NOR3::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	NOR3* nor3 = new NOR3(gfnxinfo, NOR_GATE_3_FANOUT);
	ptr->AddComponent(nor3);
}


InputPin* NOR3::GetInputPin()
{
	return m_InputPins;
}
OutputPin* NOR3::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}