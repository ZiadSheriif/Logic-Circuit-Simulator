#include "AddXORgate3.h"
#include "..\ApplicationManager.h"

AddXORgate3::AddXORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddXORgate3::~AddXORgate3(void)
{
}

void AddXORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input XOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR3* pA = new XOR3(GInfo, XOR_GATE_3_FANOUT);
	pManager->AddComponent(pA);
}

void AddXORgate3::Undo()
{
	pManager->removeComponent(pManager->GetCompCount() - 1);
}

void AddXORgate3::Redo()
{}

