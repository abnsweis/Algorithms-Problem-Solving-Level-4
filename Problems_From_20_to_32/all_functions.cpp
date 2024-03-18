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
	
	for (int i = 0; i < Days; i++) {
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
// Increase Date By One Week 
stDate IncreaseDateByOneWeek(stDate Date){
	
	for (int i = 0; i < 7; i++) {
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
	
}
// Increase Date By X Week
stDate IncreaseDateByXWeek(stDate Date , short weeksNumber){
	
	for (int i = 0; i < weeksNumber; i++) {
		Date = IncreaseDateByOneWeek(Date);
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
stDate IncreaseDateByXMonths(stDate Date,short MonthsNumber){
	
	for (int i = 0; i < MonthsNumber; i++) {
		
		Date = IncreaseDateByOneMonth(Date);
	}
	
	return Date;
}


// Increase Date By One Year
stDate IncreaseDateByOneYear(stDate Date){
	
	Date.Year++;
	return Date;
}

// Increase Date By X Years
stDate IncreaseDateByXYears(stDate Date,short YearsNumber){
	for (int i = 0; i < YearsNumber; i++) {
		Date = IncreaseDateByOneYear(Date);
	}
	
	return Date;
}


// Increase Date By X Years (Faster)
stDate IncreaseDateByXYearsFaster(stDate Date,short YearsNumber){
	Date.Year += YearsNumber;
	return Date;
}

// Increase Date By One Decade 
stDate IncreaseDateByOneDecade(stDate Date){
	Date.Year += 10;
	return Date;
}
// Increase Date By X Decade
stDate IncreaseDateByXDecade(stDate Date,short DecadeNumber){
	for (int i = 0; i < DecadeNumber *10; i++) {
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

// Increase Date By X Decade (Faster)
stDate IncreaseDateByXDecadeFaster(stDate &Date,short DecadeNumber){
	 Date.Year += DecadeNumber*10;
	 return Date;
}

// Increase Date By By One Century
stDate IncreaseDateByOneCentury(stDate &Date){
	Date.Year +=100;
	return Date;
}

// Increase Date By By One Millennium
stDate IncreaseDateByOnemillennium(stDate &Date){
	Date.Year +=1000;
	return Date;
}

int main(){
	
	system("cl");
	
	stDate Date = ReadFullDate();
	
	cout << "Date After :" << endl;
	
	// Increase Date By  One Day
	Date = IncreaseDateByOneDay(Date);
	cout << "01-Adding One Day  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Increase Date By X Day
	Date = IncreaseDateByXDay(Date,10);
	cout << "02-Adding 10 Day  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By One Week 
	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding One Week  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Increase Date By X Week 
	Date = IncreaseDateByXWeek(Date,10);
	cout << "04-Adding 10 Week  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By One Month 
	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding One Month  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Increase Date By X Months 
	Date = IncreaseDateByXMonths(Date,5);
	cout << "06-Adding 5 Months  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Increase Date By One Year
	Date =  IncreaseDateByOneYear(Date);
	cout << "07-Adding One Year  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By 10 Year
	Date = IncreaseDateByXYears(Date,10);
	cout << "08-Adding 10 Year  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By 11 Year (Faster)
	Date = IncreaseDateByXYearsFaster(Date,10);
	cout << "09-Adding 10  Year  (Faster):" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By One Decade
	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding One Decade " ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By X Decade
	Date = IncreaseDateByXDecade(Date,10);
	cout << "11-Adding 10 Decade " ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl
	;
	// Increase Date By X Decade Faster
	Date = IncreaseDateByXDecadeFaster(Date,10);
	cout << "12-Adding 10 Decade (Faster)" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
;
	// Increase Date By By One Century
	Date = IncreaseDateByOneCentury(Date);
	cout << "13-Adding One Century " ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Increase Date By One Millennium
	Date = IncreaseDateByOnemillennium(Date);
	cout << "13-Adding One Century " ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;



	return 0;
};