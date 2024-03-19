#include <iostream>
using namespace std;

namespace MyLibDate {
	struct stDate{
		short Day;
		short Month;
		short Year;
	};
	// Read Year From Screen
	short ReadYear(){ 
		int Year;

		cout << "Please Enter Year :" ; 
		cin >> Year ;
	
		return Year;
	}
	// Read Month From Screen in range from 1 to 12 only
	short ReadMonth(){ 
		int Month;
	
		do{
		cout << "Please Enter Month :" ; 
		cin >> Month ;
		}while(Month > 12 || Month <= 0);
		
		return Month;
	}
	// Read Days From Scren in range from 1 to 31 only
	short ReadDay(){ 
		int Day;
	
		do{
		cout << "Please Enter Day :" ; 
		cin >> Day ;
		}while(Day > 31 || Day <= 0);
		
		return Day;
	}
	
	// Function return true if year parameter is leap Year 
	bool isLeapYear(short year){
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	// Read Full Date From Sreen Year + Month + Day
	stDate ReadFullDate(){
		stDate Date;
		
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		
		return Date;
	}
	// Function return Number Of Month in Year 
	short NumberOfDaysInMonth(short month, short year){
		if (month < 1 || month > 12)
			return 0;
	
		short arrNumberOdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOdays[month - 1];
	}
	// Function return true if month parameter is last month in year
	bool isLastMonthInYear(short Month){
		return Month == 12;
	}
	// Function return true if day  is last day in month
	bool isLastDayInMonth(stDate Date){
		
		return NumberOfDaysInMonth(Date.Month,Date.Year) ==  Date.Day;
		
	}
	
}