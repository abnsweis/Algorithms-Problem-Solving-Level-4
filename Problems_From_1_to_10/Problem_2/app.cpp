#include <iostream>
using namespace std;

bool isLeapYear(short year){
	
	if(year % 400 == 0){
		return true;
	}
	
	else if(year % 100 == 0){
		return false;
	}
	else if(year % 4 == 0){
		return true;
	} 
	else{
		return false;
	}
	
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