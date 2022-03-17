#pragma once
#include"Action.h"
#include"..\\Components\Component.h"
class Move:public Action
{
	int X, Y,x1,y1;
	Component* ptrmv;
public:

	/* Constructor */
	Move(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();
	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Move();
};

