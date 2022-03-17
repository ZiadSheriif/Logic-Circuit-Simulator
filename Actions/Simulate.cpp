#include "Simulate.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp):Action(pApp)
{
}

Simulate::~Simulate()
{
	pManager->GetOutput()->ClearStatusBar();
}

void Simulate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Simulation Started");
	pOut->ClearDesignToolBar();
	pOut->CreateSimulationToolBar();
	pOut->ClearStatusBar();

}

void Simulate::Execute()
{
	ReadActionParameters();
	int count = pManager->GetCompCount();
	if(count%2==0)
		pManager->startSimulation(count+1);
	else
		pManager->startSimulation(count);

	
	pManager->GetOutput()->PrintMsg("Simulation ended");
}

void Simulate::Undo()
{
}

void Simulate::Redo()
{
}
