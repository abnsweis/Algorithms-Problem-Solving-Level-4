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

short ReadNumberOfDays(){ 
	int days;

	cout << "Please Enter Number Of Days To Add  :" ; 
	cin >> days ;
	
	return days;
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

short NumberOfDaysFromTheBeginingOfTheYear(short days , short Month , short year){

	short TotalDays = 0;
	
	for (int i = 1; i <= Month  - 1 ; i++) {
		TotalDays += NumberOfDaysInMonth(i,year);
	}
	TotalDays += days;
	return TotalDays  ;
}




stDate AddDaysToDate(stDate Date,short Days){
	
	short RemainingDays =Days +NumberOfDaysFromTheBeginingOfTheYear(Date.Day,Date.Month,Date.Year);
	
	short MonthDays=1;
	
	Date.Month = 1;
	
	while(true){
		MonthDays = NumberOfDaysInMonth(Date.Month,Date.Year);	
		if(RemainingDays   > MonthDays){
			RemainingDays -= MonthDays;
			Date.Month++;
			if(Date.Month > 12){
				Date.Month = 1;
				Date.Year++;
			}
		}
		else{
			
			Date.Day = RemainingDays;
			break;
		}
	}
	
	
	
	
	return Date;
	
}

int main(){
	system("cl");
	
	// stDate Date = ReadFullDate();
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	
	Date.Year = ReadYear();	
	
	short NumberOfDaysToAdd = ReadNumberOfDays();
	
	Date = AddDaysToDate(Date,NumberOfDaysToAdd);
	
	cout << "Date After Adding ["<<NumberOfDaysToAdd <<" ] Days is  " ;
	cout << Date.Day<<"/";
	cout << Date.Month<<"/";
	cout <<Date.Year<< "/"<<endl;
	
	
	
	
	
	return 0;
};


