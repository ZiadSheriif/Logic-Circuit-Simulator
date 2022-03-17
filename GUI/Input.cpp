//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	string ComponentName="";
	char NameChar;
	enum SpecialKeys{ESC=27,ENTER=13,BACKSPACE=8};
	pOut->PrintMsg("Enter the Name ");
	pWind->WaitKeyPress(NameChar);
	if (NameChar != ESC && NameChar != ENTER)
		ComponentName += NameChar;
	while(NameChar!=ESC && NameChar!=ENTER)
	{
		//ComponentName +=NameChar;
		pOut->PrintMsg("Enter the Name "+ComponentName);
		pWind->WaitKeyPress(NameChar);
		
		if(NameChar == ESC)
		{
			ComponentName = "";
			break;
		}
		else if(NameChar == ENTER)
		{
			break;
		}
		else if(NameChar==BACKSPACE && ComponentName.length() > 0)
		{
			ComponentName.pop_back();
			pOut->PrintMsg("Enter the Name "+ComponentName);
			continue;
		}
		else if(NameChar==BACKSPACE && ComponentName.length() == 0)
		{
			continue;
		}
		ComponentName+=NameChar;
	}
	pOut->PrintMsg("Entered name is "+ComponentName);
	return ComponentName;
}

char Input::GetChar(Output* pOut)
{
	char n;
	pWind->WaitKeyPress(n);
	return n;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Buff:return ADD_Buff;
			case ITM_INV:return ADD_INV;
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2:return ADD_NAND_GATE_2;
			case ITM_NOR2:return ADD_NOR_GATE_2;
			case ITM_XOR2:return ADD_XOR_GATE_2;
			case ITM_XNOR2:return ADD_XNOR_GATE_2;
			case ITM_AND3:return ADD_AND_GATE_3;
			case ITM_NOR3:return ADD_NOR_GATE_3;
			case ITM_XOR3:return ADD_XOR_GATE_3;
			case ITM_SWITCH:return ADD_Switch;
			case ITM_LED:return ADD_LED;
			case ITM_CONNECTION:return ADD_CONNECTION;
			case ITM_EXIT: return EXIT;
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if(y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x>=UI.width-UI.MngToolItemWidth)
		{
			int ClickedItemOrder = ((y-UI.ToolBarHeight) / UI.MngToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_Label:return ADD_Label;
			case ITM_EDIT_Label:return EDIT_Label;
			//case ITM_Create_TruthTable: return Create_TruthTable;
			//case ITM_Change_Switch: return Change_Switch;
			case ITM_SELECT:return SELECT;
			case ITM_DEL:return DEL;
			case ITM_MOVE:return MOVE;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_DSN_MODE:return DSN_MODE;
			case ITM_SIM_MODE:return SIM_MODE;
			case ITM_COPY:return COPY;
			case ITM_CUT:return CUT;
			case ITM_PASTE:return PASTE;
			//case ITM_STATUS_BAR:return STATUS_BAR;
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x<UI.width-UI.MngToolItemWidth)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_VALIDATE:return VALIDATE_SIM_MODE;
			case ITM_SIM:return SIMULATE_SIM_MODE;
			case ITM_TRUTH: return Create_TruthTable; //done
			case ITM_PROBE: return PROBE_SIM_MODE;
			case ITM_DESIGN:return DSN_MODE; 
			case ITM_Change_Switch:return Change_Switch;
			case ITM_EXITS:return EXIT;
			default: return SIM_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if(y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x>=UI.width-UI.MngToolItemWidth)
		{
			int ClickedItemOrder = ((y-UI.ToolBarHeight) / UI.MngToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			//case ITM_ADD_Label:return ADD_Label;
			//case ITM_EDIT_Label:return EDIT_Label;
			//case ITM_Create_TruthTable: return Create_TruthTable;
			//case ITM_Change_Switch: return Change_Switch;
			//case ITM_SELECT:return SELECT;
			//case ITM_DEL:return DEL;
			//case ITM_MOVE:return MOVE;
			//case ITM_SAVE:return SAVE;
			//case ITM_LOAD:return LOAD;
			//case ITM_UNDO:return UNDO;
			//case ITM_REDO:return REDO;
			case ITM_DSN_MODE:return DSN_MODE;
			case ITM_SIM_MODE:return SIM_MODE;
			//case ITM_COPY:return COPY;
			//case ITM_CUT:return CUT;
			//case ITM_PASTE:return PASTE;
			//case ITM_STATUS_BAR:return STATUS_BAR;
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x<UI.width-UI.MngToolItemWidth)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}

}


Input::~Input()
{
}
