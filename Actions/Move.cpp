#include "Move.h"
#include "..\ApplicationManager.h"


Move::Move(ApplicationManager* pAppMan) :Action(pAppMan)
{

}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Move Action has been selected, select component to Move");
	pIn->GetPointClicked(X, Y);
	pOut->ClearStatusBar();
	pOut->PrintMsg("CLick on the the Place  ");
	pIn->GetPointClicked(x1, y1);
	pOut->ClearStatusBar();
}

void Move::Execute()
{
	ReadActionParameters();
	GraphicsInfo Gfxinfo;
	int indexelement = pManager->InsideArea(X, Y);
	GraphicsInfo gfxinfo;
	if (indexelement != -1)
	{

		OutputPin* outpin = pManager->connectionGetOutputPin(X, Y, gfxinfo);
		InputPin* inpin = pManager->connectionGetInputPin(X, Y, gfxinfo);
		int index;
		int InputNum = pManager->GetNumofInputs(indexelement);
		for (int i = 0;i < pManager->GetCompCount();i++)
		{
			int index = pManager->GetConnectionByoutputPin(outpin);

			if (index != -1)
			{
				pManager->removeComponent(index);

			}
		}

		if (inpin != NULL)
		{

			for (int i = 0;i < InputNum;i++)
			{
				index = pManager->GetConnectionByInputPin(&inpin[i]);
				if (index != -1 && inpin[i].IsSelected() == true)
					pManager->removeComponent(index);
			}
		}
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;

		Gfxinfo.x1 = x1 - Len / 2;
		Gfxinfo.x2 = x1 + Len / 2;
		Gfxinfo.y1 = y1 - Len / 2;
		Gfxinfo.y2 = y1 + Len / 2;
		pManager->setmovecomp(Gfxinfo, indexelement);

	}
	//int index = pManager->InsideArea(X, Y);
	//if (index != -1)
	//{
	//	int Len = UI.AND2_Width;
	//	int Wdth = UI.AND2_Height;

	//	Gfxinfo.x1 = x1 - Len / 2;
	//	Gfxinfo.x2 = x1 + Len / 2;
	//	Gfxinfo.y1 = y1 - Len / 2;
	//	Gfxinfo.y2 = y1 + Len / 2;
	//	pManager->setmovecomp(Gfxinfo, index);
	//	/*pManager->removetemporary(index);
	//	pManager->setmovecomp(index);*/
	//}






	//Gfxinfo.x1 = X - Len / 2;
	//Gfxinfo.x2 = X + Len / 2;
	//Gfxinfo.y1 = Y - Len / 2;
	//Gfxinfo.y2 = Y + Len / 2;

	//int index = pManager->InsideArea(X, Y);
	//
	//{
	//	pManager->setmovecomp(Gfxinfo);
	//	/*pManager->removetemporary(index);*/
	//
	//}
}

void Move::Undo()
{
}

void Move::Redo()
{
}

Move::~Move()
{
}
