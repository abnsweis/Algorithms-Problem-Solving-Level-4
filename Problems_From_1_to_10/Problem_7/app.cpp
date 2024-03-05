#include <iostream>
#include <string>
using namespace std;

short ReadYear(){ 
	int Year;

	cout << "Please Enter Year " ; 
	cin >> Year ;
	
	return Year;
}
short ReadMonth(){ 
	int Month;

	do{
	cout << "Please Enter Month " ; 
	cin >> Month ;
	}while(Month > 12 || Month < 0);
	
	return Month;
}
short ReadDay(){ 
	int Day;

	do{
	cout << "Please Enter Day " ; 
	cin >> Day ;
	}while(Day > 31 || Day < 0);
	
	return Day;
}

short DayOfWeekOrder(short year , short Month,short day){
	short a = (14 - Month )/ 12 ;
	short y = year - a ;
	short m = Month + (12*a) - 2;
	
	short DayOfWeek = (day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12))%7;
	return DayOfWeek;
	
} 


string GetDayNameByIndex(short index){
	string DaysName[7] = {"Sunday","Monday","Tuesday","Wednesday"
	,"Thursday","Friday","Saturday"};
	return DaysName[index];
}

int main(){
	system("cl");
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
	
	cout << Year<<"/"<<Month<<"/"<<Day<< endl;
	cout << DayOfWeekOrder(Year,Month,Day) << endl;
	cout << GetDayNameByIndex(DayOfWeekOrder(Year,Month,Day)) << endl;
	return 0;
};