#include "Select.h"
#include "..\ApplicationManager.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Select any Component");

	//Wait for User Input
	pIn->GetPointClicked(x, y);
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Select::Execute()
{
	ReadActionParameters();
	int index = pManager->InsideArea(x, y); // kda ana 5at el index bta3 el coomponnet l dost fe l digram
	if (index != -1) //de fe 7alt lw das 3la 7aga fadya fe l digram de mafrod trg3 -1
	{
		pManager->Select_UnSelect(index);// bt3tna l index bta3 l comp.3lashan ye3`yar sorto
	}
	
}

void Select::Undo()
{}

void Select::Redo()
{}

