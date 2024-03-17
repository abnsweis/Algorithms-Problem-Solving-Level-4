#include <iostream>
#include <string>
using namespace std;

short ReadYear(){ 
	int Year;

	cout << "Please Enter Year :" ; 
	cin >> Year ;
	
	return Year;
}
short ReadMonth(){ 
	int Month;

	do{
	cout << "Please Enter Month :" ; 
	cin >> Month ;
	}while(Month > 12 || Month <= 0);
	
	return Month;
}
short ReadDay(){ 
	int Day;

	do{
	cout << "Please Enter Day :" ; 
	cin >> Day ;
	}while(Day > 31 || Day <= 0);
	
	return Day;
}
bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

struct stDate{
	short Day;
	short Month;
	short Year;
};

stDate ReadFullDate(){
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	
	return Date;
}

short NumberOfDaysInMonth(short month, short year){
	if (month < 1 || month > 12)
		return 0;

	short arrNumberOdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOdays[month - 1];
}

bool DateOneisLess(stDate Date1 ,stDate Date2){
	

	return(Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool isLastMonthInYear(short Month){
	
	return Month == 12;
	
}

bool isLastDayInMonthe(stDate Date){
	
	return NumberOfDaysInMonth(Date.Month,Date.Year) ==  Date.Day;
	
}


stDate IncreaseDateOneDay(stDate Date){
	
	if(isLastDayInMonthe(Date)){
		
		if(isLastMonthInYear(Date.Month)){
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else{
			Date.Day=1;
			Date.Month++;
		}
			
	}else{
		Date.Day++;
	}
	return Date;	
}

void SwapDates(stDate &Date1,stDate &Date2){
	
	stDate TempDate ;
	
	TempDate.Year = Date1.Year;
	TempDate.Month= Date1.Month;
	TempDate.Day= Date1.Day;
	
	
	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;
	
	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
	
}

int DaysDifferenceBetweenTwoDates(stDate Date1 ,stDate Date2,bool
IncludeEnd = false){
	
	
	short CounterDays = 0;
	short SwapFlagValue = 1;
	
	if(!DateOneisLess(Date1,Date2)){
		SwapDates(Date1,Date2);
		SwapFlagValue=-1;
	}
	
	while(DateOneisLess(Date1,Date2)  ){
		CounterDays++;
		Date1 = IncreaseDateOneDay(Date1);
	}
	
	
	
	return IncludeEnd ? ++CounterDays * SwapFlagValue: CounterDays *SwapFlagValue;
}



int main(){
	system("cl");
	stDate Date1= ReadFullDate();
	cout  << endl;
	stDate Date2= ReadFullDate();

	
	cout << DaysDifferenceBetweenTwoDates(Date1,Date2) << endl;
	cout << "Include End "<<DaysDifferenceBetweenTwoDates(Date1,Date2,true) << endl;

		
	
	
	
	
	
	
	return 0;
};

