#pragma once
#include "action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"
class AddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	//int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	//Component* SelectedComp(int x, int y, GraphicsInfo& G1);



};

