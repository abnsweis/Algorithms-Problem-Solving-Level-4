#include <iostream>
#include "../../MyLibDate.h"

using namespace std;
using namespace MyLibDate;
bool Date1AfterDate2(stDate Date1, stDate Date2) {

	return (!Date1BeforeDate2(Date1, Date2)) && (!Date1EqualDate2(Date1, Date2));
}


int main() {

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	if(Date1AfterDate2(Date1, Date2)) {
		cout << "Yes, Date1 is After Date2" << endl;
	}else {
		cout << "No, Date1 is Not After Date2" << endl;
	}

	return 0;
};