

/*

void setTime_A(int hh, int mm, int ss) {

	if (hh < 24)
		time_A = hh * 10000 + mm * 100 + ss;
	else
		time_A = (hh % 24) * 10000 + mm * 100 + ss;




}
void setDate_A(int yy, int MM, int dd) {

	if (yy < 3000)
		date_A = yy * 10000 + MM * 100 + dd;
	else
		date_A = (yy % 3000) * 10000 + MM * 100 + dd;


}


void getPartTime_A() {



	//this.Pos select hours, minutes or seconds
	switch (Pos) {
		//get Hours
	case 0:
		value = time_A / 10000;
		break;
		//get Minutes
	case 1:
		value = (time_A - (time_A / 10000)) / 100;
		break;
		//get Seconds
	case 2:
		value = time_A % 100;
		break;
	default:
		value = -1;
	}
}

void getPartDate_A() {



	//this.Pos select Year, month or day.
	switch (Pos) {
		//get Year
	case 0:
		value = (int)(date_A / 10000);
		break;
		//get month
	case 1:
		value = (int)((date_A - (time_A / 10000)) / 100);
		break;
		//get day
	case 2:
		value = (int)(date_A % 100);
		break;
	default:
		value = -1;
	}

}

int setPartTime_A() {
	int returned = 0, hh, mm, ss;


	if (Pos<3 && Pos>-1)
	{




		//this.Pos select hours, minutes or seconds and this.value contains its value
		switch (Pos) {
			//set Hours
		case 0:

			hh = value;
			mm = (time_A - (time_A / 10000)) / 100;
			ss = time_A % 100;

			setTime_A(hh, mm, ss);
			break;
			//set Minutes
		case 1:
			hh = time_A / 10000;
			mm = value;
			ss = time_A % 100;
			setTime_A(hh, mm, ss);
			break;
			//set Seconds
		case 2:
			hh = time_A / 10000;
			mm = (time_A - (time_A / 10000)) / 100;
			ss = value;
			setTime_A(hh, mm, ss);
			break;
		default:
			returned = 9002;
		}
	}
	else {
		returned = 9001;
	}


	return(returned);

}


int setPartDate_A() {
	int returned = 0, yy, MM, dd;


	if (Pos<3 && Pos>-1)
	{




		//this.Pos select hours, minutes or seconds and this.value contains its value
		switch (Pos) {
			//set Hours
		case 0:

			yy = value;
			MM = (time_A - (time_A / 10000)) / 100;
			dd = time_A % 100;

			setDate_A(yy, MM, dd);;
			break;
			//set Minutes
		case 1:
			yy = time_A / 10000;
			MM = value;
			dd = time_A % 100;
			setDate_A(yy, MM, dd);
			break;
			//set Seconds
		case 2:
			yy = time_A / 10000;
			MM = (time_A - (time_A / 10000)) / 100;
			dd = value;
			setDate_A(yy, MM, dd);
			break;
		default:
			returned = 9012;
		}
	}
	else {
		returned = 9011;
	}


	return(returned);

}

*/
//---