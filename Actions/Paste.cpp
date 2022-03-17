#include "Paste.h"
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{

}

Paste::~Paste()
{

}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Select the place you want to paste the Component");
	pIn->GetPointClicked(x1, y1);
	pOut->ClearStatusBar();
}

void Paste::Execute()
{
	ReadActionParameters();

	GraphicsInfo Gfxinfo;

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	Gfxinfo.x1 = x1 - Len / 2;
	Gfxinfo.x2 = x1 + Len / 2;
	Gfxinfo.y1 = y1 - Len / 2;
	Gfxinfo.y2 = y1 + Len / 2;

	pManager->paste(Gfxinfo);

}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
