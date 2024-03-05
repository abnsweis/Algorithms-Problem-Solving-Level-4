#include <iostream>
using namespace std;

bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

short DaysOg0fYear(short year){
	return isLeapYear(year) ? 366 :365;
}


short HoursOfYear(short year){
	return DaysOg0fYear(year) * 24;
}

int MinutesOfYear(short year){
	return HoursOfYear(year) * 60;
}

int SecoundsOfYear(short year){
	return MinutesOfYear(year) * 60;
}


int ReadNumber(string massage){ 
	int number;

	cout << massage ; 
	cin >> number ;
	
	return number;
}
int main(){
	system("cl");
	short Year = ReadNumber("Please Enter Year : ");
	
	cout<<"Number of Days in Year [ "<<Year<<" ] is "<<DaysOg0fYear(Year)<<endl;
	cout<<"Number of Hours in Year [ "<<Year<<" ] is "<<HoursOfYear(Year)<<endl;
	cout<<"Number of Minutes in Year [ "<<Year<<" ] is "<<MinutesOfYear(Year)<<endl;
	cout<<"Number of Secounds in Year [ "<<Year<<" ] is "<<SecoundsOfYear(Year)<<endl;
	
	return 0;
};