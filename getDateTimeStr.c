#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct dateTime{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
}dateTime;

dateTime *getDateTime(){
	/* 生成当前中国时间 */ 
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	dateTime *dt;
	dt->year = p->tm_year + 1900;
	dt->mon = p->tm_mon + 1;
	dt->day = p->tm_mday;
	dt->hour = p->tm_hour + 8;
	dt->min = p->tm_min;
	dt->sec = p->tm_sec;
	return dt;
}

void getDateTimeStr(char *str){
	/* 返回字符串格式的日期及时间 */
	dateTime *dt = getDateTime();
	char year[4];
	char mon[2];
	char day[2];
	char hour[2];
	char min[2];
	char sec[2];
	itoa(dt->year,year,10);
	itoa(dt->mon,mon,10);
	itoa(dt->day,day,10);
	itoa(dt->hour,hour,10);
	itoa(dt->min,min,10);
	itoa(dt->sec,sec,10);
	strcat(str,year);
	strcat(str,"/");
	strcat(str,mon);
	strcat(str,"/");
	strcat(str,day);
	strcat(str," ");
	if(dt->hour < 10){
		strcat(str,"0");
	}
	strcat(str,hour);
	strcat(str,":");
	if(dt->min < 10){
		strcat(str,"0");
	}
	strcat(str,min);
	strcat(str,":");
	if(dt->sec < 10){
		strcat(str,"0");
	}
	strcat(str,sec); 
	strcat(str,"\0"); 
}

int main(){
	char curr_dt[100];
	getDateTimeStr(curr_dt);
	printf("当前时间： %s", curr_dt);
	return 0;	
} 
