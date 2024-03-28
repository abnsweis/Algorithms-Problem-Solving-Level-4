#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;


bool IsValidDate(stDate Date){
	
	if(Date.Day < 1 || Date.Day > 31){
		return false;
	}
	if(Date.Month < 1 || Date.Month > 12){
		return false;
	}
	
	
	if(Date.Month == 2){
		if(isLeapYear(Date.Year)){
			if(Date.Day > 29){
				return false;	
			}
		}
		else{
			if(Date.Day > 28){
				return false;
			}
		}
	}
	
	
	short DaysMonth = NumberOfDaysInMonth(Date.Month,Date.Year);
	if(Date.Day > DaysMonth){
		return false;
	}
	return true;
	
}



int main(){
	
	stDate Date;
	system("cl");
	
	cout << "Please Enter Day :";
	cin >> Date.Day;	
	
	cout << "Please Enter Month :";
	cin >> Date.Month;
	cout << "Please Enter Year :";
	cin >> Date.Year;
	
	if(IsValidDate(Date)){
		cout << "Yes , Date Is Valid" << endl;	
	}
	else{
		cout << "No , Date Is Not Valid" << endl;	
		
	}
	
	return 0;
};