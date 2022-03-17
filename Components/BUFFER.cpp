#include "BUFFER.h"
#include"..\\ApplicationManager.h"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
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

void BUFFER::Operate()
{
	m_OutputPin.setStatus(m_InputPins->getStatus());
}

void BUFFER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo, getSelect());
}

void BUFFER::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.

}

void BUFFER::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	BUFFER* buff = new BUFFER(gfnxinfo, Buff_FANOUT);
	ptr->AddComponent(buff);
}

void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

void BUFFER::Save(ofstream& print)
{
	print << "BUFFER\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}


InputPin* BUFFER::GetInputPin()
{
	return m_InputPins;
}
OutputPin* BUFFER::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}