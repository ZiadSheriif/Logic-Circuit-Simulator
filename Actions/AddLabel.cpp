#include "AddLabel.h"
#include "..\ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Add Label: Select the gate you want to add label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLabel::Execute()
{
	
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int index = pManager->InsideArea(Cx, Cy);
	if (index != -1)
	{
		pOut->PrintMsg("Enter The Label");
		string name = pIn->GetSrting(pOut);
		pManager->SetLabel(index, name);
	}
	else if (index = -1)
	{
		index = pManager->InsideAreaForCon(Cx, Cy);
		if (index != -1)
		{
			pOut->PrintMsg("Enter The Label");
			string name = pIn->GetSrting(pOut);
			pManager->SetLabel(index, name);
		}

	}
}

void AddLabel::Undo()
{
	pManager->SetLabel(pManager->GetCompCount() - 1, " ");
}

void AddLabel::Redo()
{}
