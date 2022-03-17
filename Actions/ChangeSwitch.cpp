#include "ChangeSwitch.h"
#include"Simulate.h"
ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) :Action(pApp)
{

}

ChangeSwitch::~ChangeSwitch(void)
{
}

void ChangeSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Choose any Switch");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void ChangeSwitch::Execute()
{
	ReadActionParameters();
	int index = pManager->InsideArea(x, y);
	if (index != -1)
	{
		if (pManager->SwitchON_Off(index) == true)
		{
			pManager->Changeswitch(index);
		}
	}
	Simulate* sim = new Simulate(pManager);
	sim->Execute();
	delete sim;
	sim = NULL;
}

void ChangeSwitch::Undo()
{
}

void ChangeSwitch::Redo()
{
}
