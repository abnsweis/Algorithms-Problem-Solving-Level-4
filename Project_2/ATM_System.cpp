#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../MyStringLib.h"

using namespace std;
void ShowATMSMainMenucreen();
void ShowQuickWithdrowScreen();
void ShowNormalWithdrowScreen();
static string ClientsFileName = "../clients.txt";
enum eATMOption {
	eQuickWithdrow=1,
	eNormakWithdrow=2,
	eDeposit=3,
	eCheckBalance=4,
	eLogout = 5
};

struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
stClient  ClientLogin;
// =========== Print ===============
// Print Client Card
void PrintClientCard(stClient client){
	
	cout <<"AccountNumber  : "<< client.AccountNumber << endl ;
	cout <<"PIN Code       : "<< client.PINCode << endl;
	cout <<"Full Name      : "<<  client.FullName << endl ;
	cout <<"Phone Number   : "<< client.Phone << endl ;
	cout <<"Account Balance: $"<< client.AccountBalance << endl;
}

short ReadATMMainOption(){
	short option;
	cout << "Choose What Do You want to Do? [1 to 5]:" ;
	cin >> option;
	return option;
}
short ReadQuickWithDrowOption(){
	short option;
	do{
		cout << "Choose What Do You want to Do? [1 to 9]:" ;
		cin >> option;
		
	}while(option < 1 || option > 9);
	return option;
}
double ReadPositiveAmount(){ 
	double number;
	do{
		
		cout << "Enter a Positive Deposit Amount :";
		cin >> number ;
	}while(number < 0);

	return number;
}
int ReadNormalWithdrowAmount(){
	int Amount;
	do{
	cout << "Enter An Amount Multiple of 5?:" ;
	cin >> Amount;
	}while((Amount % 5)!=0);
			
	return Amount;
}
// Go To ATM Main Menue Screen
void GoBackToATMMainMenu(){
	cout<<"Press Enter To Go Back To ATM Main Menue...." ;
	cin.ignore().get();
	ShowATMSMainMenucreen();
}
// Go Continue
void GoContinue(){
	cout<<"Press Enter To Continue...." ;
	
}

// =========== Convert ===============
stClient ConvertLineDataTostClient(string lineData,string delimiter="#//#"){
	
	
	vector <string> ClientDataLine = MyStringlib::split(lineData,delimiter);
	
	stClient client;
	
	
	client.AccountNumber = ClientDataLine[0];
	client.PINCode = ClientDataLine[1];
	client.FullName = ClientDataLine[2];
	client.Phone= ClientDataLine[3];
	client.AccountBalance= stod(ClientDataLine[4]);
	
	
	
	return client;
	
	
}
string ConvertRecordToOneLine(stClient client,string sperator = "#//#"){
	
	string stClientData ="";
	
	stClientData += client.AccountNumber + sperator;
	stClientData += client.PINCode + sperator;
	stClientData += client.FullName + sperator;
	stClientData += client.Phone + sperator;
	stClientData += to_string(client.AccountBalance) ;
	
	return  stClientData;
	
}

//find client by account number and return true if found and return false if not found
bool FindClientByAcountNumber(string AccountNumber,vector <stClient> vClients,stClient &clientD){
	
	
	for (stClient  &client: vClients) {
		
		if(client.AccountNumber == AccountNumber){
			clientD = client;
			return true;
		}
	
	}
	
	
	return false;
	
}
// Svae clinets to File
vector <stClient> SaveCleintsDataToFile(string FileName,vector <stClient> vClients){
	
	fstream File ;
	string Line;
	File.open(FileName,ios::out);
	
	if(File.is_open()){
		
		for (stClient &C : vClients) {
			
			if(C.MarkForDelete == false){
				Line = ConvertRecordToOneLine(C);
				File << Line << "\n";
			}
			
			
		}
		
	}
	
	return vClients;
} 
vector <stClient> LoadClientsFromFileToVector(string FileName){
	fstream File;
	vector <stClient> vClients;
	File.open(ClientsFileName,ios::in);
	
	if(File.is_open()){
		string 	RecordLine = "";
		
		while(getline(File,RecordLine)){
			vClients.push_back(ConvertLineDataTostClient(RecordLine));
		}
		
		
		File.close();
	}
	return vClients;
}

// Deposit Function
void Deposit(string AccountNumber,int Amount){
	
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;

	char ProcessConfirmation = 'y';
	cout << "Are you sure you want perform is transaction?(y/N):";
	cin >> ProcessConfirmation;
	if(tolower(ProcessConfirmation) == 'y'){
		for (stClient &C : vClients) {
			if(C.AccountNumber == AccountNumber){
				
				C.AccountBalance += Amount; 
			
				SaveCleintsDataToFile(ClientsFileName,vClients);
				
				
				break;
				
			}
		}
	}
	
	
	
	
	
}

short GetWithdrowAmount(short QuickWithdrowAmount){
	switch(QuickWithdrowAmount){
		case 1:
			return 20;
			
		case 2:
			  return 50;
			
		case 3:
			  return 100;
				
		case 4:
			  return 200;
		
		case 5:
			  return 400;
			
		case 6:
			  return 600;
			
		case 7:
			  return 800;
			
		case 8:
			  return 1000;
		default :
			return 0;
	}
}

