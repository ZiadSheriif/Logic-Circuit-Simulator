#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddLED.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include"Actions\\AddINVERTERgate.h"
#include"Actions\\AddBUFFERgate.h"
#include"Actions\\AddSWITCH.h"
#include"Actions\\AddORgate2.h"
#include"Actions\\AddNORgate2.h"
#include"Actions\\AddNORgate3.h"
#include"Actions\\Save.h"
#include"Actions\\AddConnection.h"
#include"Actions/Load.h"
#include"Actions/Delete.h"
#include"Actions/Select.h"
#include"Actions/Simulate.h"
#include"Actions/AddLabel.h"
#include"Actions/Edit.h"
#include"Actions/ChangeSwitch.h"
#include"Components/SWITCH.h"
#include"Actions/undo.h"
#include"Actions/Copy.h"
#include"Actions/Cut.h"
#include"Components/Connection.h"
#include"Actions/Paste.h"
#include"Actions/Move.h"
#include<fstream>
#include<iostream>
using namespace std;
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ActionCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;
	for (int i = 0; i < MaxCompCount; i++)
		ActionList[i] = NULL;
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}

int ApplicationManager::GetNumofInputs(int index)
{
	return CompList[index]->getInPutCount();
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::undoAction()
{
	if(ActionCount>=1)
	ActionList[--ActionCount]->Undo();
}
//Component** ApplicationManager::getComponentList()
//{
//	return CompList;
//}
int ApplicationManager::GetCompCount()
{
	return CompCount;
}
void ApplicationManager::decCompCount()
{
	CompCount--;
}

void ApplicationManager::SaveComponent(ofstream& print)
{
	for (int i = 0;i < CompCount;i++)
		if (!dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(print);
}
void ApplicationManager::SaveConnection(ofstream& print)
{
	for (int i = 0;i < CompCount;i++)
		if (dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(print);
}
int ApplicationManager::InsideArea(int x, int y)
{
	for (int i = 0;i < CompCount;i++)
	{
		
		if (CompList[i]->InsideArea(x, y))
		{
			if (dynamic_cast<Connection*>(CompList[i]))
				return -1;
			return i;
		}
	}
	return -1;
}

int ApplicationManager::InsideAreaForCon(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->InsideAreaConnection(x,y))
		{
			return i;
		}
	}
	return -1;
}

void ApplicationManager::Select_UnSelect(int index)
{
	CompList[index]->changeselect();
}

bool ApplicationManager::SwitchON_Off(int index)
{
	//SWITCH* Sptr = dynamic_cast<SWITCH*>(CompList[index]);

	if (dynamic_cast<SWITCH*>(CompList[index]) != NULL)
	{
		//Changeswitch(index);

		return true;
	}
	return  false;
}

void ApplicationManager::Changeswitch(int index)
{
	//(shape*)pc->... /// upcasting
	((SWITCH*)CompList[index])->ChangeSwitch();
}

void ApplicationManager::setmovecomp(GraphicsInfo& G,int index)
{
	CompList[index]->setgraphicsinfo(G);
}

void ApplicationManager::paste(GraphicsInfo&gfnxinfo)
{
	Clipboard->Paste(gfnxinfo,this);
}

void ApplicationManager::removeComponent(int index)
{
	delete CompList[index];
	CompList[index] = CompList[CompCount - 1];
	CompCount--;
}

void ApplicationManager::removetemporary(int index )
{
	CompList[index] = CompList[CompCount - 1];
	CompCount--;
}

GraphicsInfo ApplicationManager::getCompGraphicsInfo(int Index)
{
	return CompList[Index]->GetInfo();
}

void ApplicationManager::getCompGraphicsInfoForLoad(int I, GraphicsInfo& G1)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsmyID(I))
			G1 = CompList[i]->GetInfo();
	}
}

int ApplicationManager::NoconnectionNum()
{
	int count = 0;
	for (int i = 0;i < CompCount;i++)
		if (!dynamic_cast<Connection*>(CompList[i]))
			count++;
	return count;
}

