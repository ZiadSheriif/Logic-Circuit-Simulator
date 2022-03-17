#include "Delete.h"
#include "..\ApplicationManager.h"


Delete::Delete(ApplicationManager* pApp) :Action (pApp)
{
}

Delete::~Delete()
{
}

void Delete::ReadActionParameters()
{
	Output *pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Delete Action has been selected, select component to delete");
	pIn->GetPointClicked(xcoordinate, ycoordinate);
	pOut->ClearStatusBar();
}

void Delete::Execute()
{
	ReadActionParameters();
	int indexelement = pManager->InsideArea(xcoordinate, ycoordinate);
	GraphicsInfo gfxinfo;
	if (indexelement != -1)
	{

		OutputPin* outpin = pManager->connectionGetOutputPin(xcoordinate, ycoordinate, gfxinfo);
		InputPin* inpin = pManager->connectionGetInputPin(xcoordinate, ycoordinate, gfxinfo);
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
				if (index != -1 && inpin[i].IsSelected()==true)
					pManager->removeComponent(index);
			}
		}
		pManager->removeComponent(indexelement);

	}
	int ConnectionIndex = pManager->InsideAreaForCon(xcoordinate, ycoordinate);
	if (ConnectionIndex != -1)
	{
		pManager->removeComponent(ConnectionIndex);
	}
	//GraphicsInfo GfxInfo;
	//ReadActionParameters();
	//CompToDelete = SelectedComp(xcoordinate, ycoordinate);

	//if (CompToDelete != NULL)
	//{
	//	int Index=0;
	//	for (int i = 0;i < pManager->GetCompCount();i++)
	//	{
	//		if (pManager->getComponentList()[i] == CompToDelete)
	//		{
	//			Index = i;
	//			pManager->getComponentList()[i] = NULL;
	//			break;
	//		}
	//	}
	//	for(int i = Index;i < pManager->GetCompCount()-1;i++)
	//	{
	//		pManager->getComponentList()[i] = pManager->getComponentList()[i + 1];
	//	}
	//	pManager->decCompCount();
	//}
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}

//Component* Delete::SelectedComp(int x, int y)
//{
//	int gx1, gx2, gy1, gy2;
//	for (int i = 0; i < pManager->GetCompCount(); i++)
//	{
//		pManager->getComponentList()[i]->GetInfo(gx1, gy1, gx2, gy2);
//		if (x > gx1 && x<gx2 && y>gy1 && y < gy2)
//		{
//			return pManager->getComponentList()[i];
//		}
//
//	}
//	return NULL;
//}
