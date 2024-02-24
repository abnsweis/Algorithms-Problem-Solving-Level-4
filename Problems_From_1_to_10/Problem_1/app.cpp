#include <iostream>
#include <string>
using namespace std;


int ReadNumber(string massage){ 
	int number;

	cout << massage ; 
	cin >> number ;
	
	return number;
}

string NumberToText(int number){
	
	if(number ==0){
		return "";
	}
	
	if(number >= 1 && number <=19 ){
		
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr[number] + " ";
	}
	
	if(number >= 20 && number <= 99){
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		
		return arr[number/10] + " " + NumberToText(number % 10);
		
	}
	
	if(number >=100 && number <= 199){
		return "One Hundred " + NumberToText(number%100);
	}
	
	if(number >=200 && number <= 999){
		return NumberToText(number/100) + "Hundreds " + NumberToText(number%100);
	}
	
	if(number >=1000 && number <=1999){
		return "One Thousand " + NumberToText(number%1000);
	}
	
	if(number >=2000 && number <=999999){
		return NumberToText(number/1000) + "Thousands "+ NumberToText(number%1000);
	}
	
	if(number >=1000000 &&number<=1999999){
		return "One Million " + NumberToText(number%1000000);	
	}
	
	if(number >=2000000 && number <=999999999){
		return NumberToText(number/1000000) + "Millions " + NumberToText(number%1000000);
	}
	
	if(number >=1000000000 && number <=1999999999){
		return "One Billion " + NumberToText(number%1000000000);
	}
	else{
		return NumberToText(number/1000000000) + " Billions "
		+NumberToText(number%1000000000);
	}						   
	
}


int main(){
	system("cl");
	int number = ReadNumber("Please Entet Number :");
	
	cout << NumberToText(number) << endl;
	
	return 0;
};




