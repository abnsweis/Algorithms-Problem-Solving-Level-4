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

bool isDateWithInThePeriod(stPeriod Per,stDate Date){
	return !(
		CompareDates(Date,Per.DateFrom) == enCompareDates::Before ||
		CompareDates(Date,Per.DateTo) == enCompareDates::After );
}

int main(){
	
	stPeriod Per;
	stDate Date;
	
	system("cl");
	
	cout << "Read Period 1" << endl;
	Per = ReadPeriod();	
	
	cout << "\nRead Dare" << endl;
	Date = ReadFullDate();
	
	if(isDateWithInThePeriod(Per,Date)){
		cout<<"Yes,Date is within Period .";
	}
	else{
		cout<<"No,Date is not within Period .";
	}
	
	return 0;
};