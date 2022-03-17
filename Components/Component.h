#pragma once
class ApplicationManager;
#include<iostream>
#include<ostream>
#include<istream>
#include<fstream>
using namespace std;
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include"..\Components\Pin.h"
#include"InputPin.h"
#include "OutputPin.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	int InPutCount;
	bool select;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	
	static int counter;
	int ID;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	void setID(int i);
	int getInPutCount();
	void changeselect();
	//virtual void Paste(GraphicsInfo&,ApplicationManager*){}
	void setSelect(bool s);
	void setInPutCount(int c);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void DrawLabel(Output* pOut) = 0;
	virtual bool getSelect();
	virtual bool InsideArea(int &x, int &y);
	virtual bool InsideAreaConnection(int& x, int& y);
	virtual void setgraphicsinfo(GraphicsInfo&) ;
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void Paste(GraphicsInfo&, ApplicationManager*)=0;

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual string getLabel();
	virtual void setLabel(string name);
	virtual void Save(ofstream& print) = 0; //Make it virtual after compeleting the save functions
	virtual GraphicsInfo&  GetInfo();
	int GetID();
	bool IsmyID(int i);
	Component();	
	virtual InputPin* GetInputPin() = 0;
	virtual OutputPin* GetOutputPin()= 0;
	//Destructor must be virtual
	virtual ~Component();
};


