#include "OR2.h"
#include"..\\ApplicationManager.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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


void OR2::Operate()
{
	bool inputStatus[2];
	for (int i = 0; i < 2; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			inputStatus[i] = true;
		else
			inputStatus[i] = false;
	}

	if ((inputStatus[0] || inputStatus[1]) == true)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);


	//Add you code here
}




// Function Draw
// Draws 2-input AND gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo, getSelect());
}

void OR2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void OR2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	OR2* or2 = new OR2(gfnxinfo, OR_GATE_2_FANOUT);
	ptr->AddComponent(or2);
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR2::Save(ofstream& print)
{
	print << "OR2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}

InputPin* OR2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* OR2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}