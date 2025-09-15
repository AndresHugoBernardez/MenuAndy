


#include"time_Andy.h"
#include"menuAndy.h"
#include"ArduinoEmulated.h" 
#include"StringAndy.h"









// cadenas, deben ser menores a 16 caracteres
char horaString[] = "Hora";
char alarma1String[] = "Alarma 1";
char alarma2String[] = "Alarma 2";
char alarma3String[] = "Alarma 3";
char alarma4String[] = "Alarma 4";
char activarAlarmasString[] = "Activa alarmas";
char activadaString[] = "Activada";
char desactivadaString[] = "Desactivada";


// Menu principal
Item  Menu1[6] = {
	Item(TIME_ANDY, horaString,0),
	Item(TIME_ANDY, alarma1String,30),
	Item(TIME_ANDY, alarma2String,60),
	Item(TIME_ANDY, alarma3String,90),
	Item(TIME_ANDY, alarma4String,120),
	Item(OPTION, activarAlarmasString) };

// Menu OPCIONES
char * activarOptions[2] = {activadaString,desactivadaString};


Item  MenuPrincipal(MENU, "Menu Principal") ;



//fourButtonsAndy Opciones;


void setup() {

	MenuPrincipal.allocateItems(6,Menu1);

	Menu1[5].allocateOptions(2,activarOptions);

	Opcions.Init(&MenuPrincipal, 300);
	Opcions.setButtons(0, 1, 2, 3);

	


}

int main() {
	int rtrn = 1;



	setup();



	
	
	menuAndy();

	
	
	

	rtrn = 0;

	return (rtrn);
}