#include <iostream>
#include <string>
#include <iomanip>
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
	}while(Month > 12 || Month < 0);
	
	return Month;
}

string GetDayNameByIndex(short index){
	string DaysName[7] = {"Sunday","Monday","Tuesday","Wednesday"
	,"Thursday","Friday","Saturday"};
	return DaysName[index];
}

bool isLeapYear(short year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month,short Year){
	
	if(Month < 0 || Month > 12){
		return 0;
	};
	
	short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	
	
	return (Month == 2) ? (isLeapYear(Year) ? 29:28 ) : NumberOfDays[Month -1];
}






short DayOfWeekOrder(short year , short Month,short day){
	short a = (14 - Month )/ 12 ;
	short y = year - a ;
	short m = Month + (12*a) - 2;
	
	short DayOfWeek = (day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12))%7;
	return DayOfWeek;
	
} 







string GetMonthName(short Month){
	string ArrMonthsNames[13]={"","Jan","Feb","March","Apr","May","Jun","Jul","Aug","Sep","Oct",
		"Nov","Dec",
	} ;
	
	
	return ArrMonthsNames[Month];
}



void PrintMonthCalender(short Month,short Year){
	
	short current = DayOfWeekOrder(Year,Month,1); 
	short NumberOfDays ;
	NumberOfDays = NumberOfDaysInAMonth(Month,Year);
	cout << "----------- "<<GetMonthName(Month)<<" -----------" << endl;

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	
	// int i;
	// for (i = 0; i < current ; i++) {
	// 	printf("    ");
	// }
	
	// for (int j = 1; j < NumberOfDays; j++) {
	// 	printf("%4d",j);
	// 	if(++i == 7){
	// 		i =0;
	// 		printf("\n");
	// 	}
	// }
	
	
	
	
	
	int i; 
	for (i = 0; i < current; i++){         
		printf("     "); 
	}
	for (int j = 1; j <= NumberOfDays; j++){         
		printf("%5d", j); 
		if (++i == 7){
			i = 0;             
			printf("\n");         
			
		}     
		
	}
	
	
	
	
	
	cout << "\n---------------------------" << endl;
	
	
}


int main(){
	system("cl");
	
	short Year = ReadYear();
	short Month = ReadMonth();
	
	PrintMonthCalender(Month,Year);
	return 0;
};