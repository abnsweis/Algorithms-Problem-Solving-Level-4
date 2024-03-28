#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;


struct stPeriod {
	stDate DateFrom ;
	stDate DateTo;
};





stPeriod ReadPeriod(){
	stPeriod Per;
	cout << "Read Date From :" << endl;
	Per.DateFrom = ReadFullDate();
	cout << "\nRead Date To :" << endl;
	Per.DateTo = ReadFullDate();
	cout  << endl;
	return Per;
}

short PeriodLengthInDays(stPeriod Per,bool includeEndDay = false){
	return DaysDifferenceBetweenTwoDates(Per.DateFrom,Per.DateTo,includeEndDay);
}


int main(){
	
	stPeriod Per;
	
	
	system("cl");
	
	cout << "Read Period 1" << endl;
	Per = ReadPeriod();	
	
	
	cout << "Period length = " <<PeriodLengthInDays(Per) << endl;
	cout << "Period length (Include End Day)= " <<PeriodLengthInDays(Per,true) << endl;
	
	return 0;
};