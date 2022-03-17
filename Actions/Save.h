#pragma once
#include"Action.h"
#include<iostream>
#include<ostream>
#include<fstream>
class Save :public Action
{
private:
	static int FileNum;
public:
	Save(ApplicationManager* pApp);
	virtual ~Save();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

