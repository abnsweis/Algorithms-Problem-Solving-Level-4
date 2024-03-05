#include <iostream>
using namespace std;

bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

int ReadNumber(string massage){ 
	int number;

	cout << massage ; 
	cin >> number ;
	
	return number;
}
int main(){
	system("cl");
	short Year = ReadNumber("Please Enter Year?:");
	if(isLeapYear(Year)){
		cout << "Yes,"<< Year << " is Leap Year :-)" << endl;	
	}else{
		cout << "No,"<< Year << " is Not Leap Year :-(" << endl;	
	}
	return 0;
};