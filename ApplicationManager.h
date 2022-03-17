#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* Clipboard;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Action* ActionList[MaxCompCount];
	int ActionCount;
	/*Component* movecomp;*/

public:
	ApplicationManager(); //constructor
	int GetNumofInputs(int index);
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	void EmptyActionList();
	void AddAction(Action* pAction);
	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window
	//Component* TypeOfComp(int index);
	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void undoAction();
	//Component** getComponentList();
	int GetCompCount();
	void decCompCount();
	void SaveComponent(ofstream& print);
	void SaveConnection(ofstream& print);
	int InsideArea(int x, int y);
	int InsideAreaForCon(int x, int y);
	void Select_UnSelect(int);
	bool SwitchON_Off(int);
	void Changeswitch(int);
	void setmovecomp(GraphicsInfo&,int);
	void paste(GraphicsInfo&);
	void removetemporary(int);
	void removeComponent(int index);
	GraphicsInfo getCompGraphicsInfo(int Index);
	void getCompGraphicsInfoForLoad(int ID, GraphicsInfo &G1);
	int NoconnectionNum();
	OutputPin* connectionGetOutputPin(int x, int y, GraphicsInfo& G);
	InputPin* connectionGetInputPin(int x, int y, GraphicsInfo& G);
	int GetConnectionByInputPin(InputPin* inpin);
	int GetConnectionByoutputPin(OutputPin* outpin);

	void EmptyComplist();
	void startSimulation(int count);
	void SetLabel(int index, string name);
	//destructor
	void setClipboard(int index);
	InputPin* SearchIDIN(int ID);
	OutputPin* SearchIDOUT(int ID);
	~ApplicationManager();
};

#endif