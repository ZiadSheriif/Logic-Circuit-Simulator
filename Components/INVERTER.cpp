#include "INVERTER.h"
#include"..\\ApplicationManager.h"

INVERTER::INVERTER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	setInPutCount(1);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	setLabel("NoName");
	ID = counter;
	counter++;
}

void INVERTER::Operate()
{
	if (m_InputPins->getStatus() == LOW) //sherif
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW); // sherif
}

void INVERTER::Draw(Output* pOut)
{
	pOut->DrawINV(m_GfxInfo, getSelect());
}

void INVERTER::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

int INVERTER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();

}

int INVERTER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void INVERTER::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	INVERTER* invert = new INVERTER(gfnxinfo, INV_FANOUT);
	ptr->AddComponent(invert);
}

void INVERTER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

void INVERTER::Save(ofstream& print)
{
	print << "INVERTER\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;

}

InputPin* INVERTER::GetInputPin()
{
	return m_InputPins;
}
OutputPin* INVERTER::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}