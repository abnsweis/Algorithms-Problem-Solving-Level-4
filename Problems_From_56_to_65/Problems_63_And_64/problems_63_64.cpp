#include <iostream>
#include <string>
#include "../../MyLibDate.h"
#include "../../MyStringLib.h"
using namespace std;
using namespace MyLibDate;



string ReadStringDate(){
	string Date = "";
	cout << "Pleaee Enter Full Date As String :";
	cin >> Date;
	
	
	return Date;
}



stDate StringToDate(string date_str){
	stDate Date;
	vector <string> Vector_Date = Mylib::split(date_str,"/");
	
	Date.Day=stoi(Vector_Date[0]);
	Date.Month=stoi(Vector_Date[1]);
	Date.Year=stoi(Vector_Date[2]);
	return Date;
}

string DateToString(stDate Date){
	
	string DateString="";
	
	DateString+=to_string(Date.Day) + "/";
	DateString+=to_string(Date.Month) + "/";
	DateString+=to_string(Date.Year);
	return DateString;
}



int main(){
	
	string DateOneLineString = ReadStringDate();
	stDate Date;
	
	cout << "\nConvert Date From String To \'sdDate\'" << endl;
	
	Date = StringToDate(DateOneLineString);
	
	cout << "Day : "<<Date.Day << endl;
	cout << "Month : "<<Date.Month << endl;
	cout << "Year : "<<Date.Year << endl;
	
	
	
	cout << "\nConvert Date From \"sdDate\" To \'String\'" << endl;
	cout << DateToString(Date) << endl;
	return 0;
};