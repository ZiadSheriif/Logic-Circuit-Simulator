#include"Cut.h"
#include "..\ApplicationManager.h"


Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut()
{
}

void Cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Cut Action has been selected, select component to cut");
	pIn->GetPointClicked(mX, mY);
	pOut->ClearStatusBar();
}

void Cut::Execute()
{
	ReadActionParameters();
	
	int indexelement = pManager->InsideArea(mX, mY);
	GraphicsInfo gfxinfo;
	if (indexelement != -1)
	{

		OutputPin* outpin = pManager->connectionGetOutputPin(mX, mY, gfxinfo);
		InputPin* inpin = pManager->connectionGetInputPin(mX, mY, gfxinfo);
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
		pManager->setClipboard(indexelement);
		pManager->removetemporary(indexelement);

	}
	
	
	//int index = pManager->InsideArea(mX, mY);
	//
	//
	//if (index != -1)
	//{
	//	pManager->setClipboard(index);
	//	pManager->removetemporary(index);
	//}


}

void Cut::Undo()
{
}

void Cut::Redo()
{
}


