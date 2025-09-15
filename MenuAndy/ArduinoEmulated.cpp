

#include<iostream>
#include "ArduinoEmulated.h"
#include"menuAndy.h"





unsigned int millis() {

	return(clock());





}


void delay(unsigned int miliseconds) {

	unsigned int CLK = 0;
	CLK = millis() + miliseconds;
	while (millis() < CLK);

}





int checkState(fourButtonsAndy* Botones, int BUTTON, int STATUS) {

	int btn;

	//aclaración para windows hay que setear los botones desde el 0 hasta 3 usando "this.setButtons(0,1,2,3);" Opciones.buttons[i].Pin tiene que ser igual a "i" para que funcione en windows. 
	btn = Botones->buttons[BUTTON].Value;	//digitalRead(BUTTON);


	if (btn == STATUS)
	{
		delay(50);
		btn = Botones->buttons[BUTTON].Value;	//digitalRead(BUTTON);
		if (btn == STATUS)
			return(1);
	}
	return(0);
}


  

	int lcd::setCursor(int col, int row) {
		return(0);
	}

	void lcd::print(char* cadena) {
		std::cout << cadena << std::endl;
	}
	void lcd::print(const char* cadena) {
		std::cout << cadena << std::endl;
	}

	void optionsAndy(int *opcion) {
		std::cout << "1:Menu/Accept 2:Exit/Cancel 3:Up 4:Down" << std::endl;
		std::cin >> (*opcion);
	}

lcd lcd_1;






