#pragma once
#include "action.h"
#include "..\ApplicationManager.h"
#include "..\Components\XOR3.h"
class Delete :public Action
{
private:
	Component* CompToDelete;
	int xcoordinate;
	int ycoordinate;
public:
	Delete(ApplicationManager *pApp);
	virtual ~Delete();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	/*Component* SelectedComp(int x, int y);*/

};

