#include <iostream>
using namespace std;


int ReadNumber(string massage){ 
	int number;

	cout << massage ; 
	cin >> number ;
	
	return number;
}
bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year,short Month){
	
	if(Month < 0 || Month > 12){
		return 0;
	};
	
	short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	
	
	return (Month == 2) ? (isLeapYear(Year) ? 29:28 ) : NumberOfDays[Month -1];
}



int main(){
	system("cl");
	short Year = ReadNumber("Please Enter Year to check:");
	short Month = ReadNumber("Please Enter Month to check:");
	
	cout<<"Number of Days in Month [ "<<Month<<" ] is "<<NumberOfDaysInAMonth(Year,Month)<<endl;
	return 0;
};