void PerformQuickWithDrowOption(short Choose){
	
	if(Choose == 9)
		return;
	
	short QuickWithdrowAmount = GetWithdrowAmount(Choose);
	
	if(QuickWithdrowAmount > ClientLogin.AccountBalance){
		cout<<"Amount Exceeds The Balance ,Make Another Choice" <<endl;
		cout << "Press Enter To Continue...." ;
		cin.ignore().get();
		ShowQuickWithdrowScreen();
	}
	Deposit(ClientLogin.AccountNumber,QuickWithdrowAmount*-1);
	ClientLogin.AccountBalance -= QuickWithdrowAmount;
	cout << "\nSuccessfully Withdrow , New Balance Is : $" << ClientLogin.AccountBalance << endl<<endl;
}
void ShowQuickWithdrowScreen(){
	
	system("cl");
	cout << "=========================================" << endl;
	cout << "            Quick WithDrow Screen " << endl;
	cout << "=========================================" << endl;
	cout << "\t [1] 20 \t [2] 50 " << endl;
	cout << "\t [3] 100 \t [4] 200 " << endl;
	cout << "\t [5] 400 \t [6] 600 " << endl;
	cout << "\t [7] 800 \t [8] 1000 " << endl;
	cout << "\t [9] Logout!  " << endl;
	cout << "=========================================" << endl;
	cout << "Your Balance Is :$"<<ClientLogin.AccountBalance << endl;
	PerformQuickWithDrowOption(ReadQuickWithDrowOption());
	
}


void PerformNormalWithDrowOption(){
	int QuickWithdrowAmount = ReadNormalWithdrowAmount();
	
	
	if(QuickWithdrowAmount > ClientLogin.AccountBalance){
		cout<<"Amount Exceeds The Balance ,Make Another Choice" <<endl;
		cout << "Press Enter To Continue...." ;
		cin.ignore().get();
		ShowNormalWithdrowScreen();
		return;
	}
	
	Deposit(ClientLogin.AccountNumber,QuickWithdrowAmount*-1);
	ClientLogin.AccountBalance  -= QuickWithdrowAmount;
	   cout << "\nSuccessfully Withdrow , New Balance Is : $" <<
	ClientLogin.AccountBalance << endl<<endl;
	
}
void ShowNormalWithdrowScreen(){
	
	
	system("cl");
	cout << "=========================================" << endl;
	cout << "          Normal WithDrow Screen " << endl;
	cout << "=========================================" << endl;
	cout << "Your Balance Is :$"<<ClientLogin.AccountBalance << endl;
	
	PerformNormalWithDrowOption();
	
	
}

void PerformDepositMainMenu(){
	double Amount =ReadPositiveAmount();
	Deposit(ClientLogin.AccountNumber,Amount);
	ClientLogin.AccountBalance += Amount;	
}


void ShowDepositScreen(){
	cout << "=====================================" << endl;
	cout << "          Deposit Screen " << endl;
	cout << "=====================================" << endl;
	cout << "Your Balance Is :$"<<ClientLogin.AccountBalance << endl;
	
	PerformDepositMainMenu();
	
	cout << "\nSuccessfully Deposit , New Balance Is : $" <<
	ClientLogin.AccountBalance << endl<<endl;
}

void ShowCheckBalanceScreen(){
	cout << "=====================================" << endl;
	cout << "          Check Balance Screen " << endl;
	cout << "=====================================" << endl;
	cout << "Your Balance Is :$"<<ClientLogin.AccountBalance << endl;
	
	GoBackToATMMainMenu();
}

void PerformATMMainOption(short Choose){
	
	switch(Choose){
		
		case eATMOption::eQuickWithdrow:
			system("cl");
			ShowQuickWithdrowScreen();
			GoBackToATMMainMenu();
			break;
		case eATMOption::eNormakWithdrow:
			system("cl");
			ShowNormalWithdrowScreen();
			GoBackToATMMainMenu();
			break;
			
		case eATMOption::eDeposit:
			system("cl");
			ShowDepositScreen();
			GoBackToATMMainMenu();
			break;
		case eATMOption::eCheckBalance:
			system("cl");
			ShowCheckBalanceScreen();
			GoBackToATMMainMenu();
			break;
		case eATMOption::eLogout:
			system("cl");
			cout << "Prograim End........" << endl;
			
			
	}
}

// Show ATM Sreen 
void ShowATMSMainMenucreen(){
	system("cl");
	cout << "================================" << endl;
	cout << "      ATM Main Menu Screen " << endl;
	cout << "================================" << endl;
	
	cout << "\t[1] Quick Withdrow " << endl;
	cout << "\t[2] Normal Withdrow " << endl;
	cout << "\t[3] Deposit " << endl;
	cout << "\t[4] Check Balance" << endl;
	cout << "\t[5] Logout!" << endl;
	
	PerformATMMainOption((eATMOption)ReadATMMainOption());
}

bool FindClientByAcountNumberAndPINCode(string AccountNumber,string
PINCode,stClient &Client){
	vector <stClient> vClients =LoadClientsFromFileToVector(ClientsFileName);
	
	for (stClient &C : vClients) {
		if(C.AccountNumber == AccountNumber && C.PINCode == PINCode){
			Client = C;	
			return true;
		
		}
	}
	return false;
}

bool LoadClientInfo(string AccountNumber,string PINCode){

	if(FindClientByAcountNumberAndPINCode(AccountNumber,PINCode,ClientLogin)){
		return true;	
	}
	else
		return false;
}
void Login(){
	string AccountNumber , PINCode;
	bool LoginFalid=false;
	do{
		system("cl");
		cout << "================================" << endl;
		cout << "          Login " << endl;
		cout << "================================" << endl;
		if(LoginFalid){
			cout << "Invalid Account Number or PINCode :-( " << endl;
		}
		cout << "Enter Account Number?" ;
		cin >> AccountNumber;		
	
		cout << "Enter PIN Code?" ;
		cin >> PINCode;
		
		LoginFalid = !LoadClientInfo(AccountNumber,PINCode);
	
	}while(LoginFalid);
	
	ShowATMSMainMenucreen();
}


int main(){
	Login();
	return 0;
};