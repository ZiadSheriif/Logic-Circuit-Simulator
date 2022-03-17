#include "AddINVERTERgate.h"
#include "..\ApplicationManager.h"
AddINVERTERgate::AddINVERTERgate(ApplicationManager* pApp):Action(pApp)
{
	
}

AddINVERTERgate::~AddINVERTERgate(void)
{
}

void AddINVERTERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Iverter Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddINVERTERgate::Execute()
{
	// Get Center point of the Gate
		ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INVERTER* pA = new INVERTER(GInfo, INV_FANOUT);
	pManager->AddComponent(pA);
}

void AddINVERTERgate::Undo()
{
	pManager->removeComponent(pManager->GetCompCount() - 1);
}

void AddINVERTERgate::Redo()
{
}
