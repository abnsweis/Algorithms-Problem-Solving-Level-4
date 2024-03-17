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

struct stDate{
	short Day;
	short Month;
	short Year;
};

bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



short NumberOfDaysInMonth(short month, short year){
	if (month < 1 || month > 12)
		return 0;

	short arrNumberOdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOdays[month - 1];
}

short NumberOfDaysRemainingInYear(short days , short Month , short year){

	short TotalDays = 0;
	
	for (int i = 1; i <= Month  - 1 ; i++) {
		TotalDays += NumberOfDaysInMonth(i,year);
	}
	TotalDays += days;
	return TotalDays  ;
}






	
	
	
stDate ConvertNumberOfDaysToDate(short DateOrderInYear, short Year) { 
	stDate Date; 
	Date.Year = Year;     
	
	short RemainingDays = DateOrderInYear; 
	
	short MonthDays = 0;     
	Date.Month = 1; 
	
	
	while (true){ 
		MonthDays = NumberOfDaysInMonth(Date.Month, Year); 
		if (RemainingDays > MonthDays){   
			RemainingDays -= MonthDays;             
			Date.Month++;         
			
		} 
		else{   
			Date.Day = RemainingDays; 
			break;         
			
		}     
		
	} 
	
	return Date; 
	
} 


int main(){
	system("cl");
	
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	
	short TotalDays = NumberOfDaysRemainingInYear(Day,Month,Year);
	cout << "Number of Days from the begining of the year is "  ;
	cout <<TotalDays<<endl;
	stDate Date = ConvertNumberOfDaysToDate(TotalDays,Year);
	
	cout << "Date for [ "<< TotalDays << " ] is ";
	cout << Date.Day<<"/";
	cout << Date.Month<<"/";
	cout <<Date.Year<< "/"<<endl;
	
	return 0;
};


