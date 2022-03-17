//#ifndef _INPUTPIN_H
//#define _INPUTPIN_H
#pragma once

//#include"Component.h"
#include "Pin.h"
class Component; //Forward class declaration

class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	bool SelectedInput;
	int order;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	bool IsSelected();
	void SelectInputpin();
	void UnselectInputpin();
	int GetNumInput();
	void setOrder(int o);
	int getOrder();
	int getID();
};

//#endif