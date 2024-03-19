#include <iostream>
#include "../MyLibDate.h"
using namespace std;
using namespace MyLibDate;

// Decrease Date By One Day
stDate DecreaseDateByOneDay(stDate Date){
	
	if(Date.Day == 1){
		
		if(Date.Month == 1){
			Date.Day = 31;
			Date.Month=12;
			Date.Year--;
			
		}
		else{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
		}
		
	}else{
		Date.Day--;
	}
	
	return Date;
}

// Decrease Date By X Day
stDate DecreaseDateByXDay(stDate Date , short Days){
	
	for (short i = 0; i < Days; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

// Decrease Date By One Week 
stDate DecreaseDateByOneWeek(stDate Date){
	
	for (short i = 0; i < 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
	
}

// Decrease Date By X Week
stDate DecreaseDateByXWeeks(stDate Date , short weeks){
	
	for (short i = 0; i < weeks; i++) {
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;	
}




// Decrease Date By One Month
stDate DecreaseDateByOneMonth(stDate Date){ 
	
	if(Date.Month == 1){
		Date.Month = 12;
		Date.Year--;
	}
	else{
		Date.Month--;
	}
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	
	if(Date.Day != NumberOfDaysInCurrentMonth){
		
		Date.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
	}
	
	return Date; 
	

	
	
}

// Decrease Date By X Months
stDate DecreaseDateByXMonths(stDate Date,short MonthsNumber){
	
	for (int i = 0; i < MonthsNumber; i++) {
		
		Date = DecreaseDateByOneMonth(Date);
	}
	
	return Date;
}


// Decrease Date By One Year
stDate DecreaseDateByOneYear(stDate Date){
	
	for (int i = 0; i < 12; i++) {
		Date = DecreaseDateByOneMonth(Date);
	}
	
	return Date;
}

// Decrease Date By X Years
stDate DecreaseDateByXYears(stDate Date,short Years){
	for (int i = 0; i < Years; i++) {
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

// Decrease Date By X Years (Faster)
stDate DecreaseDateByXYearsFaster(stDate Date,short Years){
	Date.Year -= Years;
	return Date;
}

// Decrease Date By One Decade 
stDate DecreaseDateByOneDecade(stDate Date){
	Date.Year -= 10 ;
	return Date;
}

// Increase Date By X Decade
stDate DecreaseDateByXDecade(stDate Date,short Decade){
	for (int i = 0; i < 10 * Decade; i++) {
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

// Decrease Date By X Decade (Faster)
stDate DecreaseDateByXDecadeFaster(stDate &Date,short DecadeNumber){
	 Date.Year -= DecadeNumber*10;
	 return Date;
}

// Decrease Date By By One Century
stDate DecreaseDateByOneCentury(stDate &Date){
	Date.Year -=100;
	return Date;
}

// Decrease Date By By One Millennium
stDate DecreaseDateByOnemillennium(stDate &Date){
	Date.Year -=1000;
	return Date;
}

int main(){
	
	system("cl");
	
	stDate Date = ReadFullDate();
	
	cout << "Date After :" << endl;
	
	// Decrease Date By One Day
	Date = DecreaseDateByOneDay(Date);
	cout << "01-Subtracting One Day  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Decrease Date By X Days
	Date = DecreaseDateByXDay(Date,10);
	cout << "02-Subtracting 10 Days  :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Decrease Date By One Week
	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting One Week :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	

	// Decrease Date By X Weeks
	Date = DecreaseDateByXWeeks(Date,10);
	cout << "04-Subtracting 10 Weeks :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	

	// Decrease Date By One Month
	Date = DecreaseDateByOneMonth(Date);
	cout << "02-Subtracting One Month :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Decrease Date By X Month
	Date = DecreaseDateByXMonths(Date,5);
	cout << "05-Subtracting 5 Month :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	// Decrease Date By One Year
	Date = DecreaseDateByOneYear(Date);
	cout << "06-Subtracting One Year :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	// Decrease Date By X Years
	Date = DecreaseDateByXYears(Date,10);
	cout << "07-Subtracting 10 Year :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	

	//Decrease Date By X Years Faster
	Date = DecreaseDateByXYearsFaster(Date,10);
	cout << "08-Subtracting 10 Year Faster :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	//Decrease Date By One Decade
	Date = DecreaseDateByOneDecade(Date);
	cout << "09-Subtracting One Decade :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;
	
	//Decrease Date By X Decade
	Date = DecreaseDateByXDecade(Date,10);
	cout << "10-Subtracting 10 Decade :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	//Decrease Date By X Decade (Faster)
	Date = DecreaseDateByXDecadeFaster(Date,10);
	cout << "10-Subtracting 10 Decade Faster:" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	
	//Decrease Date By X Decade (Faster)
	Date = DecreaseDateByOneCentury(Date);
	cout << "10-Subtracting One Century :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	

	//Decrease Date By X Decade (Faster)
	Date = DecreaseDateByOnemillennium(Date);
	cout << "10-Subtracting One Millennium :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	


	cout << "================\n\n" << endl;
	stDate Date2 = ReadFullDate();
	
	Date2 = DecreaseDateByOneYear(Date2);
	cout << Date2.Day <<"/" << Date2.Month << "/"<<Date2.Year << endl;	
		
	

	return 0;
};