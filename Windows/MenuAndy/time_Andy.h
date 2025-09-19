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



/*==============================================================================*/
/* Useful Constants */
#define SECS_PER_MIN  ((time_tAndy)(60UL))
#define SECS_PER_HOUR ((time_tAndy)(3600UL))
#define SECS_PER_DAY  ((time_tAndy)(SECS_PER_HOUR * 24UL))


// leap year calculator expects year argument as years offset from 1970
#define LEAP_YEAR(Y)     ( ((1970+(Y))>0) && !((1970+(Y))%4) && ( ((1970+(Y))%100) || !((1970+(Y))%400) ) )

static  const int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // API starts months from 1, this array starts from 0


time_tAndy mktimeAndy(const tmAndy*);
void localtimeAndy(tmAndy*, time_tAndy* );

#endif
