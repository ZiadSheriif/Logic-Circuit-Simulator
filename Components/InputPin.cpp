#include "InputPin.h"
#include"Component.h"
InputPin::InputPin()
{
	SelectedInput = false;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

bool InputPin::IsSelected()
{
	return SelectedInput;
}

void InputPin::SelectInputpin()
{
	SelectedInput = true;
}

void InputPin::UnselectInputpin()
{
	SelectedInput = false;
}



int InputPin::GetNumInput()
{
	return pComp->getInPutCount();
}

void InputPin::setOrder(int o)
{
	order = o;
}

int InputPin::getOrder()
{
	return order;
}

int InputPin::getID()
{
	return pComp->GetID();
}
