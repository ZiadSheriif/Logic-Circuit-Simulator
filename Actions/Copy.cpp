#include"Copy.h"
#include "..\ApplicationManager.h"


Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy()
{
}

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Copy Action has been selected, select component to copy");
	pIn->GetPointClicked(mX, mY);
	pOut->ClearStatusBar();
}

void Copy::Execute()
{
	ReadActionParameters();
	int index = pManager->InsideArea(mX, mY);
	if (index != -1)
		pManager->setClipboard(index);


}

void Copy::Undo()
{
}

void Copy::Redo()
{
}

