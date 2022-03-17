#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit ***IN Simulation tool bar

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application
	COPY,
	CUT,
	PASTE,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

	//ADDED for simulation tool bar Create truth table is above
	SIM_TOOL,
	VALIDATE_SIM_MODE,
	SIMULATE_SIM_MODE,
	PROBE_SIM_MODE,

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_Buff,
	ITM_INV,
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,        //NAND 2 gates
	ITM_NOR2,          // NOR 2 gates
	ITM_XOR2,
	ITM_XNOR2,
	ITM_AND3,
	ITM_NOR3,
	ITM_XOR3,
	ITM_SWITCH,
	ITM_LED,
	ITM_CONNECTION,
	ITM_EXIT, 	//AND gate item in menu

		//Exit item
	//TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};
enum Mngtoolbar
{

	ITM_ADD_Label,			//Add Label to a Component, a Connection
	ITM_EDIT_Label,			//Edit Label of a Component, a Connection

	//ITM_Create_TruthTable,	//Create Truth Table of the Circuit

	//ITM_Change_Switch,		//Change Switch Status in Simulation Mode

	ITM_SELECT,		//Select a Component, a Connection
	ITM_DEL,		//Delete a Component, a Connection
	ITM_MOVE,		//Move a Component, a Connection

	ITM_SAVE,		//Save the whole Circuit to a file
	ITM_LOAD,		//Load a Circuit from a file

	ITM_UNDO,		//Undo the last Action preformed
	ITM_REDO,		//Redo the last Action canceled

	ITM_DSN_MODE,	//Switch to Design mode
	ITM_SIM_MODE,	//Switch to Simulatiom mode
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	//ITM_STATUS_BAR,		//A click on the status bar
	ITM_MNG_CNT,
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	ITM_VALIDATE,//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item
	ITM_PROBE,
	ITM_DESIGN,
	ITM_Change_Switch,
	ITM_EXITS,
	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
		//Default fan out of 2-input AND gate
	Buff_FANOUT = 5,			//Add 1-input Buffer gate
	INV_FANOUT = 5,
	AND2_FANOUT = 5,		//Add 1-input Inverter gate
	OR_GATE_2_FANOUT = 5,		//Add 2-input OR gate
	NAND_GATE_2_FANOUT = 5,	//Add 2-input NAND gate
	NOR_GATE_2_FANOUT = 5,		//Add 2-input NOR gate
	XOR_GATE_2_FANOUT = 5,		//Add 2-input XOR gate
	XNOR_GATE_2_FANOUT = 5,	//Add 2-input XNOR gate
	AND_GATE_3_FANOUT = 5,		//Add 3-input AND gate
	NOR_GATE_3_FANOUT = 5,		//Add 3-input NOR gate
	XOR_GATE_3_FANOUT = 5,		//Add 3-input XOR gate
	Switch_FANOUT = 5,			//Add Switch
	LED_FANOUT = 5,			//Add LED

};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif