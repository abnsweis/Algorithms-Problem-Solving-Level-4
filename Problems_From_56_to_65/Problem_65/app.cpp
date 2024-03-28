#include <iostream>
#include <string>
#include "../../MyLibDate.h"
#include "../../MyStringLib.h"
using namespace std;
using namespace MyLibDate;



string ReadStringDate() {
	string Date = "";
	cout << "Pleaee Enter dd/mm/yy  :";
	cin >> Date;


	return Date;
}



stDate StringToDate(string date_str) {
	stDate Date;
	vector < string > Vector_Date = Mylib::split(date_str, "/");

	Date.Day = stoi(Vector_Date[0]);
	Date.Month = stoi(Vector_Date[1]);
	Date.Year = stoi(Vector_Date[2]);
	return Date;
}

string DateToString(stDate Date) {

	string DateString = "";

	DateString += to_string(Date.Day) + "/";
	DateString += to_string(Date.Month) + "/";
	DateString += to_string(Date.Year);
	return DateString;
}


string FotmatDate(stDate Date, string format) {

	string FormatedStringDate = "";

	FormatedStringDate = Mylib::replceWord(format, "dd", to_string(Date.Day));
	FormatedStringDate = Mylib::replceWord(FormatedStringDate, "mm", to_string(Date.Month));
	FormatedStringDate = Mylib::replceWord(FormatedStringDate, "yyy", to_string(Date.Year));



	return FormatedStringDate;


}

int main() {

	string DateOneLineString = ReadStringDate();
	stDate Date;


	Date = StringToDate(DateOneLineString);




	cout << FotmatDate(Date, "yyy/mm/dd") << endl;
	cout << FotmatDate(Date, "dd/mm/yyy") << endl;
	cout << FotmatDate(Date, "mm/yyy/dd") << endl;
	return 0;
};