#include "undo.h"
#include "..\ApplicationManager.h"

undo::undo(ApplicationManager* pApp) :Action(pApp)
{
}

undo::~undo(void)
{
}

void undo::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Undo Action");
}

void undo::Execute()
{
	ReadActionParameters();
	pManager->undoAction();
	pManager->GetOutput()->ClearStatusBar();
}

void undo::Undo()
{
}

void undo::Redo()
{
}
