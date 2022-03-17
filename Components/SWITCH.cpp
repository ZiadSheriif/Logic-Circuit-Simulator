#include "SWITCH.h"
#include"..\\ApplicationManager.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo)
{
	setSelect(false);
	Outputpin = new OutputPin(LOW); //allocate 1 output pin -by default LOW
	Outputpin->setComponent(this);
	//STATUS m_Status{};	//Status of the Pin
	/*SrcPin->setStatus();*/ // low or high
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	setOutputPinStatus(LOW);
	setLabel("NoName");
	ID = counter;
	counter++;
	on_off = false;

}

void SWITCH::Operate()
{


}

void SWITCH::Draw(Output* pOut)
{
	pOut->DrawSWITCH(m_GfxInfo, getSelect(), on_off);
}
void SWITCH::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	SWITCH* Switch = new SWITCH(gfnxinfo);
	ptr->AddComponent(Switch);
}
void SWITCH::ChangeSwitch()
{
	if (Outputpin->getStatus() == LOW)
	{                                         // upon pressing switch,, it returns reflected action (0>>>1) or(1>>0)
		Outputpin->setStatus(HIGH);
		on_off = true;
	}
	else
	{
		Outputpin->setStatus(LOW);
		on_off = false;
	}
}

int SWITCH::GetOutPinStatus()
{
	return Outputpin->getStatus();
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1;

}

void SWITCH::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{


}
void SWITCH::Save(ofstream& print)
{
	print << "SWITCH\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;
}
InputPin* SWITCH::GetInputPin()
{
	return NULL;

}
OutputPin* SWITCH::GetOutputPin()
{
	return Outputpin;
}

void SWITCH::setOutputPinStatus(STATUS s)
{
	Outputpin->setStatus(LOW);
}
