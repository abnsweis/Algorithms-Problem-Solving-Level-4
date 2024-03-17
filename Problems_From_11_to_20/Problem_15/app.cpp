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

bool isLastMonthInYear(short Date){
	
	return Month == 12;
	
}

bool isLastDayInMonthe(stDate Date){
	
	return NumberOfDaysInMonth(Date.Month,Date.Year) ==  Date.Day;
	
}


int main(){
	system("cl");
	cout << "Read Date  :"  << endl;
	stDate Date= ReadFullDate();

	

	
	if(isLastDayInMonthe(Date)){
		cout << "Yes , Day is Last Day in Month " << endl;	
	}else{
		cout << "No ,  Day is Not Last Day in Month  " << endl;	
		
	}
	if(isLastMonthInYear(Date.Month)){
		cout << "Yes , Month is Last Month in Year " << endl;	
	}else{
		cout << "No ,  Month is Not Last Month in Year " << endl;	
		
	}
		
	
	
	
	
	
	
	return 0;
};


