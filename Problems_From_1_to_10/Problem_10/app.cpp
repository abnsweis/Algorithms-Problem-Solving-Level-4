#include <iostream>
#include <string>
using namespace std;

short ReadYear(){ 
	int Year;

	cout << "Please Enter Year " ; 
	cin >> Year ;
	
	return Year;
}
short ReadMonth(){ 
	int Month;

	do{
	cout << "Please Enter Month " ; 
	cin >> Month ;
	}while(Month > 12 || Month <= 0);
	
	return Month;
}
short ReadDay(){ 
	int Day;

	do{
	cout << "Please Enter Day " ; 
	cin >> Day ;
	}while(Day > 31 || Day <= 0);
	
	return Day;
}


bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



short NumberOfDaysInAMonth(short Year,short Month){
	
	if(Month < 0 || Month > 12){
		return 0;
	};
	
	short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	
	
	return (Month == 2) ? (isLeapYear(Year) ? 29:28 ) : NumberOfDays[Month -1];
}




short NumberOfDaysRemainingInYear(short days , short Month , short year){

	short NumberOfdaysRemaining = 0;
	
	for (int i = 1; i < Month; i++) {
		NumberOfdaysRemaining += NumberOfDaysInAMonth(year,i);
	}
	
	NumberOfdaysRemaining += days;
	return NumberOfdaysRemaining  ;
}

int main(){
	system("cl");
	
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	cout << "nNumber of Days from the begining of the year is "  ;
	cout << NumberOfDaysRemainingInYear(Day,Month,Year)<<endl;
	
	return 0;
};