#ifndef _AND2_H
#define _AND2_H
#include"..\ApplicationManager.h"
/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"

class AND2 :public Gate
{
private:

public:
	AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);

	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Paste(GraphicsInfo&, ApplicationManager*);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void DrawLabel(Output* pOut);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& print);
	virtual InputPin* GetInputPin();
	virtual OutputPin* GetOutputPin();
	virtual void Move(GraphicsInfo&);
};

#endif