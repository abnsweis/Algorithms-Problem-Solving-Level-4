#include <iostream>
using namespace std;


int ReadNumber(string massage){ 
	int number;

	cout << massage ; 
	cin >> number ;
	
	return number;
}
bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year,short Month){
	
	if(Month < 0 || Month > 12){
		return 0;
	}
	if(Month == 2){
		return isLeapYear(Year) ? 29 : 28;	
	}
	
	short Arr31Days[7] = {1,3,5,7,8,10,12};
	for (short i = 0; i < 7; i++) {
		if(Arr31Days[i-1] == Month ){
			return 31;
		}
	}
	return 30;
}
short NumberOfHoursInAMonth(short Year,short Month){
	return NumberOfDaysInAMonth(Year,Month) *24;
}
int NumberOfMinutesInAMonth(short Year,short Month){
	return NumberOfHoursInAMonth(Year,Month) *60;
}
int NumberOfSecoundsInAMonth(short Year,short Month){
	return NumberOfMinutesInAMonth(Year,Month) *60;
}


int main(){
	system("cl");
	short Year = ReadNumber("Please Enter Year to check:");
	short Month = ReadNumber("Please Enter Month to check:");
	
	cout<<"Number of Days in Month [ "<<Month<<" ] is "<<NumberOfDaysInAMonth(Year,Month)<<endl;
	cout<<"Number of Hours in Month [ "<<Month<<" ] is "<<NumberOfHoursInAMonth(Year,Month)<<endl;
	cout<<"Number of Minutes in Month [ "<<Month<<" ] is "<<NumberOfMinutesInAMonth(Year , Month)<<endl;
	cout<<"Number of Secounds in Month [ "<<Month<<" ] is 	"<<NumberOfSecoundsInAMonth(Year,Month)<<endl;
	return 0;
};