#include <iostream>
#include <string>
using namespace std;

short ReadYear(){ 
	int Year;

	cout << "Please Enter Year :" ; 
	cin >> Year ;
	
	return Year;
}
short ReadMonth(){ 
	int Month;

	do{
	cout << "Please Enter Month :" ; 
	cin >> Month ;
	}while(Month > 12 || Month <= 0);
	
	return Month;
}
short ReadDay(){ 
	int Day;

	do{
	cout << "Please Enter Day :" ; 
	cin >> Day ;
	}while(Day > 31 || Day <= 0);
	
	return Day;
}


bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

struct stDate{
	short Day;
	short Month;
	short Year;
};






short NumberOfDaysInMonth(short month, short year){
	if (month < 1 || month > 12)
		return 0;

	short arrNumberOdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOdays[month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short days , short Month , short year){

	short TotalDays = 0;
	
	for (int i = 1; i <= Month  - 1 ; i++) {
		TotalDays += NumberOfDaysInMonth(i,year);
	}
	TotalDays += days;
	return TotalDays  ;
}



stDate ReadFullDate(){
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	
	return Date;
}


bool DateOneisLess(stDate Date1 ,stDate Date2){
	

return(Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ?
(Date1.Month < Date2.Month ) : Date1.Day < Date2.Day ? true : false;

}

int main(){
	system("cl");
	cout << "Read Date 1 :"  << endl;
	stDate Date1 = ReadFullDate();
	cout << "\nRead Date 2 :"  << endl;
	stDate Date2 = ReadFullDate();
	
	
	// Date.Day = ReadDay();
	// Date.Month = ReadMonth();
	
	// Date.Year = ReadYear();	
	
	
	
	
	if(DateOneisLess(Date1,Date2)){
		cout << "Yeas , Date1 is Less Then Date2 " << endl;	
	}else{
		cout << "No , Date1 is Not Less Then Date2 " << endl;	
		
	}
		
	
	
	
	
	
	
	return 0;
};


