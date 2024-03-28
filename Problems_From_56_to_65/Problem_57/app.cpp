#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;


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


int main() {

	system("cl");

	cout << "Read Date 1" << endl;
	stDate Date1 = ReadFullDate();

	cout << "\nRead Date 2" << endl;
	stDate Date2 = ReadFullDate();

	cout << "Compar Result = " << CompareDates(Date1, Date2) ;


	return 0;
};