#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;




stDate CalculateVacationReturnDate(stDate FromDate ,short VacationDays) {
	
	// FromDate = IncreaseDateOneDay(FromDate);
	// isBusinessDay 
	//IsWeekEnd
	
	short WeekEndDays =0;
	while(IsWeekEnd(FromDate)){
		FromDate = IncreaseDateOneDay(FromDate);
	}
		
	
	for (int i = 0; i < VacationDays + WeekEndDays; i++) {
		
		if(IsWeekEnd(FromDate)){
			WeekEndDays++;	
		}
		FromDate = IncreaseDateOneDay(FromDate);
	}
	
	
	
	while(IsWeekEnd(FromDate)){
		FromDate = IncreaseDateOneDay(FromDate);
	}
	
	

	
	return FromDate;
}


int main() {
	system("cl");
	stDate FromDate = ReadFullDate();
	
	short VacationDays=0;
	cout << "Please Enter Vacation Days?: " ;
	cin >> VacationDays;
	stDate Date ;
	
	Date = CalculateVacationReturnDate(FromDate,VacationDays);
	cout <<Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	return 0;
};