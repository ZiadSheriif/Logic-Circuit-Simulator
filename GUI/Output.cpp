#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");
	CreateDesignToolBar();	//Create the desgin toolbar
	CreateManageToolBar();
	CreateStatusBar();		//Create Status bar
	//CreateSimulationToolBar();
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width-UI.MngToolItemWidth, UI.height - UI.StatusBarHeight);
	
}
void Output::ClearDesignToolBar() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	
}
void Output::PrintString(GraphicsInfo r_GfxInfo,string strFromGetString) const
{
	pWind->DrawString(r_GfxInfo.x1,r_GfxInfo.y1,strFromGetString);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_Buff] = "Images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_INV] = "Images\\Menu\\not.jpg";
	MenuItemImages[ITM_AND2] = "Images\\Menu\\and.jpg";
	MenuItemImages[ITM_OR2] = "Images\\Menu\\or.jpg";
	MenuItemImages[ITM_NAND2] = "Images\\Menu\\nand.jpg";
	MenuItemImages[ITM_NOR2] = "Images\\Menu\\nor.jpg";
	MenuItemImages[ITM_XOR2] = "Images\\Menu\\xor.jpg";
	MenuItemImages[ITM_XNOR2] = "Images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_AND3] = "Images\\Menu\\and3.jpg";
	MenuItemImages[ITM_NOR3] = "Images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_XOR3] = "Images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_SWITCH] = "Images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "Images\\Menu\\led.jpg";
	MenuItemImages[ITM_CONNECTION] = "Images\\Menu\\connection.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::CreateManageToolBar() const
{
	UI.AppMode = DESIGN;
	string MenuItemImages[ITM_MNG_CNT];
	MenuItemImages[ITM_ADD_Label]="Images\\Menu\\Add.jpg";
	MenuItemImages[ITM_EDIT_Label]="Images\\Menu\\edit.jpg";//
	//MenuItemImages[ITM_Create_TruthTable]="Images\\Menu\\buffer.jpg";//Should be in simulation bar
	//MenuItemImages[ITM_Change_Switch]="Images\\Menu\\switch.jpg";//Should be in simulation bar
	MenuItemImages[ITM_SELECT]="Images\\Menu\\Select.jpg";
	MenuItemImages[ITM_DEL]="Images\\Menu\\delete.jpg";//
	MenuItemImages[ITM_MOVE]="Images\\Menu\\Move.jpg";
	MenuItemImages[ITM_SAVE]="Images\\Menu\\save.jpg";//
	MenuItemImages[ITM_LOAD]="Images\\Menu\\load.jpg";//
	MenuItemImages[ITM_UNDO]="Images\\Menu\\undo.jpg";//
	MenuItemImages[ITM_REDO]="Images\\Menu\\redo.jpg";//
	MenuItemImages[ITM_DSN_MODE]="Images\\Menu\\pause.jpg";//
	MenuItemImages[ITM_SIM_MODE]="Images\\Menu\\play.jpg";//
	MenuItemImages[ITM_COPY] = "Images\\Menu\\copy.jpg";//
	MenuItemImages[ITM_CUT] = "Images\\Menu\\cut.jpg";//
	MenuItemImages[ITM_PASTE] = "Images\\Menu\\paste.jpg";
	
	//MenuItemImages[ITM_STATUS_BAR]="Images\\Menu\\buffer.jpg";

	for(int i=0; i<ITM_MNG_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],UI.width-UI.MngToolItemWidth,i*UI.MngToolItemWidth+UI.ToolBarHeight,UI.MngToolItemWidth,UI.MngToolItemWidth);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(UI.width-UI.MngToolItemWidth, UI.ToolBarHeight, UI.width-UI.MngToolItemWidth, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string SimulationItemImages[ITM_SIM_CNT];
	SimulationItemImages[ITM_VALIDATE] = "Images\\Simulation\\validate.jpg";
	SimulationItemImages[ITM_SIM] = "Images\\Simulation\\simulate.jpg";
	SimulationItemImages[ITM_TRUTH] = "Images\\Simulation\\table.jpg";

	SimulationItemImages[ITM_PROBE] = "Images\\Simulation\\probe.jpg";
	SimulationItemImages[ITM_DESIGN] = "Images\\Simulation\\design.jpg";
	SimulationItemImages[ITM_Change_Switch] = "Images\\Menu\\switch.jpg";
	SimulationItemImages[ITM_EXITS] = "Images\\Simulation\\exit.jpg";

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(SimulationItemImages[i],i*UI.ToolItemWidth,3,UI.ToolItemWidth, UI.ToolBarHeight);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//pWind->DrawRectangle(0, UI.ToolBarHeight + UI.SimulationBarHeight + 10, UI.width - UI.MngToolItemWidth, UI.height - UI.StatusBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//


void Output::DrawBuff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\buffer.jpg";
	else
		GateImage = "Images\\Gates\\buffer.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\not.jpg";
	else
		GateImage = "Images\\Gates\\not.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Menu\\and.jpg";
	else  
		GateImage = "Images\\Gates\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\or.jpg";
	else
		GateImage = "Images\\Gates\\or.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\nand.jpg";
	else
		GateImage = "Images\\Gates\\nand.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\nor.jpg";
	else
		GateImage = "Images\\Gates\\nor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\xor.jpg";
	else
		GateImage = "Images\\Gates\\xor.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\xnor.jpg";
	else
		GateImage = "Images\\Gates\\xnor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\and3.jpg";
	else
		GateImage = "Images\\Gates\\and3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\nor3.jpg";
	else
		GateImage = "Images\\Gates\\nor3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\xor3.jpg";
	else
		GateImage = "Images\\Gates\\xor3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected,bool Active ) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Menu\\switch.jpg";
	else  
		GateImage = "Images\\Gates\\switch.jpg";
	if (Active)
	{
		GateImage = "Images\\Gates\\switch_on.jpg";
	}

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected, bool Active) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\led.jpg";
	else
		GateImage = "Images\\Gates\\led.jpg";
	if (Active)
		GateImage = "Images\\Gates\\led_on.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BLACK, 2);
	//TODO: Add code to draw connection
	if ((r_GfxInfo.x1 == r_GfxInfo.x2) || (r_GfxInfo.y1 == r_GfxInfo.y2))
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	}
	else
	{
		if ((r_GfxInfo.x1 - r_GfxInfo.x2) > 1 || (r_GfxInfo.x2 - r_GfxInfo.x1) > 1)
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 1, r_GfxInfo.y1, FRAME);
			pWind->DrawLine(r_GfxInfo.x1 + 1, r_GfxInfo.y1, r_GfxInfo.x1 + 1, r_GfxInfo.y2, FRAME);
			pWind->DrawLine(r_GfxInfo.x1 + 1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);

		}
		else if ((r_GfxInfo.y1 - r_GfxInfo.y2) > 1 || (r_GfxInfo.y2 - r_GfxInfo.y1) > 1)
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1 + 1, FRAME);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1 + 1, r_GfxInfo.x2, r_GfxInfo.y1 + 1, FRAME);
			pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1 + 1, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);

		}
	}

}


Output::~Output()
{
	delete pWind;
}
