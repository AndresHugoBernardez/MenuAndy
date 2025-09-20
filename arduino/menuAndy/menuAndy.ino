#include <arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include "time_Andy.h"
#include "StringAndy.h"
#include "ArduinoEmulated.h"
#include "menuAndy.h"
// C++ code


//

LiquidCrystal lcd_1(7,6,5,4,3,2);



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
		case MENU:

          stradd_Andy(cadena1, Opcions.currentItem->subItems[Opcions.pos].itemName);
			break;

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

      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print(cadena1);
      lcd_1.setCursor(0, 1);
      lcd_1.print(cadena2);
      


    
    

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

lcd_1.clear();
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
  Item(TIME_ANDY, horaString,1),
  Item(TIME_ANDY, alarma1String,10),
  Item(TIME_ANDY, alarma2String,20),
  Item(TIME_ANDY, alarma3String,30),
  Item(TIME_ANDY, alarma4String,40),
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
 // alarma 1
  apertura1.tm_hour = 0;
  apertura1.tm_min = 0;
  apertura1.tm_sec = 1;


  // alarma 1
  apertura1.tm_hour = 0;
  apertura1.tm_min = 0;
  apertura1.tm_sec = 10;
  // alarma 2
  cierre1.tm_hour = 0;
  cierre1.tm_min = 0;
  cierre1.tm_sec = 20; 
  // alarma 3
  apertura2.tm_hour = 0;
  apertura2.tm_min = 0;
  apertura2.tm_sec = 30;
  // alarma 4
  cierre2.tm_hour = 0;
  cierre2.tm_min = 0;
  cierre2.tm_sec = 40;

  
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

