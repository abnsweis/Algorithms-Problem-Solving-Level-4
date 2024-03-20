#pragma warning(disable : 4996);

#include <iostream>
#include <ctime>
using namespace std;

namespace MyLibDate {
	struct stDate {
		short Day;
		short Month;
		short Year;
	};
	// Read Year From Screen
	short ReadYear() {
		int Year;

		cout << "Please Enter Year :";
		cin >> Year;

		return Year;
	}
	// Read Month From Screen in range from 1 to 12 only
	short ReadMonth() {
		int Month;

		do {
			cout << "Please Enter Month :";
			cin >> Month;
		}while(Month > 12 || Month <= 0);

		return Month;
	}
	// Read Days From Scren in range from 1 to 31 only
	short ReadDay() {
		int Day;

		do {
			cout << "Please Enter Day :";
			cin >> Day;
		}while(Day > 31 || Day <= 0);

		return Day;
	}

	// Function return true if year parameter is leap Year
	bool isLeapYear(short year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	// Read Full Date From Sreen Year + Month + Day
	stDate ReadFullDate() {
		stDate Date;

		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();

		return Date;
	}
	// Function return Number Of Month in Year
	short NumberOfDaysInMonth(short month, short year) {
		if (month < 1 || month > 12)
		return 0;

		short arrNumberOdays[12] = {
			31,
			28,
			31,
			30,
			31,
			30,
			31,
			31,
			30,
			31,
			30,
			31
		};

		return (month == 2) ? (isLeapYear(year) ? 29: 28): arrNumberOdays[month - 1];
	}
	// Function return true if month parameter is last month in year
	bool isLastMonthInYear(short Month) {
		return Month == 12;
	}
	// Function return true if day  is last day in month
	bool isLastDayInMonth(stDate Date) {

		return NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day;

	}

	// Get Date Now
	stDate GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);

		stDate Date;

		Date.Year = now->tm_year +1900;
		Date.Month = now->tm_mon +1;
		Date.Day = now->tm_mday;

		return Date;

	}

	// // This function returns what day of the week the data type is integer.
	// short DayOfWeekOrder(short year , short Month,short day){
	// 	short a = (14 - Month )/ 12 ;
	// 	short y = year - a ;
	// 	short m = Month + (12*a) - 2;

	// 	short DayOfWeek = (day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12))%7;
	// 	return DayOfWeek;

	// }

	// // This function returns the name of the day according to index
	// string GetDayNameByIndex(short index){
	// 	string DaysName[7] = {"Sunday","Monday","Tuesday","Wednesday"
	// 	,"Thursday","Friday","Saturday"};
	// 	return DaysName[index];
	// }
	

	bool isLastDayInMonthe(stDate Date) {

		return NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day;

	}
	bool DateOneisLess(stDate Date1, stDate Date2) {


		return(Date1.Year < Date2.Year) ? true: ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true: (Date1.Month == Date2.Month ? Date1.Day < Date2.Day: false)): false);

	}
	stDate IncreaseDateOneDay(stDate Date) {

		if(isLastDayInMonthe(Date)) {

			if(isLastMonthInYear(Date.Month)) {
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}

		}else {
			Date.Day++;
		}
		return Date;
	}


	void SwapDates(stDate &Date1, stDate &Date2) {

		stDate TempDate;

		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;


		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;

	}
	int DaysDifferenceBetweenTwoDates(stDate Date1, stDate Date2, bool
		IncludeEnd = false) {


		short CounterDays = 0;
		short SwapFlagValue = 1;

		if(!DateOneisLess(Date1, Date2)) {
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while(DateOneisLess(Date1, Date2)) {
			CounterDays++;
			Date1 = IncreaseDateOneDay(Date1);
		}



		return IncludeEnd ? ++CounterDays * SwapFlagValue: CounterDays *SwapFlagValue;
	}
}