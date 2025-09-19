#include <LiquidCrystal.h>
#include <Servo.h>


// C++ code


//

LiquidCrystal lcd_1(2,3,4,5,6,7);


//*****************************************************
///********************
//--------------- HEADERS






//............................StringAndy.h

/*
#ifndef _STRING_ANDY
#define _STRING_ANDY




void strcpy_Andy(char* destination, char* source);
void strcpy_Andy(char* destination, const char *source);

void stradd_Andy(char* destination, char* source);
void stradd_Andy(char* destination, const char* source);

void stradd_Andy(char* destination, int source);

#endif // _STRING_ANDY
*/



void strcpy_Andy(char* destination, char* source) {
  int i = 0;
  while (source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
}
void strcpy_Andy(char* destination, const char *source) {
  int i = 0;
  while (source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
}

  void stradd_Andy(char* destination, char* source) {
  int i = 0, j = 0;
  while (destination[i] != '\0') {
    i++;
  }
  while (source[j] != '\0') {
    destination[i] = source[j];
    i++;
    j++;
  }
  destination[i] = '\0';

}
  void stradd_Andy(char* destination,const char* source) {
    int i = 0, j = 0;
    while (destination[i] != '\0') {
      i++;
    }
    while (source[j] != '\0') {
      destination[i] = source[j];
      i++;
      j++;
    }
    destination[i] = '\0';


  }


  void stradd_Andy(char* destination, int source) {
    int i = 0, j = 0, k = 0, inverter=0, negative = 0;
    int currentDigit = 0;
    char cadena[20] = "";

    while (destination[i] != '\0') {
      i++;
    }

    inverter = source;
    if (inverter == 0) {
      destination[i] = '0';
      i++;
    }
    else if (inverter < 0) {

      negative = 1;
      inverter = -inverter;
    }
    
    while ( (inverter != 0) && (k<20)) {

      currentDigit = inverter % 10;


      switch (currentDigit) {

      case 0: cadena[k] = '0';
        break;
      case 1: cadena[k] = '1';
        break;
      case 2: cadena[k] = '2';
        break;
      case 3: cadena[k] = '3';
        break;
      case 4: cadena[k] = '4';
        break;
      case 5: cadena[k] = '5';
        break;
      case 6: cadena[k] = '6';
        break;
      case 7: cadena[k] = '7';
        break;
      case 8: cadena[k] = '8';
        break;
      case 9: cadena[k] = '9';
        break;
      }

      inverter = inverter / 10;

      k++;
    }
       if(negative){
       cadena[k]='-';
       k++;
     }

    k--;
    while (k > -1) {
      destination[i] = cadena[k];
      i++;
      k--;
    
    
    
    }


    destination[i] = '\0';

  }


int checkState( int BUTTON, int STATUS) {

  int btn;

  //aclaración para windows hay que setear los botones desde el 0 hasta 3 usando "this.setButtons(0,1,2,3);" Opciones.buttons[i].Pin tiene que ser igual a "i" para que funcione en windows. 
  //btn = Botones->buttons[BUTTON].Value; //digitalRead(BUTTON);
  btn=digitalRead(BUTTON);


  if (btn == STATUS)
  {
    delay(25);
    //btn = Botones->buttons[BUTTON].Value; //digitalRead(BUTTON);
    btn=digitalRead(BUTTON);
    if (btn == STATUS)
      return(1);
  }
  return(0);
}

void clslcdANDY(){
  lcd_1.setCursor(0,0);
  lcd_1.print("                ");
  lcd_1.setCursor(0,1);
  lcd_1.print("                ");
  
}



//............................time_Andy.h

/*

#ifndef _TIME_ANDY

#define _TIME_ANDY

typedef unsigned long int time_tAndy;

struct tmAndy
{
  int tm_sec = 1;   // seconds after the minute - [0, 60] including leap second
  int tm_min = 0;   // minutes after the hour - [0, 59]
  int tm_hour = 0;  // hours since midnight - [0, 23]
  int tm_mday = 1;  // day of the month - [1, 31]
  int tm_mon = 1;   // months since January - [0, 11]
  int tm_year = 1900;  // years since 1900
  int tm_wday = 0;  // days since Sunday - [0, 6]
  int tm_yday = 0;  // days since January 1 - [0, 365]
  int tm_isdst = 0; // daylight savings time flag
};



//=============================================================================/
//Useful Constants 
#define SECS_PER_MIN  ((time_tAndy)(60UL))
#define SECS_PER_HOUR ((time_tAndy)(3600UL))
#define SECS_PER_DAY  ((time_tAndy)(SECS_PER_HOUR * 24UL))


// leap year calculator expects year argument as years offset from 1970
#define LEAP_YEAR(Y)     ( ((1970+(Y))>0) && !((1970+(Y))%4) && ( ((1970+(Y))%100) || !((1970+(Y))%400) ) )

static  const int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // API starts months from 1, this array starts from 0


time_tAndy mktimeAndy(const tmAndy*);
void localtimeAndy(tmAndy*, time_tAndy* );

#endif


*/



struct tmAndy
{
  int tm_sec = 1;   // seconds after the minute - [0, 60] including leap second
  int tm_min = 0;   // minutes after the hour - [0, 59]
  int tm_hour = 0;  // hours since midnight - [0, 23]
  int tm_mday = 1;  // day of the month - [1, 31]
  int tm_mon = 1;   // months since January - [0, 11]
  int tm_year = 1900;  // years since 1900
  int tm_wday = 0;  // days since Sunday - [0, 6]
  int tm_yday = 0;  // days since January 1 - [0, 365]
  int tm_isdst = 0; // daylight savings time flag
};



//=============================================================================/
//Useful Constants 
const unsigned long int SECS_PER_MIN =60;
const unsigned long int SECS_PER_HOUR =3600;
const unsigned long int SECS_PER_DAY=86400;


// leap year calculator expects year argument as years offset from 1970
const unsigned long int LEAP_YEAR(int Y) {
  return( ((1970+(Y))>0) && !((1970+(Y))%4) && ( ((1970+(Y))%100) || !((1970+(Y))%400) ) );
}

static  const int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // API starts months from 1, this array starts from 0


unsigned long int mktimeAndy(const struct tmAndy*);
void localtimeAndy(struct tmAndy*, unsigned long int * );


void optionsAndy(int * a){}



//............................menuAndy.h
/*

#ifndef _MENU_ANDY

#define _MENU_ANDY

//#include "time_Andy.h"
//#include "menuAndy.h"




/// <summary>
/// Emulador Arduino
/// </summary>
/// 
/// 
const int HIGH = 1;
const int LOW = 0;








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












#endif//menuAndy.h

*/












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
  unsigned long int time = 3661;


  //MENU TYPE
  int subItemsN = 0;
  class Item* subItems = NULL;
  class Item* father = NULL;



  //OPTION TYPE
  int optionsN = 0;
  char** options = NULL;



Item() {
  father = NULL;

}

Item(int Type, char* name) {

  strcpy_Andy(itemName, name);
  itemType = Type;
  subItemsN = 0;
  optionsN = 0;
  Pos = 0;
  value = 0;
  father = NULL;

}

Item(const int Type, const char* name) {

  strcpy_Andy(itemName, (char*)name);
  itemType = Type;
  subItemsN = 0;
  optionsN = 0;
  Pos = 0;
  value = 0;
  father = NULL;

}

Item(int Type, char* name, int Min, int Max) {
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
Item(const int Type, const char* name, const int Min, const int Max) {
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



Item(int Type, char* name, unsigned long int timeA) {
  strcpy_Andy(itemName, (char*)name);
  itemType = Type;
  subItemsN = 0;
  optionsN = 0;
  Pos = 0;
  value = 0;
  father = NULL;
  
  time = timeA;
}
Item(const int Type, const char* name, const unsigned long int timeA) {
  strcpy_Andy(itemName, (char*)name);
  itemType = Type;
  subItemsN = 0;
  optionsN = 0;
  Pos = 0;
  value = 0;
  father = NULL;

  time = timeA;
}




~Item() {
}

void allocateItems(int N, class Item items[]) {
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



void allocateOptions(int N, char** nombres) {

  options = nombres;
  optionsN = N;
  Pos = 0;



}





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

  struct tmAndy  info;

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






fourButtonsAndy() {
  timeValue.allocateItems(3, tTime);
  currentItem = NULL;
  waitTimer = 1000;
}

void Init(Item* Menu, unsigned int timer) {
  currentItem = Menu;
  waitTimer = timer;

}
void setButtons(int menu, int exit, int up, int down) {


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

void pressed() {

  option = 0;

  //MENU
  if (checkState( buttonMenu->Pin, HIGH)) {
    if (buttonMenu->Status == LOW) {

      buttonMenu->Status = HIGH;
      buttonMenu->Clock = millis() + waitTimer;

      //std::cout << "M.H_";




    }

  }
  else {
    if (buttonMenu->Status == HIGH) {


      if (checkState(buttonMenu->Pin, LOW) || millis() > buttonMenu->Clock)
      {
        buttonMenu->Status = LOW;

        //std::cout << "M.L_";

        handleButtonMenu();
        delay(250);

      }

    }
  }


  //EXIT
  if (checkState( buttonExit->Pin, HIGH)) {
    if (buttonExit->Status == LOW) {

      buttonExit->Status = HIGH;
      buttonExit->Clock = millis() + waitTimer;

      //std::cout << "E.H_";


    }

  }
  else {
    if (buttonExit->Status == HIGH) {


      if (checkState( buttonExit->Pin, LOW) || millis() > buttonExit->Clock)
      {
        buttonExit->Status = LOW;

        //std::cout << "E.L_";

        handleButtonExit();
        delay(250);



      }

    }
  }

  //UP
  if (checkState( buttonUp->Pin, HIGH)) {
    if (buttonUp->Status == LOW) {

      buttonUp->Status = HIGH;
      buttonUp->Clock = millis() + waitTimer;

      //std::cout << "U.H_";


    }

  }
  else {
    if (buttonUp->Status == HIGH) {


      if (checkState(buttonUp->Pin, LOW) || millis() > buttonUp->Clock)
      {
        buttonUp->Status = LOW;


        //std::cout << "U.L_";

        handleButtonUp();
        delay(250);

      }

    }

  }

  //DOWN
  if (checkState(buttonDown->Pin, HIGH)) {
    if (buttonDown->Status == LOW) {

      buttonDown->Status = HIGH;
      buttonDown->Clock = millis() + waitTimer;


      //std::cout << "D.H_";

    }

  }
  else {

    if (buttonDown->Status == HIGH) {


      if (checkState( buttonDown->Pin, LOW) || millis() > buttonDown->Clock)
      {
        buttonDown->Status = LOW;

        //std::cout << "D.L_";

        handleButtonDown();
        delay(250);

      }

    }
  }

  //std::cout << "|";
}






private:





//MENU
void handleButtonMenu() {
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
void handleButtonExit() {
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
void handleButtonUp() {


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
void handleButtonDown() {

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









};



void menuAndy();






//*******************************************************
//*********************
///------------------------------CPP





//............................ArduinoEmulated.cpp

/*
//#include "ArduinoEmulated.h"
//#include"menuAndy.h"





unsigned int millis() {

  return(clock());





}


void delay(unsigned int miliseconds) {

  unsigned int CLK = 0;
  CLK = millis() + miliseconds;
  while (millis() < CLK);

}


*/


//............................menuAndy.cpp
/*
//#include "menuAndy.h"
//#include "ArduinoEmulated.h"
//#include"StringAndy.h"

*/

fourButtonsAndy Opcions;




//............................ArduinoEmulated.h

/*
#ifndef _Arduino_EM_ANDY
#define _Arduino_EM_ANDY
#include"menuAndy.h"

int checkState(fourButtonsAndy* Botones, int BUTTON, int STATUS);
unsigned int millis();
void delay(unsigned int miliseconds);


class lcd {

public:
  int setCursor(int col, int row);

  void print(char* cadena);
  void print(const char* cadena);

};
extern lcd lcd_1;



#endif // !_Arduino_EM_ANDY
*/







void menuAndy() {

  int opcion=0, i=0;

  struct tmAndy info;
  char cadena1[16] = "";
  char cadena2[16] = "";



  Opcions.option=20;

 delay(500);
  opcion = 20;

  while (opcion != -2) {



    if (Opcions.option) {

      
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

      clslcdANDY();
      lcd_1.setCursor(0, 0);
      lcd_1.print(cadena1);
      lcd_1.setCursor(0, 1);
      lcd_1.print(cadena2);
      
      optionsAndy(&opcion);

    
    

    }



	Opcions.pressed();
	opcion=Opcions.option;



    //emulated button:
 /*   if (opcion < 5 && opcion>0) {

      Opcions.buttons[opcion - 1].Value = HIGH;



      //if (Opciones.option) {
      Opcions.pressed();
      delay(100);

      //Opcions.buttons[opcion - 1].Value = LOW;


      opcion = 0;


      Opcions.pressed();


      Opcions.option;


    }
   
    else Opcions.pressed();*/


    //-------







    delay(25);

  }

clslcdANDY();
}






//............................StringAndy.cpp

/*

//#include"StringAndy.h"

*/


//............................time_Andy.cpp




//#include"time_Andy.h"

//----



unsigned long int mktimeAndy(const struct tmAndy* TM) {
  // assemble time elements into time_t 
  // note year argument is offset from 1970 (see macros in time.h to convert to other formats)
  // previous version used full four digit year (or digits since 2000),i.e. 2009 was 2009 or 9

  int i;
  unsigned int seconds;

  // seconds from 1970 till 1 jan 00:00:00 of the given year
  seconds = TM->tm_year * (SECS_PER_DAY * 365);
  for (i = 0; i < TM->tm_year; i++) {
    if (LEAP_YEAR(i)) {
      seconds += SECS_PER_DAY;   // add extra days for leap years
    }
  }

  // add days for this year, months start from 1
  for (i = 1; i < TM->tm_mon; i++) {
    if ((i == 2) && LEAP_YEAR(TM->tm_year)) {
      seconds += SECS_PER_DAY * 29;
    }
    else {
      seconds += SECS_PER_DAY * monthDays[i - 1];  //monthDay array starts from 0
    }
  }
  seconds += (TM->tm_mday - 1) * SECS_PER_DAY;
  seconds += TM->tm_hour * SECS_PER_HOUR;
  seconds += TM->tm_min * SECS_PER_MIN;
  seconds += TM->tm_sec;
  return (unsigned long int)seconds;
}



void localtimeAndy(struct tmAndy* TM, unsigned long int* timeInput) {
  // break the given time_t into time components
  // this is a more compact version of the C library localtime function
  // note that year is offset from 1970 !!!

  int year;
  int month, monthLength;
  long int time;
  unsigned long days;

  time = (long int)(*timeInput);
  TM->tm_sec = time % 60;
  time /= 60; // now it is minutes
  TM->tm_min = time % 60;
  time /= 60; // now it is hours
  TM->tm_hour = time % 24;
  time /= 24; // now it is days
  TM->tm_wday = ((time + 4) % 7) + 1;  // Sunday is day 1 

  year = 0;
  days = 0;
  while ((unsigned)(days += (LEAP_YEAR(year) ? 366 : 365)) <= time) {
    year++;
  }
  TM->tm_year = year; // year is offset from 1970 

  days -= LEAP_YEAR(year) ? 366 : 365;
  time -= days; // now it is days in this year, starting at 0

  days = 0;
  month = 0;
  monthLength = 0;
  for (month = 0; month < 12; month++) {
    if (month == 1) { // february
      if (LEAP_YEAR(year)) {
        monthLength = 29;
      }
      else {
        monthLength = 28;
      }
    }
    else {
      monthLength = monthDays[month];
    }

    if (time >= monthLength) {
      time -= monthLength;
    }
    else {
      break;
    }
  }
  TM->tm_mon = month + 1;  // jan is month 1  
  TM->tm_mday = time + 1;     // day of month
}
















////////***************************
//***********************/



// cadenas, deben ser menores a 16 caracteres
char horaString[] = "Hora";
char alarma1String[] = "Apertura 1";
char alarma2String[] = "Cierre 1";
char alarma3String[] = "Apertura 2";
char alarma4String[] = "Cierre 2";
char activarAlarmasString[] = "Sistema";
char activadaString[] = "Activado";
char desactivadaString[] = "Desactivado";


// Menu principal
Item  Menu1[6] = {
  Item(TIME_ANDY, horaString,2000),
  Item(TIME_ANDY, alarma1String,30),
  Item(TIME_ANDY, alarma2String,60),
  Item(TIME_ANDY, alarma3String,90),
  Item(TIME_ANDY, alarma4String,120),
  Item(OPTION, activarAlarmasString) };

// Menu OPCIONES
char * activarOptions[2] = {desactivadaString,activadaString};


Item  MenuPrincipal(MENU, "Menu Principal") ;








//*****************************************************
//***********************************/
/////ARDUINO INO


struct tmAndy hora,apertura1,cierre1,apertura2,cierre2;

int a1angulo = 0;

int a2angulo = 0;

int a3angulo = 0;

int a4angulo = 0;

int opcion = 0;

int menu = 0;

int subopcion = 0;

int ImprimeHora = 0;



unsigned long int tiempoPatron=0;
unsigned long int auxiliarTime=0;

Servo servo_9;



void setup()
{
  unsigned long int start=1;
  MenuPrincipal.allocateItems(6,Menu1);

  Menu1[5].allocateOptions(2,activarOptions);

  Opcions.Init(&MenuPrincipal, 333);
  Opcions.setButtons(A3,A2,A1,A0);

  Opcions.buttonMenu->Status = LOW;
  Opcions.buttonExit->Status = LOW;
  Opcions.buttonUp->Status = LOW;
  Opcions.buttonDown->Status = LOW;

  servo_9.attach(9, 500, 2500);
  lcd_1.begin(16, 2);

  servo_9.write(0);
  lcd_1.setCursor(0, 0);
  lcd_1.print("00:00:00");
  millis();

  // Hora actual
  localtimeAndy(&hora,&start);
  localtimeAndy(&apertura1,&start);
  localtimeAndy(&apertura2,&start);
  localtimeAndy(&cierre1,&start);
  localtimeAndy(&cierre2,&start);
 // hora
  apertura1.tm_hour = 0;
  apertura1.tm_min = 0;
  apertura1.tm_sec = 1;


  // alarma 1
  apertura1.tm_hour = 0;
  apertura1.tm_min = 0;
  apertura1.tm_sec = 30;
  // alarma 2
  cierre1.tm_hour = 0;
  cierre1.tm_min = 1;
  cierre1.tm_sec = 0; 
  // alarma 3
  apertura2.tm_hour = 0;
  apertura2.tm_min = 1;
  apertura2.tm_sec = 30;
  // alarma 4
  cierre2.tm_hour = 0;
  cierre2.tm_min = 2;
  cierre2.tm_sec = 0;

  
  tiempoPatron=millis()+1000;
}

void loop()
{
 auxiliarTime=millis();
  
  if(auxiliarTime>tiempoPatron){
    tiempoPatron=tiempoPatron+1000;
    hora.tm_sec++;
  
  }
  
  
  
  // Acomodo del tiempo:
  if (hora.tm_sec >= 60) {
    hora.tm_sec = 0;
    hora.tm_min += 1;
    if (hora.tm_min >= 60) {
      hora.tm_min = 0;
      hora.tm_hour += 1;
      if (hora.tm_hour >= 24) {
        hora.tm_hour = 0;
      }
      lcd_1.setCursor(0, 0);
      if (hora.tm_hour < 10) {
        lcd_1.print("0");
        lcd_1.print(hora.tm_hour);
      } else {
        lcd_1.print(hora.tm_hour);
      }
    }
    lcd_1.setCursor(3, 0);
    if (hora.tm_min < 10) {
      lcd_1.print("0");
      lcd_1.print(hora.tm_min);
    } else {
      lcd_1.print(hora.tm_min);
    }
  }
  lcd_1.setCursor(6, 0);
  if (hora.tm_sec < 10) {
    lcd_1.print("0");
    lcd_1.print(hora.tm_sec);
  } else {
    lcd_1.print(hora.tm_sec);
  }
  
  
  ///APERTURA;
  


if(MenuPrincipal.subItems[5].Pos==1)
{
  // alarma 1: apertura
  if (apertura1.tm_hour == hora.tm_hour && (apertura1.tm_min == hora.tm_min  && apertura1.tm_sec < hora.tm_sec)) {
    servo_9.write(90);
  }
  if (cierre1.tm_hour == hora.tm_hour && (cierre1.tm_min == hora.tm_min  && cierre1.tm_sec < hora.tm_sec)){
  // alarma 2: cierre
    servo_9.write(0);
  }
  // alarma 3: apertura
  if (apertura2.tm_hour == hora.tm_hour && (apertura2.tm_min == hora.tm_min  && apertura2.tm_sec < hora.tm_sec)) {
    servo_9.write(90);
  }
  // alarma 4: cierre
  if (cierre2.tm_hour == hora.tm_hour && (cierre2.tm_min == hora.tm_min  && cierre2.tm_sec < hora.tm_sec)) {
    servo_9.write(0);
  }
}

  
  
  ///ENTRADA AL MENU
 if(checkState(Opcions.buttonMenu->Pin,HIGH)) 
{

   MenuPrincipal.subItems[0].time=mktimeAndy(&hora);
   
   menuAndy();   
   //asignacion de variables.
   
   
   
   
   
   //---------------------------
   
   
  localtimeAndy(&hora,&(MenuPrincipal.subItems[0].time)); 
  localtimeAndy(&apertura1,&(MenuPrincipal.subItems[1].time)); 
  localtimeAndy(&cierre1, &(MenuPrincipal.subItems[2].time)); 
  localtimeAndy(&apertura2,&(MenuPrincipal.subItems[3].time)); 
  localtimeAndy(&cierre2, &(MenuPrincipal.subItems[4].time)); 

   
   //Reconstruir pantalla

 lcd_1.setCursor(0, 0);
 if (hora.tm_hour < 10) {
        lcd_1.print("0");
        lcd_1.print(hora.tm_hour);
      } else {
        lcd_1.print(hora.tm_hour);
      }
  lcd_1.print(":");
 lcd_1.setCursor(3, 0);
    if (hora.tm_min < 10) {
      lcd_1.print("0");
      lcd_1.print(hora.tm_min);
    } else {
      lcd_1.print(hora.tm_min);
    }
  lcd_1.print(":");

  if (hora.tm_sec < 10) {
    lcd_1.print("0");
    lcd_1.print(hora.tm_sec);
  } else {
    lcd_1.print(hora.tm_sec);
  }

   //reiniciar tiempoPatron
	tiempoPatron=millis()+1000;
}

  
  delay(10); // Wait for 10 millisecond(s)
}
