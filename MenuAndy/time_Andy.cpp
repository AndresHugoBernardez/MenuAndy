


#include"time_Andy.h"

//----



time_tAndy mktimeAndy(const tmAndy* TM) {
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
	return (time_tAndy)seconds;
}



void localtimeAndy(tmAndy* TM, time_tAndy* timeInput) {
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












