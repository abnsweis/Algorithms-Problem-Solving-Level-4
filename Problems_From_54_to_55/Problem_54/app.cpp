#include <iostream>
#include "../../MyLibDate.h"
using namespace std;
using namespace MyLibDate;




short CalculateVacationDays(stDate Date1, stDate Date2) {

	short VacationDays = 0;

	while(DateOneisLess(Date1, Date2)) {
		if(isBusinessDay(Date1)) {
			VacationDays++;
		}
		Date1 = IncreaseDateOneDay(Date1);
	}

	return VacationDays;
}


int main() {
	system("cl");
	cout << "Read Date 1" << endl;
	stDate Date1 = ReadFullDate();
	cout << "\nRead Date 2" << endl;
	stDate Date2 = ReadFullDate();
	cout << "\nVacation From " << GetDayNameByIndex(DayOfWeekOrder(Date1));
	cout << "\t" <<Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
	cout << "Vacation To " << GetDayNameByIndex(DayOfWeekOrder(Date2));
	cout <<"\t" << Date2.Day << "/"<< Date2.Month << "/" << Date2.Year << endl;
	cout << "\nVacation Days Is " << CalculateVacationDays(Date1, Date2)<< endl;
	return 0;
};