OutputPin* ApplicationManager::connectionGetOutputPin(int x, int y, GraphicsInfo& G)
{
	for (int i = 0;i < CompCount;i++)
	{
		if (CompList[i]->InsideArea(x, y))
		{
			G = getCompGraphicsInfo(i);
			return CompList[i]->GetOutputPin();
		}
	}
	return NULL;
}

InputPin* ApplicationManager::connectionGetInputPin(int x, int y, GraphicsInfo& G)
{
	for (int i = 0;i < CompCount;i++)
	{
		if (CompList[i]->InsideArea(x, y))
		{
			G = getCompGraphicsInfo(i);
			return CompList[i]->GetInputPin();
		}
	}
	return NULL;
}
int ApplicationManager::GetConnectionByInputPin(InputPin* inpin)
{
	for (int i = 0;i < CompCount;i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]))
		{
			if (((Connection*)CompList[i])->getDestPin() == inpin)
			{
				return i;
			}
		}
	}
	return -1;
}
int ApplicationManager::GetConnectionByoutputPin(OutputPin* outpin)
{
	for (int i = 0;i < CompCount;i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]))
			if (((Connection*)CompList[i])->getSourcePin() == outpin)
				return i;
	}
	return -1;
}
void ApplicationManager::setClipboard(int index)
{
	Clipboard = CompList[index];
}
void ApplicationManager::EmptyComplist()
{
	for (int i = 0;i < CompCount;i++)
	{
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
	EmptyActionList();
}

void ApplicationManager::startSimulation(int count)
{
	for (int i = 0;i < count;i++) //to make sure its odd number
	{
		for (int j = 0;j < CompCount;j++)
			CompList[j]->Operate();
	}
}

void ApplicationManager::SetLabel(int index, string name)
{
	CompList[index]->setLabel(name);
}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}

void ApplicationManager::EmptyActionList()
{
	for (int i = 0;i < ActionCount;i++)
	{
		if(ActionList[i]!=NULL)
			delete ActionList[i];
		ActionList[i] = NULL;
	}
	ActionCount = 0;
}

void ApplicationManager::AddAction(Action* pAction)
{
	ActionList[ActionCount++] = pAction;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_Switch:
		pAct = new AddSWITCH(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;
	case  MOVE:
		pAct = new Move (this);
		break;
	case ADD_INV:
		pAct = new AddINVERTERgate(this);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case SIM_MODE:
		pAct = new Simulate(this);
		break;
	case ADD_Label:
		pAct = new AddLabel(this);
		break;
	case EDIT_Label:
		pAct = new Edit(this);
		break;

	/*case UNDO:
		pAct = new undo(this);
		break;*/
	case Change_Switch:
		pAct = new ChangeSwitch(this);
		break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case DSN_MODE:
		OutputInterface->ClearDesignToolBar();
		OutputInterface->CreateDesignToolBar();
		break;
	case PASTE:
		pAct = new Paste(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case EXIT:
		EmptyActionList();
		EmptyComplist();
		exit(0);
		break;
	}
	
	if(ActType != COPY && ActType != CUT && ActType != Change_Switch && ActType != SIM_MODE &&ActType!=UNDO && pAct!=NULL &&ActType!=LOAD &&ActType!=DSN_MODE)
		AddAction(pAct);

	if (pAct)
	{
		pAct->Execute();
		if (ActType == COPY && ActType == CUT && ActType == Change_Switch && ActType == SIM_MODE && ActType == UNDO && pAct != NULL && ActType == LOAD)
			delete pAct;
		//pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(OutputInterface);
		if (!(CompList[i]->getLabel() == "NoName"))
			CompList[i]->DrawLabel(OutputInterface);
	}
}



////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

InputPin* ApplicationManager::SearchIDIN(int I)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsmyID(I))
		{
			return CompList[i]->GetInputPin();
		}
	}
}

OutputPin* ApplicationManager::SearchIDOUT(int I)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsmyID(I))
		{
			return CompList[i]->GetOutputPin();
		}
	}
}

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}