#include <iostream>
using namespace std;

struct stDate{
	short Day;
	short Month;
	short Year;
};

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
stDate ReadFullDate(){
	stDate Date;
	
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	
	return Date;
}
short NumberOfDaysInMonth(short month, short year){
	if (month < 1 || month > 12)
		return 0;

	short arrNumberOdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOdays[month - 1];
}
bool isLastMonthInYear(short Month){
	return Month == 12;
}
bool isLastDayInMonthe(stDate Date){
	
	return NumberOfDaysInMonth(Date.Month,Date.Year) ==  Date.Day;
	
}
// Increase Date By One Day
stDate IncreaseDateByOneDay(stDate Date){
	
	if(isLastDayInMonthe(Date)){
		
		if(isLastMonthInYear(Date.Month)){
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else{
			Date.Day=1;
			Date.Month++;
		}
			
	}else{
		Date.Day++;
	}
	return Date;	
}

// Increase Date By X Day
stDate IncreaseDateByXDay(stDate Date , short Days){
	
	for (int i = 0; i <= Days; i++) {
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}




// Increase Date By One Month
stDate IncreaseDateByOneMonth(stDate Date){ 
	if (Date.Month == 12){ 
		Date.Month = 1; 
		Date.Year++;     
		
	} 
	else{ 
		Date.Month++;     
		
	} //last check day in date should not exceed max days in the current month// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year); 
	if (Date.Day > NumberOfDaysInCurrentMonth){ 
		Date.Day = NumberOfDaysInCurrentMonth;     
		
	} 
	return Date; 
	
}

// Increase Date By X Months
void IncreaseDateByXMonth(stDate &Date,short MonthsNumber){
	
	for (int i = 0; i < MonthsNumber; i++) {
		
		if(Date.Month == 12){
			Date.Month=1;
			Date.Year++;
		}
		else{
			Date = IncreaseDateByOneMonth(Date);
		}
	}
	
	
}

// Increase Date By One Year
void IncreaseDateByOneYear(stDate &Date){
	
	for (int i = 0; i < 12; i++) {
		Date = IncreaseDateByOneMonth(Date);
	}
	
}

// Increase Date By X Years (Faster)
void IncreaseDateByXYears(stDate &Date,short YearsNumber){
	
	Date.Year += YearsNumber;
}
// Increase Date By One Decade 
void IncreaseDateByOneDecade(stDate &Date){
	Date.Year += 10;
}
// Increase Date By X Decade
void IncreaseDateByXDecade(stDate &Date,short DecadeNumber){
	for (int i = 0; i < DecadeNumber; i++) {
		IncreaseDateByOneDecade(Date);
	}
}
// Increase Date By X Decade (Faster)
void IncreaseDateByXDecadeFaster(stDate &Date,short DecadeNumber){
	 Date.Year += DecadeNumber*10;
}
// Increase Date By By One Century
void IncreaseDateByOneCentury(stDate Date){
	IncreaseDateByXDecade(Date,10);
}

// Increase Date By By One Millennium
void IncreaseDateByOnemillennium(stDate Date){
	for (int i = 0; i < 10; i++) {
		IncreaseDateByXDecade(Date,10);
	}
}


int main(){
	
	system("cl");
	
	stDate Date = ReadFullDate();
	
	
	IncreaseDateByOnemillennium(Date);
	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	return 0;
};