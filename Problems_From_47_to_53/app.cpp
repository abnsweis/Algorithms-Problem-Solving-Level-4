#pragma warning(disable : 4996);

#include <iostream>
#include <ctime>
#include "../MyLibDate.h"
using namespace MyLibDate;
using namespace std;



short DayOfWeekOrder(short year, short Month, short day) {
	short a = (14 - Month)/ 12;
	short y = year - a;
	short m = Month + (12*a) - 2;

	short DayOfWeek = (day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12))%7;
	return DayOfWeek;

}

short DayOfWeekOrder(stDate Date) {
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);


}
// This function returns the name of the day according to index
string GetDayNameByIndex(short index) {
	string DaysName[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	return DaysName[index];
}

short NumberOfDaysInYear(short Year) {
	return isLeapYear(Year) ? 366: 365;
}



bool IsItEndOfWeek(stDate Date) {
	short IndexDayWeek = DayOfWeekOrder(Date);
	return IndexDayWeek == 6;
}

bool IsWeekEnd(stDate Date) {
	short IndexDayWeek = DayOfWeekOrder(Date);
	return IndexDayWeek == 5 || IndexDayWeek == 6;
}

bool isBusinessDay(stDate Date) {
	return !IsWeekEnd(Date);
}
short DaysUntilEndOfWeek(stDate Date) {
	return 6 - DayOfWeekOrder(Date);

}
short DaysUntilEndOfMonth(stDate Date) {
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return DaysDifferenceBetweenTwoDates(Date, EndOfMonthDate);
}
short DaysUntilEndOfYear(stDate Date) {
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = 31;
	EndOfMonthDate.Month = 12;
	EndOfMonthDate.Year = Date.Year;

	return DaysDifferenceBetweenTwoDates(Date, EndOfMonthDate);

}


int main() {

	system("cl");

	stDate DateNow = GetSystemDate();
	short IndexDay = DayOfWeekOrder(DateNow);
	cout << "Today is "<<
	GetDayNameByIndex(IndexDay) << " ";
	cout << DateNow.Day << "/" << DateNow.Month << "/"<< DateNow.Year << endl;



	cout << "It is End Of Week?" << endl;
	if(IsItEndOfWeek(DateNow)) {
		cout << "Yes , it is a week end" << endl;
	}else {
		cout << "No , Not End Of week" << endl;

	}
	cout << "\nIt is Weekend?" << endl;
	if(IsWeekEnd(DateNow)) {
		cout << "Yes , it is a week end" << endl;
	}else {
		cout << "No , Not End Of week" << endl;

	}cout << "\nIt is Business Day?" << endl;
	if(isBusinessDay(DateNow)) {
		cout << "Yes , it is Business Day" << endl;
	}else {
		cout << "No , Not Business Day" << endl;

	}

	cout << "Days Until End Of Week is " << DaysUntilEndOfWeek(DateNow)<<" Day(s)"<<endl;

	cout << "Days Until End Of Month is " << DaysUntilEndOfMonth(DateNow)<<" Day(s)"<<endl;

	cout << "Days Until End Of Yearis " << DaysUntilEndOfYear(DateNow)<<" Day(s)"<<endl;

	return 0;
};