#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include"..\\Components\Component.h"
class Simulate:public Action
{
private:
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

