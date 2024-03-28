#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;


struct stPeriod {
	stDate DateFrom ;
	stDate DateTo;
};



enum enCompareDates {
	After = 1, 
	Equal = 0,
	Before = -1
};
enCompareDates CompareDates(stDate Date1, stDate Date2) {


	if(Date1EqualDate2(Date1, Date2)) {
		return enCompareDates::Equal;
	}
	if(Date1BeforeDate2(Date1, Date2)) {
		return enCompareDates::Before;
	}

	return enCompareDates::After;


}


stPeriod ReadPeriod(){
	stPeriod Per;
	cout << "Read Date From :" << endl;
	Per.DateFrom = ReadFullDate();
	cout << "\nRead Date To :" << endl;
	Per.DateTo = ReadFullDate();
	cout  << endl;
	return Per;
}
// 1/2/2024
// 10/2/2024

// 6/2/2024
// 30/2/2024

bool IsOverlapPeriods(stPeriod Per1 , stPeriod Per2){
	
	if(
		(CompareDates(Per2.DateTo,Per1.DateFrom)==enCompareDates::Before)||((CompareDates(Per2.DateFrom,Per1.DateTo)==enCompareDates::After)
		)){
		return false;
	}
	
	return true;
}


int main(){
	
	stPeriod Per1 ;
	stPeriod Per2 ;
	
	system("cl");
	
	cout << "Read Period 1" << endl;
	Per1 = ReadPeriod();	
	
	cout << "\nRead Period 2" << endl;
	Per2 = ReadPeriod();
	
	
	if(IsOverlapPeriods(Per1,Per2)){
		cout << "Yes, Periods Overlap" << endl;
	}else{
		cout << "No, Periods is Not Overlap" << endl;
		
	}
	
	return 0;
};