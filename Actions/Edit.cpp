#include "Edit.h"
#include"../Actions/AddConnection.h"
#include "..\ApplicationManager.h"
Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Edit Label: Select the gate you want to Edit label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{

	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int index = pManager->InsideArea(Cx, Cy);
	if (index != -1)
	{
		pOut->PrintMsg("Enter The Label");
		string name = pIn->GetSrting(pOut);
		pManager->SetLabel(index, name);
	}
	else if (index == -1)
	{
		index = pManager->InsideAreaForCon(Cx, Cy);
		if (index != -1)
		{
			pOut->PrintMsg("Enter 1 if you want to change the label And Any thing to Edit Distination and source pin");
			string name;// = pIn->GetSrting(pOut);
			char n = pIn->GetChar(pOut);
			if (n == '1')
			{
				pOut->PrintMsg("Enter The Label");
				name = pIn->GetSrting(pOut);
				pManager->SetLabel(index, name);
			}
			else
			{
				int x1, x2, y1, y2;
				pManager->removeComponent(index);
				pOut->PrintMsg("CONNECTION: Click on the source pin");
				pIn->GetPointClicked(x1, y1);
				pOut->ClearStatusBar();
				pOut->PrintMsg("CONNECTION: Click on the dist pin");
				pIn->GetPointClicked(x2, y2);
				pOut->ClearStatusBar();
				GraphicsInfo G1, G2;
				GraphicsInfo G3;
				OutputPin* outpin;
				InputPin* inputpin;

				outpin = pManager->connectionGetOutputPin(x1, y1, G1);
				inputpin = pManager->connectionGetInputPin(x2, y2, G2);
				InputPin* EmptyPin = NULL;
				if (outpin != NULL && inputpin != NULL)
				{
					int order = 0;
					for (int i = 0; i < inputpin[0].GetNumInput(); i++)
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
							G3.y2 = (G2.y1 + G2.y2) / 2;
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
							G3.y2 = G2.y1 + (G2.y2 - G2.y1) * (3.0 / 4);
						}


						EmptyPin->setOrder(order + 1);
						Connection* pA = new Connection(G3, outpin, EmptyPin);
						pManager->AddComponent(pA);
					}

				}
			}

		}
	}
}

void Edit::Undo()
{
	pManager->SetLabel(pManager->GetCompCount() - 1, " ");
}

void Edit::Redo()
{}
