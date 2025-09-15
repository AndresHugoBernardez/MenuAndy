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

void optionsAndy(int * opcion);
extern lcd lcd_1;



#endif // !_Arduino_EM_ANDY




