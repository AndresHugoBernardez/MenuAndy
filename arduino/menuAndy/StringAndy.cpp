
#include"StringAndy.h"



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


		k--;
		while (k > -1) {
			destination[i] = cadena[k];
			i++;
			k--;
		
		
		
		}


		destination[i] = '\0';

	}
