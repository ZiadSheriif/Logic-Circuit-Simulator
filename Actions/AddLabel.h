#pragma once
#include"Action.h"
class AddLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	
	
public:
	AddLabel(ApplicationManager* pApp);
	virtual ~AddLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

