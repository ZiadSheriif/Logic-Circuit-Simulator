#pragma once
#include "action.h"
#include "..\Components\AND2.h"

class Load :public Action
{
private:
	Input* pIn;
	Output* pOut;
	
	string fileName;
public:
	Load(ApplicationManager* pApp);
	virtual ~Load();
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void CreateComp(string &Name, int& id, string& label, int& x, int& y);
	virtual void ReadConnection(int FstID, int SecID, int PinNum);
	virtual void Undo();
	virtual void Redo();
};

