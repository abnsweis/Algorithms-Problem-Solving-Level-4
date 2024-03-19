#include <iostream>
#include "../MyLibDate.h"
using namespace std;
using namespace MyLibDate;





// Decrease Date By One Month
stDate DecreaseDateByOneMonth(stDate Date){ 
	
	if(Date.Month == 1){
		Date.Month = 12;
		Date.Day= 31;
		Date.Year--;
	}
	else{
		Date.Month--;
		Date.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
		
	}
	return Date; 
	

	
	
}







int main(){
	
	system("cl");
	
	stDate Date = ReadFullDate();
	
	cout << "Date After :" << endl;
	

	// Decrease Date By One Month
	Date = DecreaseDateByOneMonth(Date);
	cout << "02-Subtracting One Month :" ;	
	cout << Date.Day <<"/" << Date.Month << "/"<<Date.Year << endl;	
	

	return 0;
};