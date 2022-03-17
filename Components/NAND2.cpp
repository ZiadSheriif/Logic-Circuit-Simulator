#include "NAND2.h"
#include"..\ApplicationManager.h"
NAND2::NAND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
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


void NAND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	bool inputStatus[2];
	for (int i = 0;i < 2;i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			inputStatus[i] = true;
		else
			inputStatus[i] = false;
	}

	if ((inputStatus[0] && inputStatus[1]) == true)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
	//Add you code here
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo, getSelect());
}

//returns status of outputpin
int NAND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

void NAND2::DrawLabel(Output* pOut)
{
	GraphicsInfo g2;
	g2.x1 = m_GfxInfo.x1;
	g2.x2 = m_GfxInfo.x2;
	g2.y1 = m_GfxInfo.y1 - 20;
	g2.y2 = m_GfxInfo.y2 - 20;
	pOut->PrintString(g2, getLabel());
}

void NAND2::Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr)
{
	NAND2* nand2 = new NAND2(gfnxinfo, NAND_GATE_2_FANOUT);
	ptr->AddComponent(nand2);
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void NAND2::Save(ofstream& print)
{
	print << "NAND2\t" << ID << "\t" << getLabel() << "\t" << m_GfxInfo.x1 + UI.AND2_Width / 2 << "\t" << m_GfxInfo.y1 + UI.AND2_Height/2 << endl;
}

InputPin* NAND2::GetInputPin()
{
	return m_InputPins;
}
OutputPin* NAND2::GetOutputPin()
{
	OutputPin* p1 = &m_OutputPin;
	return p1;
}