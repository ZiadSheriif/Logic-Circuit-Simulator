#pragma once
#include"OutputPin.h"
#include"Component.h"
class SWITCH :public Component
{
private:
	bool on_off;
protected:

	OutputPin* Outputpin;
public:
	SWITCH(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the SWITCH
	virtual void Draw(Output* pOut);
	void Paste(GraphicsInfo& gfnxinfo, ApplicationManager* ptr);
	virtual int GetOutPinStatus();	//returns status of outputpin if SWITCH, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void DrawLabel(Output* pOut);
	virtual void ChangeSwitch();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& print);
	virtual InputPin* GetInputPin();
	virtual OutputPin* GetOutputPin();
	virtual void setOutputPinStatus(STATUS s);
};

