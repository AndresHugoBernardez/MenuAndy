


#include "ArduinoEmulated.h"
#include"menuAndy.h"
#include <arduino.h>







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
