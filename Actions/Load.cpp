#include "Load.h"
#include "..\ApplicationManager.h"
#include"Action.h"
#include"../Components/AND2.h"
#include"../Components/AND3.h"
#include"../Components/BUFFER.h"
#include"../Components/NAND2.h"
#include"../Components/SWITCH.h"
#include"../Components/LED.h"
#include"../Components/INVERTER.h"
#include"../Components/OR2.h"
#include"../Components/XNOR2.h"
#include"../Components/XOR3.h"
#include"../Components/NOR3.h"
#include"../Components/XOR2.h"
#include"../Components/NOR2.h"
#include"../Components/Connection.h"
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;


Load::Load(ApplicationManager* pApp) : Action(pApp)
{
}

Load::~Load()
{
}

void Load::ReadActionParameters()
{
}
void Load::Execute()
{
	// string fileName; 

		//Input* pIn;
		//Output* pOut;

	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	fileName = pIn->GetSrting(pOut);
	int compcountBeforeEmpty = pManager->GetCompCount();
	for (int i = 0;i < 2;i++)
	{
		ifstream read;
		read.open(fileName);
		//pOut->PrintMsg("COmp kist empty");
		pManager->EmptyComplist();
		if (!read.is_open())
		{
			pOut->PrintMsg("File not found");
			pManager->EmptyComplist();
			pOut->ClearDrawingArea();
		}
		else
		{
			pOut->PrintMsg("File is found");
			string Name, Label;
			int CompCount, ID, xcord, ycord;
			read >> CompCount;
			for (int i = 0; i < CompCount; i++)
			{
				read >> Name >> ID >> Label >> xcord >> ycord;
				CreateComp(Name, ID, Label, xcord, ycord);
			}
			read >> Name;
			while (true)
			{
				//cout << "Done for now" << endl;
				int FirstID, SecondID, Pinnumber;
				read >> FirstID >> SecondID >> Pinnumber;
				if (FirstID == -1)
					break;

				ReadConnection(FirstID, SecondID, Pinnumber);
			}

		}
		read.close();
	}
}



void Load::CreateComp(string& Name, int& id, string& label, int& x, int& y)
{
	Component* Createdcomp;
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x - Len / 2;
	GInfo.x2 = x + Len / 2;
	GInfo.y1 = y - Wdth / 2;
	GInfo.y2 = y + Wdth / 2;
	if (Name == "AND2")
	{
		Createdcomp = new AND2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "AND3")
	{
		Createdcomp = new AND3(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "BUFFER")
	{
		Createdcomp = new BUFFER(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "INVERTER")
	{
		Createdcomp = new INVERTER(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "LED")
	{
		Createdcomp = new LED(GInfo);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NAND2")
	{
		Createdcomp = new NAND2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NOR2")
	{
		Createdcomp = new NOR2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NOR3")
	{
		Createdcomp = new NOR3(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "OR2")
	{
		Createdcomp = new OR2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "SWITCH")
	{
		Createdcomp = new SWITCH(GInfo);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XNOR2")
	{
		Createdcomp = new XNOR2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XOR2")
	{
		Createdcomp = new XOR2(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XOR3")
	{
		Createdcomp = new XOR3(GInfo, AND2_FANOUT);
		Createdcomp->setLabel(label);
		Createdcomp->setID(id);
		pManager->AddComponent(Createdcomp);
	}
	else
	{
		cout << "Gate Not found" << endl;
	}
}

void Load::ReadConnection(int FstID, int SecID, int PinNum)
{
	GraphicsInfo G1, G2, G3;
	Component* Createdcomp;
	InputPin* Inputp;
	OutputPin* Outputp;
	//cout << FstID << " " << SecID << " " << PinNum << endl;
	Inputp = pManager->SearchIDIN(SecID);
	Outputp = pManager->SearchIDOUT(FstID);
	pManager->getCompGraphicsInfoForLoad(FstID, G1);
	pManager->getCompGraphicsInfoForLoad(SecID, G2);

	if ((PinNum-1) == 0 && Inputp->GetNumInput() == 1)
	{
		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = (G2.y1 + G2.y2) / 2;
	}
	if ((PinNum - 1) == 0 && Inputp->GetNumInput() == 2)
	{
		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 3;
	}
	if ((PinNum - 1) ==1 && Inputp->GetNumInput() == 2)
	{
		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 1.5;
	}
	if ((PinNum - 1) == 0 && Inputp->GetNumInput() == 3)
	{
		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 4;
	}
	if ((PinNum - 1) == 1 && Inputp->GetNumInput() == 3)
	{
		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = G2.y1 + (G2.y2 - G2.y1) / 2;
	}
	if ((PinNum - 1) == 2 && Inputp->GetNumInput() == 3)
	{

		G3.x1 = G1.x2;
		G3.x2 = G2.x1;
		G3.y1 = (G1.y1 + G1.y2) / 2;
		G3.y2 = G2.y1 + (G2.y2 - G2.y1) * (3.0 / 4);
	}
	//cout << "DONE" << endl;
	/*if (Inputp == NULL)
		cout << "NULL input";*/
	Inputp[PinNum - 1].SelectInputpin();
	Inputp[PinNum - 1].setOrder(PinNum);
	Createdcomp = new Connection(G3, Outputp, &Inputp[PinNum-1]);
	pManager->AddComponent(Createdcomp);
}


void Load::Undo()
{
	pManager->EmptyActionList();
}

void Load::Redo()
{
}
