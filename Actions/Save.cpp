#include "Save.h"
#include "..\ApplicationManager.h"
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;
Save::Save(ApplicationManager* pApp) : Action(pApp)
{
	FileNum++;
}

Save::~Save()
{

}

void Save::ReadActionParameters()
{
}

void Save::Execute()
{
	string fileName = "Save" + to_string(FileNum) + ".txt";
	ofstream print(fileName);
	//for (int i = 0;i < pManager->GetCompCount();i++)
	//	pManager->getComponentList()[i]->Save(print);
	print << pManager->NoconnectionNum()<<endl;
	pManager->SaveComponent(print);
	print << "CONNECTIONS"<<endl;
	pManager->SaveConnection(print);
	pManager->GetOutput()->PrintMsg("File has been saved by name " + fileName);
	print << -1;
	print.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}
int Save::FileNum = 0;