#include "AddConnection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("CONNECTION: Click on the source pin");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);
	pOut->ClearStatusBar();
	pOut->PrintMsg("CONNECTION: Click on the dist pin");
	pIn->GetPointClicked(x2, y2);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	GraphicsInfo G1, G2;
	GraphicsInfo G3;
	OutputPin* outpin;
	InputPin* inputpin;
	//Get Center point of the Gate
	ReadActionParameters();
	/*Comp1 = SelectedComp(x1, y1, G1);
	Comp2 = SelectedComp(x2, y2, G2);*/
	outpin = pManager->connectionGetOutputPin(x1,y1,G1);
	inputpin = pManager->connectionGetInputPin(x2, y2, G2);
	InputPin* EmptyPin=NULL;
	if (outpin != NULL && inputpin!= NULL)
	{
		
		
		int order = 0;
		for (int i = 0;i < inputpin[0].GetNumInput();i++)
		{
			if (!inputpin[i].IsSelected())
			{
				EmptyPin = &inputpin[i];
				EmptyPin->SelectInputpin();
				order = i;
				break;
			}
		}
		if (EmptyPin == NULL)
		{
			pManager->GetOutput()->PrintMsg("Select another gate");
		}
		else
		{
			if (order == 0 && inputpin[0].GetNumInput() == 1)
			{
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = (G2.y1 + G2.y2)/2;
			}
			if (order == 0 && inputpin[0].GetNumInput() == 2)
			{
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 3;
			}
			if (order == 1 && inputpin[0].GetNumInput() == 2)
			{
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 1.5;
			}
			if (order == 0 && inputpin[0].GetNumInput() == 3)
			{
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 4;
			}
			if (order == 1 && inputpin[0].GetNumInput() == 3)
			{
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 2;
			}
			if (order == 2 && inputpin[0].GetNumInput() == 3)
			{
				
				G3.x1 = G1.x2;
				G3.x2 = G2.x1;
				G3.y1 = (G1.y1 + G1.y2) / 2;
				G3.y2 = G2.y1 +(G2.y2 - G2.y1)*(3.0/4);
			}


			EmptyPin->setOrder(order + 1);
			Connection* pA = new Connection(G3, outpin, EmptyPin);
			pManager->AddComponent(pA);
		}
		
	}
}

void AddConnection::Undo()
{
	pManager->removeComponent(pManager->GetCompCount() - 1);
}

void AddConnection::Redo()
{}
//Component* AddConnection::SelectedComp(int x, int y, GraphicsInfo& G1)
//{
//	int gx1, gx2, gy1, gy2;
//	for (int i = 0; i < pManager->GetCompCount(); i++)
//	{
//		pManager->getComponentList()[i]->GetInfo(gx1, gy1, gx2, gy2);
//		if (x > gx1 && x<gx2 && y>gy1 && y < gy2)
//		{
//			G1.x1 = gx1;
//			G1.x2 = gx2;
//			G1.y1 = gy1;
//			G1.y2 = gy2;
//			return pManager->getComponentList()[i];
//		}
//
//	}
//	return NULL;

//}