#include "AddSWITCH.h"
#include"..\ApplicationManager.h"

AddSWITCH::AddSWITCH(ApplicationManager* pApp):Action(pApp)
{
}

AddSWITCH::~AddSWITCH(void)
{
}

void AddSWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("SWITCH: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddSWITCH::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the Switch

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	SWITCH* pA = new SWITCH(GInfo);
	pManager->AddComponent(pA);
}

void AddSWITCH::Undo()
{
	pManager->removeComponent(pManager->GetCompCount() - 1);
}

void AddSWITCH::Redo()
{
}
