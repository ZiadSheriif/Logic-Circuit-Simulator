#pragma once

#include "InputPin.h"
#include "Component.h"

class LED :public Component
{
private:
	bool ONorOFF;
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	void Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void DrawLabel(Output* pOut);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& print);
	virtual InputPin* GetInputPin();
	virtual OutputPin* GetOutputPin();
};

