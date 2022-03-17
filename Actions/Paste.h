#pragma once
#include"Action.h"
#include"../Components/Component.h"
class Paste :public Action
{
private:

	int x1;
	int y1;

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	/*Component* SelectedComp(int x, int y);*/



};

