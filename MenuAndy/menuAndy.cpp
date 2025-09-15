#include "menuAndy.h"
#include "ArduinoEmulated.h"
#include <iostream>
#include"StringAndy.h"


Item::Item() {
	father = NULL;

}

Item::Item(int Type, char* name) {

	strcpy_Andy(itemName, name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;

}

Item::Item(const int Type, const char* name) {

	strcpy_Andy(itemName, (char*)name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;

}

Item::Item(int Type, char* name, int Min, int Max) {
	strcpy_Andy(itemName, (char*)name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;
	min = Min;
	max = Max;

}
Item::Item(const int Type, const char* name, const int Min, const int Max) {
	strcpy_Andy(itemName, (char*)name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;
	min = Min;
	max = Max;

}



Item::Item(int Type, char* name, time_tAndy timeA) {
	strcpy_Andy(itemName, (char*)name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;
	
	time = timeA;
}
Item::Item(const int Type, const char* name, const time_tAndy timeA) {
	strcpy_Andy(itemName, (char*)name);
	itemType = Type;
	subItemsN = 0;
	optionsN = 0;
	Pos = 0;
	value = 0;
	father = NULL;

	time = timeA;
}




Item::~Item() {
}

void Item::allocateItems(int N, class Item items[]) {
	int i;

	if (itemType == MENU) {

		subItems = items;
		subItemsN = N;
		Pos = 0;
		for (i = 0; i < N; i++) {
			subItems[i].father = this;


		}
	}
}



void Item::allocateOptions(int N, char** nombres) {

	options = nombres;
	optionsN = N;
	Pos = 0;



}



fourButtonsAndy::fourButtonsAndy() {
	timeValue.allocateItems(3, tTime);
	currentItem = NULL;
	waitTimer = 1000;
}

void fourButtonsAndy::Init(Item* Menu, unsigned int timer) {
	currentItem = Menu;
	waitTimer = timer;

}
void fourButtonsAndy::setButtons(int menu, int exit, int up, int down) {


	unsigned int clock;

	buttonMenu->Pin = menu;
	buttonExit->Pin = exit;
	buttonUp->Pin = up;
	buttonDown->Pin = down;

	buttonMenu->Status = LOW;
	buttonExit->Status = LOW;
	buttonUp->Status = LOW;
	buttonDown->Status = LOW;

	clock = millis();

	buttonMenu->Clock = clock;
	buttonExit->Clock = clock;
	buttonUp->Clock = clock;
	buttonDown->Clock = clock;




	//pinMode(buttonMenu,INPUT);
	//pinMode(buttonExit,INPUT);
	//pinMode(buttonUp,INPUT);
	//pinMode(buttonDown,INPUT);


}

void fourButtonsAndy::pressed() {

	option = 0;

	//MENU
	if (checkState(this, buttonMenu->Pin, HIGH)) {
		if (buttonMenu->Status == LOW) {

			buttonMenu->Status = HIGH;
			buttonMenu->Clock = millis() + waitTimer;

			//std::cout << "M.H_";




		}

	}
	else {
		if (buttonMenu->Status == HIGH) {


			if (checkState(this, buttonMenu->Pin, LOW) || millis() > buttonMenu->Clock)
			{
				buttonMenu->Status = LOW;

				//std::cout << "M.L_";

				handleButtonMenu();

			}

		}
	}


	//EXIT
	if (checkState(this, buttonExit->Pin, HIGH)) {
		if (buttonExit->Status == LOW) {

			buttonExit->Status = HIGH;
			buttonExit->Clock = millis() + waitTimer;

			//std::cout << "E.H_";


		}

	}
	else {
		if (buttonExit->Status == HIGH) {


			if (checkState(this, buttonExit->Pin, LOW) || millis() > buttonExit->Clock)
			{
				buttonExit->Status = LOW;

				//std::cout << "E.L_";

				handleButtonExit();



			}

		}
	}

	//UP
	if (checkState(this, buttonUp->Pin, HIGH)) {
		if (buttonUp->Status == LOW) {

			buttonUp->Status = HIGH;
			buttonUp->Clock = millis() + waitTimer;

			//std::cout << "U.H_";


		}

	}
	else {
		if (buttonUp->Status == HIGH) {


			if (checkState(this, buttonUp->Pin, LOW) || millis() > buttonUp->Clock)
			{
				buttonUp->Status = LOW;


				//std::cout << "U.L_";

				handleButtonUp();

			}

		}

	}

	//DOWN
	if (checkState(this, buttonDown->Pin, HIGH)) {
		if (buttonDown->Status == LOW) {

			buttonDown->Status = HIGH;
			buttonDown->Clock = millis() + waitTimer;


			//std::cout << "D.H_";

		}

	}
	else {

		if (buttonDown->Status == HIGH) {


			if (checkState(this, buttonDown->Pin, LOW) || millis() > buttonDown->Clock)
			{
				buttonDown->Status = LOW;

				//std::cout << "D.L_";

				handleButtonDown();

			}

		}
	}

	//std::cout << "|";
}






//MENU
void fourButtonsAndy::handleButtonMenu() {
	error = 0;
	option = 1;


	//VALUE
	switch (currentItem->itemType)
	{
	case TIME_CHANGE:
	case VALUE:

		if (currentItem->father != NULL) {

			currentItem->value = value;
			currentItem = currentItem->father;



		}

		break;

		//OPTION
	case OPTION:
		if (currentItem->father != NULL) {

			currentItem->Pos = pos;

			currentItem = currentItem->father;
			pos = currentItem->Pos;


		}
		break;
		//MENU
	case MENU:
		if (currentItem->subItems != NULL) {


			currentItem->Pos = pos;


			switch (currentItem->subItems[pos].itemType) {
			case TIME_CHANGE:
			case VALUE:
				currentItem = &(currentItem->subItems[pos]);
				value = currentItem->value;
				break;
			case OPTION:
				currentItem = &(currentItem->subItems[pos]);
				pos = currentItem->Pos;
				value = 0;
				break;
			case MENU:
				currentItem = &(currentItem->subItems[pos]);
				pos = 0;
				value = 0;
				break;
			case TIME_ANDY:


				timeValue.father = &(currentItem->subItems[pos]);
				localtimeAndy(&info, &(currentItem->subItems[pos].time));



				timeValue.subItems[0].value = info.tm_hour;
				timeValue.subItems[1].value = info.tm_min;
				timeValue.subItems[2].value = info.tm_sec;
				currentItem = &timeValue;
				pos = 0;
				value = 0;
			default:
				error = 1001;

			}




		}
		break;

	default:
		error = 1000;
	}
	returned = value;
}

//EXIT
void fourButtonsAndy::handleButtonExit() {
	error = 0;
	option = 2;
	returned = 0;
	if (currentItem->father != NULL) {
		currentItem = currentItem->father;

		//TIME_ANDY
		if (currentItem->itemType == TIME_ANDY) {

			info.tm_hour = (unsigned int)timeValue.subItems[0].value;
			if (info.tm_hour < 0)info.tm_hour = 0;
			if (info.tm_hour > 23)info.tm_hour = info.tm_hour%23;

			info.tm_min = (unsigned int)timeValue.subItems[1].value;
			if (info.tm_min < 0)info.tm_min = 0;
			if (info.tm_min > 59)info.tm_min = info.tm_min % 59;
			info.tm_sec = (unsigned int)timeValue.subItems[2].value;
			if (info.tm_sec < 0)info.tm_sec = 0;
			if (info.tm_sec > 59)info.tm_sec = info.tm_sec % 59;



			currentItem->time = mktimeAndy(&info);

			currentItem = currentItem->father;
		}

		switch (currentItem->itemType) {
		case TIME_CHANGE:
		case VALUE:
			break;
		case OPTION:
			pos = currentItem->Pos;

			break;
		case MENU:
			pos = currentItem->Pos;
			break;
		default:
			error = 2001;
		}

		returned = currentItem->itemType;


	}
	else option = -2;

}

//UP
void fourButtonsAndy::handleButtonUp() {


	error = 0;
	option = 3;
	returned = 0;
	//VALUE
	switch (currentItem->itemType) {
	case TIME_CHANGE:
	case VALUE:
		value++;
		if (value > currentItem->max)value = currentItem->max;
		

		returned = value;
		break;

		//OPTION
	case OPTION:

		if (pos < currentItem->optionsN - 1) {
			pos++;
		}
		else pos = 0;
		returned = pos;
		break;

		//MENU
	case MENU:
		if (currentItem->subItems != NULL) {


			if (pos < currentItem->subItemsN - 1) {
				pos++;
			}
			else pos = 0;
			returned = pos;
		}
		break;

	default: error = 3001;
	}

}

//DOWN
void fourButtonsAndy::handleButtonDown() {

	option = 4;
	returned = 0;
	error = 0;

	//VALUE
	switch (currentItem->itemType) {
	case TIME_CHANGE:
	case VALUE:
		value--;
		if (value < currentItem->min)value = currentItem->min;
		returned = value;
		break;
		//OPTION
	case OPTION:
		if (pos > 0) {
			pos--;
		}
		else pos = currentItem->optionsN - 1;
		returned = pos;

		break;
		//MENU
	case MENU:
		if (currentItem->subItems != NULL) {


			if (pos > 0) {
				pos--;
			}
			else pos = currentItem->subItemsN - 1;
			returned = pos;
		}
		break;
	default: error = 4001;
	}



}

fourButtonsAndy Opcions;


void menuAndy() {

	int opcion=0, i=0;

	tmAndy info;
	char cadena1[16] = "";
	char cadena2[16] = "";


	Opcions.option = 20;

	while (Opcions.option != -2) {



		if (Opcions.option) {

			system("cls");
			strcpy_Andy(cadena1, "");
			strcpy_Andy(cadena2, "");

			switch (Opcions.currentItem->itemType)
			{

			case MENU:



				switch (Opcions.currentItem->subItems[Opcions.pos].itemType) {

				case OPTION:

					stradd_Andy(cadena1, Opcions.currentItem->subItems[Opcions.pos].itemName);

					stradd_Andy(cadena2, Opcions.currentItem->subItems[Opcions.pos].options[Opcions.currentItem->subItems[Opcions.pos].Pos]);
					break;
				case TIME_CHANGE:

					stradd_Andy(cadena1, "Change ");
					stradd_Andy(cadena1, Opcions.currentItem->subItems[Opcions.pos].itemName);
					stradd_Andy(cadena1, "?");

					for (i = 0; i < 3; i++) {

						stradd_Andy(cadena2, Opcions.currentItem->subItems[i].value);
						if (i < 2)stradd_Andy(cadena2, ":");

					}

					break;

				case VALUE:
					stradd_Andy(cadena1, Opcions.currentItem->subItems[Opcions.pos].itemName);


					stradd_Andy(cadena2, Opcions.currentItem->subItems[Opcions.pos].value);
					break;
				case TIME_ANDY:
					stradd_Andy(cadena1, Opcions.currentItem->subItems[Opcions.pos].itemName);
					localtimeAndy(&info, &(Opcions.currentItem->subItems[Opcions.pos].time));
					stradd_Andy(cadena2, info.tm_hour);
					stradd_Andy(cadena2, ":");
					stradd_Andy(cadena2, info.tm_min);
					stradd_Andy(cadena2, ":");
					stradd_Andy(cadena2, info.tm_sec);
					break;
				}





				break;
			case OPTION:
				stradd_Andy(cadena1, Opcions.currentItem->itemName);
				stradd_Andy(cadena2, "<");
				stradd_Andy(cadena2, Opcions.currentItem->options[Opcions.pos]);
				stradd_Andy(cadena2, ">?");
				break;
			case TIME_CHANGE:
				stradd_Andy(cadena1, "*");
				stradd_Andy(cadena1, Opcions.currentItem->itemName);

				for (i = 0; i < 3; i++) {
					if (Opcions.currentItem == &Opcions.currentItem->father->subItems[i])
					{
						stradd_Andy(cadena2, "<");
						stradd_Andy(cadena2, Opcions.value);
						stradd_Andy(cadena2, ">?");
					}
					else stradd_Andy(cadena2, Opcions.currentItem->father->subItems[i].value);
					if (i < 2)stradd_Andy(cadena2, ":");
				}

				break;

			case VALUE:
				stradd_Andy(cadena1, "*");
				stradd_Andy(cadena1, Opcions.currentItem->itemName);
				stradd_Andy(cadena2, "<");
				stradd_Andy(cadena2, Opcions.value);
				stradd_Andy(cadena2, ">?");
				break;
			default:
				break;

			}

			/// Arduino emulado...
			lcd_1.setCursor(0, 0);
			lcd_1.print(cadena1);
			lcd_1.setCursor(0, 0);
			lcd_1.print(cadena2);
			
			optionsAndy(&opcion);

		
		

		}







		//emulated button:
		if (opcion < 5 && opcion>0) {

			Opcions.buttons[opcion - 1].Value = HIGH;



			//if (Opciones.option) {
			Opcions.pressed();
			delay(100);

			Opcions.buttons[opcion - 1].Value = LOW;


			opcion = 0;


			Opcions.pressed();


			Opcions.option;


		}
		else if (opcion != 0) {
			Opcions.option = 20;
		}
		else Opcions.pressed();


		//-------







		delay(100);

	}


}
