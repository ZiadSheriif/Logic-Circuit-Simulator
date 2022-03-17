#pragma once
#include "action.h"

class Edit : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;

public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

