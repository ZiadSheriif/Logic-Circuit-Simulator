#include "AND2.h"
#include"..\\ApplicationManager.h"


AND2::AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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



void AND2::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, getSelect());
}

void AND2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	/*AND2 Createdobject(gfnxinfo, AND2_FANOUT);*/
	AND2* compand2 = new AND2(gfnxinfo, AND2_FANOUT);
	ptr->AddComponent(compand2);

}


//returns status of outputpin
int AND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void AND2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND2::Save(ofstream& print)
{
	print << "AND2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}
InputPin* AND2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* AND2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}

void AND2::Move(GraphicsInfo& gfxinfo)
{


}
