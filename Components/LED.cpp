#include "LED.h"
#include"..\\ApplicationManager.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
{
	setSelect(false);
	//Allocate one input pin
	m_InputPins = new InputPin;
	//Associate one input pins to this lED
	m_InputPins->setComponent(this);
	setInPutCount(1);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ONorOFF = false;
	setLabel("NoName");
	ID = counter;
	counter++;
}
void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (m_InputPins->getStatus() == HIGH)
		ONorOFF = true;
	else
		ONorOFF = false;

	//Add you code here
}


// Function Draw
// Draws led AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass led drawing info to it.
	pOut->DrawLED(m_GfxInfo, getSelect(), ONorOFF);
}

void LED::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	LED* led = new LED(gfnxinfo);
	ptr->AddComponent(led);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins->getStatus();	//only one 
}

void LED::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins->setStatus(s);
}
void LED::Save(ofstream& print)
{
	print << "LED\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height / 2 << endl;

}

InputPin* LED::GetInputPin()
{
	return m_InputPins;
}
OutputPin* LED::GetOutputPin()
{
	return NULL;
}