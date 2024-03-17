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









stDate ReadFullDate(){
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	
	return Date;
}


bool Date1EqualDate2(stDate Date1 ,stDate Date2){
	

	return (Date1.Year == Date2.Year ) ? ( Date1.Month == Date2.Month ? (Date1.Day
	== Date2.Day ? true : false):false ) : false ; 
	
	
	
} 


int main(){
	system("cl");
	cout << "Read Date 1 :"  << endl;
	stDate Date1 = ReadFullDate();
	cout << "\nRead Date 2 :"  << endl;
	stDate Date2 = ReadFullDate();
	
	

	
	if(Date1EqualDate2(Date1,Date2)){
		cout << "Yes , Date1 is Equal Then Date2 " << endl;	
	}else{
		cout << "No , Date1 is Not Equal Then Date2 " << endl;	
		
	}
		
	
	
	
	
	
	
	return 0;
};


i