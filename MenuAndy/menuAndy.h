#ifndef _MENU_ANDY

#define _MENU_ANDY

#include "time_Andy.h"
#include "menuAndy.h"
#include <iostream>



/// <summary>
/// Emulador Arduino
/// </summary>
/// 
/// 
const int HIGH = 1;
const int LOW = 0;

class fourButtonsAndy;






/// <summary>
///  Item Types:
/// </summary>
const int VALUE = 1;
const int OPTION = 2;
const int MENU = 3;
const int TIME_ANDY = 4;
const int TIME_CHANGE = 5;

class Item {


public:

	char itemName[16] = "";
	int Pos = 0;

	int itemType = VALUE;

	//VALUE TYPE
	int value = 0;
	int max =32767;
	int min =-32767;

	//TIME
	time_tAndy time = 3661;


	//MENU TYPE
	int subItemsN = 0;
	class Item* subItems = NULL;
	class Item* father = NULL;



	//OPTION TYPE
	int optionsN = 0;
	char** options = NULL;



	Item();
	Item(int Type, char*name );
	Item(const int Type, const char* name);
	Item(int Type, char* name, int Min, int Max);
	Item(const int Type, const char* name, const int Min, const int Max);
	Item(int Type, char* name,  time_tAndy timeA);
	Item(const int Type, const char* name, const time_tAndy timeA);
	~Item();
	void allocateItems(int N, class Item item[]);
	void allocateOptions(int N, char** nombres);
	





};


struct buttonAndy {

	int Pin = 0;
	int Status = LOW;
	unsigned int Clock = 0;
	int Value = LOW;



};



class fourButtonsAndy {

public:

	Item tTime[3] = { Item(TIME_CHANGE, "Hour:",0,23),Item(TIME_CHANGE, "min:",0,59),Item(TIME_CHANGE, "sec:",0,59) };
	Item timeValue = Item(MENU, "Chg Time");


	Item* currentItem = NULL;







	int value = 0;
	int pos = 0;

	tmAndy  info;

	unsigned int waitTimer;


	buttonAndy buttons[4];
	buttonAndy* buttonMenu = &(buttons[0]);
	buttonAndy* buttonExit = &(buttons[1]);
	buttonAndy* buttonUp = &(buttons[2]);
	buttonAndy* buttonDown = &(buttons[3]);

	/// <summary>
	/// Returned variables:
	/// int returned;int option;int error;
	/// </summary>
	int returned = 0, option = 0, error = 0;


	fourButtonsAndy();
	void Init(Item* Menu, unsigned int timer);
	void setButtons(int menu, int exit, int up, int down);
	void pressed();




private:



	void handleButtonMenu();
	void handleButtonExit();
	void handleButtonUp();
	void handleButtonDown();









};


extern fourButtonsAndy Opcions;

void menuAndy();






////EMULADOR DE ARDUINO:









#endif
