#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../MyStringLib.h"

struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};


using namespace std;
void ShowMainMenueScreen();
void ManageUsersScreen();
void ShowTransacionsMainMenueScreen();
void Login();

struct stUser{
	string Username;
	string Password; 
	bool MarkForDelete=false;
	int Permissions;
};
stUser UserLogin;
static string UsersFileName = "./Users.txt";
static string ClientsFileName = "../clients.txt";
enum enMainMenuOptions {
	eShowAllClients=1,
	eAddNewClients=2,
	eDeleteClients=3,
	eUpdateClient=4,
	eTransactions=5,
	eFindClient=6,
	eManageUsers=7,
	eLogout=8
};


enum enTransacionsOpations{
	eDeposit=1,
	eWithdrow=2,
	eTotalBalanses=3,
	eMainMenueScreen=4
};


enum enUserMenuOptions {
	ListUsers=1,
	AddUser=2,
	DeleteUser=3,
	UpdateUser=4,
	FindUser=5,
	MainMenue=6
};


enum enPermissions {
	Full=-1,
	ShowClientsList=1,
	AddCliens=2,
	DeleteClients=4,
	UpdateClients=8,
	FindClients = 16,
	Transacions=32,
	ManageUsers=64
};


// Read MainMenue Opation
short ReadMainMenueOpation(){

	short choice;
	cout << "Choose What Do You want to Do? [1 to 6]:" ;
	
	cin >> choice;
	
	return choice;
	
}

// Read Client Account Number From screen
string ReadAccountNumber(string msg){
	
	string AccountNumber;
	cout << msg ;
	cin >> AccountNumber;
	
	
	return AccountNumber;
	
}

short ReadTransactionsOpation(){

	short choice;
	cout << "Choose What Do You want to Do? [1 to 4]:" ;
	cin >> choice;
	
	return choice;
	
};

short ReadUsersMenueOptions(){
	
	short option;
	cout << "Choose What Do You want to Do? [1 to 6]:" ;
	cin >> option;
	
	return option;
}



// =========== Start Permissions ==========
void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void AccessDenidScreen(){
	system("cl");
	cout<<"============================================"<<endl;
	cout<<"          Access Denid Screen" << endl;
	cout<<"============================================"<<endl;
}

bool CheckAccessPermission(enPermissions Permission){
	if(UserLogin.Permissions == enPermissions::Full){
		return true;
	}
	
	if((Permission & UserLogin.Permissions) == Permission){
		return true;
	}else{
		return false;
	}
}
int ReadPermissionsToSet(){
	
	int Permissions = 0;
	char Answer='n';
	
	cout << "Do you want to grant this user full permissions on the system?(y/N)" ;
	cin >> Answer;
	
	if(toupper(Answer)=='Y'){
		return -1;
	}
	
	
	cout << "[1] Show All Clients ? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::ShowClientsList;
	}
	
	
	cout << "[2] Add New Clients? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::AddCliens;
	}
	
	cout << "[3] Delete Clients? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::DeleteClients;
	}
	
	cout << "[4] Update Clients? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::UpdateClients;
	}
	
	cout << "[5] Find Clients? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::FindClients;
	}
	
	
	cout << "[6] Transacions? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::Transacions;
	}
	
	cout << "[7] Manage Users? (y/N)";
	cin >> Answer;
	if(toupper(Answer) == 'Y'){  
		Permissions+=enPermissions::ManageUsers;
	}
	
	return Permissions;	
}

// =========== End Permissions ==========

//Add Data Line To File 
void AddDataLineToFile(string FileName, string stDataLine) { 
	fstream MyFile;    
	MyFile.open(FileName, ios::out | ios::app); 
	
	if (MyFile.is_open())     {         
		MyFile << stDataLine << endl;         
	} 
	MyFile.close();     
	
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

// ============ Convert  -=============
stUser ConvetUserLineStringTostUser(string Line){
	stUser User;
	vector <string> UserInfo = MyStringlib::split(Line,"#//#");
	
	User.Username = UserInfo[0];
	User.Password = UserInfo[1];
	User.Permissions = stoi(UserInfo[2]);
	
	
	return User;
}
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
string ConvertRecordToOneLine(stUser User,string sperator = "#//#"){
	
	string stUserData ="";
	
	stUserData += User.Username + sperator;
	stUserData += User.Password + sperator;
	stUserData += to_string(User.Permissions) ;
	
	return  stUserData;
	
}
string ConverStUserToOneLineString(stUser User,string delimiter="#//#"){
	
	string line ="";
	
	
	line+=User.Username + delimiter;
	line+=User.Password + delimiter;
	line+=to_string(User.Permissions) ;
	
	
	return line;
	
}


// ============ Load  -=============

vector <stUser> SaveUsersToFile(string File,vector <stUser> vUsers){
	
	fstream FileUsers;
	
	FileUsers.open(File,ios::out);
	
	
	if(FileUsers.is_open()){
		string line;
		for (stUser &user : vUsers) {
			if(user.MarkForDelete == false){
				
				line = ConverStUserToOneLineString(user);
				FileUsers << line<<endl;
			}
		}
			
	}
	return  vUsers;
}

vector <stUser> LoadUserFromFileToVector(string FileName){
	fstream UsersFile ;
	
	vector <stUser> vUsers ;
	
	UsersFile.open(FileName,ios::in);
	if(UsersFile.is_open()){
		string line = "";
		while(getline(UsersFile,line)){
			vUsers.push_back(ConvetUserLineStringTostUser(line));
		}
		
		UsersFile.close();
	}
	
	return vUsers;
}
vector <stClient> LoadClientsFromFileToVector(string FileName){
	fstream File;
	vector <stClient> vClients;
	File.open(FileName,ios::in);
	
	
	if(File.is_open()){
		string 	RecordLine = "";
		
		while(getline(File,RecordLine)){
			vClients.push_back(ConvertLineDataTostClient(RecordLine));
		}
		
		
		File.close();
	}
	return vClients;
}

bool ClientExistByAccountNumber(string AccountNumber){
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;
	
	for (stClient &C : vClients) {
		if(C.AccountNumber == AccountNumber){
			return true;	
		}	
	}
	return false;
}
// Read New  Client 
stClient ReadNewClient(){
	stClient client;

	cout << "Enter Account Number : " ;
	getline(cin >> ws, client.AccountNumber);
	
	while(ClientExistByAccountNumber(client.AccountNumber)){
		cout << "The account number is already in use.\nPlease enter another number :" ;
		getline(cin >> ws, client.AccountNumber);
		
	}
	
	cout << "Enter Account PIN Code :" ;
	getline(cin,client.PINCode);
	
	cout << "Enter Account Full Name :" ;
	getline(cin,client.FullName);
	
	cout << "Enter Phone Number :";
	getline(cin,client.Phone);
	
	cout << "Enter Account Balance :";
	cin >> client.AccountBalance;
	
	return client;
	
}
// ============ Print -=============

// Print Client Record 
void PrintClientRecord(stClient client){
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber ;
	cout <<"| "<< setw(10)  << client.PINCode ;
	cout <<"| "<< setw(20)  << client.FullName ;
	cout <<"| "<< setw(15)  << client.Phone ;
	cout <<"| $"<< setw(10)  << client.AccountBalance << "|";
	cout  << endl;
}
// Print Client Card
void PrintClientCard(stClient client){
	
	cout <<"AccountNumber  : "<< client.AccountNumber << endl ;
	cout <<"PIN Code       : "<< client.PINCode << endl;
	cout <<"Full Name      : "<<  client.FullName << endl ;
	cout <<"Phone Number   : "<< client.Phone << endl ;
	cout <<"Account Balance: $"<< client.AccountBalance << endl;
}
// Print Client Balance 
void PrintClientBalance(stClient client){
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber ;
	cout <<"| "<< setw(20)  << client.FullName ;
	cout <<"| $"<< setw(10)  << client.AccountBalance << "|";
	cout  << endl;
}
void PrintUserInfo(stUser User){
	
	cout << "Username :"<<User.Username << endl;
	cout << "Password :"<<User.Password<< endl;
	cout << "Permissions:"<<User.Permissions<< endl;
	
}
// Print User Record in Users List Screen
void PrintUserRecord(stUser user){
	cout <<"| "<<left <<setw(13) << user.Username;
	cout <<"| "<<left <<setw(13) << user.Password;
	cout <<"| "<<left <<setw(12) << user.Permissions <<"|"<<endl;
}



bool FindUserByUserNameAndPassword(string username,string password,stUser &User){
	
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	
	
		
	for (stUser &user : vUsers) {
		
		if(user.Username == username && user.Password == password){
			User = user;	
			return true;
		}
	}		
	
	return false;
}

bool LoadUserInfo(string Username,string password){
	if(FindUserByUserNameAndPassword(Username,password,UserLogin)){
		return	true;
	}
	else{
		return false;
	}
}

// Go To Main Menue Screen
void GoBackToMainMenu(){
	cout<<"Press Enter to go back to main menu...." ;
	cin.ignore().get();
	ShowMainMenueScreen();
}
// Go To Transacions Screen
void GoToTransactionsScreen(){
	cout<<"Press Enter to go back to Transacions main menu...." ;
	cin.ignore().get();
	ShowTransacionsMainMenueScreen();
	
};
// Go To Users Manage Screen
void GoToUsersManageScreen(){
	cout<<"Press Enter to go back to main menu...." ;
	cin.ignore().get();
	ManageUsersScreen();
}


// ======== Show Clients Start ======
// Show All Client 
void ShowAllClientsScreen(){
	
	if(!CheckAccessPermission(enPermissions::ShowClientsList)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}
	
	
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;
	cout << setw(50) << "Clients List (" << vClients.size()<<")";
	cout << "\n==============================================";     
	cout << "===================================" << endl;     
	cout << "| " << left << setw(15) << "Accout Number";     
	cout << "| " << left << setw(10) << "Pin Code";     
	cout << "| " << left << setw(20) << "Client Name";     
	cout << "| " << left << setw(15) << "Phone";     
	cout << "| " << left << setw(10) << "Balance" << "|";     
	cout << "\n==============================================";     
	cout << "===================================" << endl;  

	
	for (stClient  &client : vClients) {
		PrintClientRecord(client);
	}
	cout << "==============================================";     
	cout << "===================================" << endl;  
	
	
}
// ======== Show Clients End ======



// ======== Add New Clients Start ======

// Add New Client
void AddNewClient(){
	
	stClient NewClient = ReadNewClient();
	
	AddDataLineToFile(ClientsFileName,ConvertRecordToOneLine(NewClient));
	
}


// Add New Client's
void AddNewClients(){
	char AddMoreClients = 'N';
	do{
		AddNewClient();
		cout << "Client Added Successfuly, Do Want To Add More Clients ?:";
		cin >> AddMoreClients;
		
	}while(toupper(AddMoreClients) == 'Y');
	
}// Show Add New Clients  Screen
void ShowAddNewClientsScreen(){
	
	if(!CheckAccessPermission(enPermissions::AddCliens)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}
	
	cout << "========================================" << endl;
	cout << "         Add Clients Screen           " << endl;
	cout << "========================================" << endl;
	
	AddNewClients();
	
}
// ======== Add New Clients end ======


// ======== Delete Clients Start ======


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
bool MarkClientForDeleteByAccountNumber(string AccountNumber , vector <stClient>
&clients){
	
	for (stClient  &client : clients) {
		
		if(client.AccountNumber == AccountNumber){
				client.MarkForDelete = true;
				return true;
		}
		
	}
	return false;
}
bool DeleteClientByAccountNumber(string AccountNumber,vector <stClient> &vClients){
	cout << AccountNumber << endl;
	stClient client ;
	char Answer = 'n';
	
	
	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		PrintClientCard(client);	
		
		cout << "\nAre you sure you want delete this client? y/n : " ;
		cin >> Answer;
		
		
		if(toupper(Answer) == 'Y'){
			
			MarkClientForDeleteByAccountNumber(AccountNumber,vClients);
			
			SaveCleintsDataToFile(ClientsFileName,vClients);
			
			vClients = LoadClientsFromFileToVector(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		} 

	}
	else{
			cout << "\nClient with Account Number (" << AccountNumber<< ") is NotFound!"<<endl;
			return false;
		}
	return  false;
	
}


void ShowDeleteClientsScreen(){

	if(!CheckAccessPermission(enPermissions::DeleteClients)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}

	cout << "========================================" << endl;
	cout << "          Delete Clients Screen          " << endl;
	cout << "========================================" << endl;
	
	vector <stClient> vClients= LoadClientsFromFileToVector(ClientsFileName);
	
	
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number to Delete:");
	
	DeleteClientByAccountNumber(AccountNumber,vClients);


}
// ======== Delete Clients End ======


// ======== Update Clients Start ======
stClient ChangeClientRecord(string AccountNumber){
	
	stClient client;
	
	client.AccountNumber = AccountNumber;
	// Updata PIN Code
	cout << "Please Enter PIN Code :" ;
	// getline(cin,client.PINCode);
	getline(cin>> ws,client.PINCode);
	// Updata Full Name
	cout << "Please Enter Full Name :" ;
	getline(cin , client.FullName);
	
	// Updata Phone Number
	cout << "Please Enter Phone Number :" ;
	getline(cin , client.Phone);
	
	// Updata Account Balance
	cout << "Please Enter Account Balancec :" ;
	cin >> client.AccountBalance;
	
	return client;	

	
}
bool UpdataClientByAccountNumber(string AccountNumber,vector<stClient>&vClients){
	char Answer = 'n';
	stClient client;
	
	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		
		PrintClientCard(client);
		cout << "Are you sure you want to update this client?:(y/N)";
		cin >> Answer;
		if(tolower(Answer) == 'y'){
			
			
			for (stClient &C : vClients) {
				if(C.AccountNumber == client.AccountNumber){
					C = ChangeClientRecord(AccountNumber);
					
					cout << "Client Updated Successfully :-)" << endl;
					
					break;
				 }
			}
			
			SaveCleintsDataToFile(ClientsFileName,vClients);
		}
		
	}else{
		cout << "Client With Account Number ("<<AccountNumber<<")is Not Found!:-(" << endl;
		return false;
	}
	
	
	return false;
}

void ShowUpDateClientScreen(){
	

	if(!CheckAccessPermission(enPermissions::UpdateClients)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}

	cout << "========================================" << endl;
	cout << "          Update Client Screen          " << endl;
	cout << "========================================" << endl;
	
	vector <stClient> vClients= LoadClientsFromFileToVector(ClientsFileName);
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number to Update :");
	UpdataClientByAccountNumber(AccountNumber,vClients);
	

}
// ======== Update Clients End ======

// ======== Start Transacions ======

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
				cout << "New Balance is $"<< C.AccountBalance << endl;
				break;
				
			}
		}
	}
	
	
	
	
	
}



// Deposit Screen
void ShowDepositScreen(){
	cout << "======================================" << endl;
	cout << "            Deposit Screen           " << endl;
	cout << "======================================" << endl;
	
	string AccountNumber = ReadAccountNumber("Please Enter Account Number :");
	int amount = 0; 
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;
	stClient client;

	while(!FindClientByAcountNumber(AccountNumber,vClients,client)){
		cout << "\nClient With Account Number [ "<< AccountNumber << " ] is NotFound :-(" << endl;
		AccountNumber = ReadAccountNumber("Please Enter Another Account Number :");
	}
	
	PrintClientCard(client);
	
	cout << "Please Enter Deposit Amount :";
	cin >> amount;
	Deposit(AccountNumber,amount);
} 

// Withdrow Screen
void ShowWithdrowScreen(){
	cout << "======================================" << endl;
	cout << "            Withdrow Screen           " << endl;
	cout << "======================================" << endl;
	string AccountNumber = ReadAccountNumber("Please Enter Account Number :");
		int amount = 0; 
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;
	stClient client;

	while(!FindClientByAcountNumber(AccountNumber,vClients,client)){
		cout << "\nClient With Account Number [ "<< AccountNumber << " ] is NotFound :-(" << endl;
		AccountNumber = ReadAccountNumber("Please Enter Another Account Number :");
	}
	
	PrintClientCard(client);
	cout << "Please Enter Withdrow Amount :";
	cin >> amount;
	
	while(client.AccountBalance < amount){
		cout << "amount exceeds the balance,you can withdrow to up $" <<
		client.AccountBalance<<endl;
		cout << "Please Enter Withdrow Amount :";
		cin >> amount;
	}
	Deposit(AccountNumber,amount*-1);
}

//Show Total Balances Screen
void ShowTotalBalancesScreen(){
	system("cl");
	vector <stClient> vClients = LoadClientsFromFileToVector(ClientsFileName) ;
	cout << "\n====================================================="<<endl;      
	cout << "                Balances List (" << vClients.size()<<") Clients " ;
	cout << "\n====================================================="<<endl;      
	cout << "| " << left << setw(15) << "Accout Number";   
	cout << "| " << left << setw(20) << "Client Name";     
	cout << "| " << left << setw(10) << "Balance" << " |";     
	cout << "\n====================================================="<<endl;     

	
	for (stClient  &client : vClients) {
		PrintClientBalance(client);
	}
	cout << "====================================================="<<endl;
	
	
	
}

void PerformOptionsTransaction(enTransacionsOpations opation){
	switch(opation){
		case enTransacionsOpations::eDeposit:
			system("cl");
			ShowDepositScreen();
			GoToTransactionsScreen();
			break;
			
		case enTransacionsOpations::eWithdrow:
			system("cl");
			ShowWithdrowScreen();
			GoToTransactionsScreen();
			break;
		
		case enTransacionsOpations::eTotalBalanses:
			system("cl");
			ShowTotalBalancesScreen();
			GoToTransactionsScreen();
			break;
	 	case enTransacionsOpations::eMainMenueScreen:
			system("cl");
			ShowMainMenueScreen();
			break;
	}
	
}


// Transacions Main Menue Screen
void ShowTransacionsMainMenueScreen(){
	
	if(!CheckAccessPermission(enPermissions::Transacions)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}
	system("cl");
	cout << "======================================" << endl;
	cout << "        Transacions Main Menue        " << endl;
	cout << "======================================" << endl;
	cout << "[1] Deposit " << endl;
	cout << "[2] Withdrow" << endl;
	cout << "[3] Total Balanses" << endl;
	cout << "[4] Main Menue" << endl;
	
	 PerformOptionsTransaction((enTransacionsOpations)ReadTransactionsOpation());  
	
}
// ======== End Transacions ======


// ======== Find clients Start ======
void ShowFindClientScreen(){
	if(!CheckAccessPermission(enPermissions::FindClients)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}
	cout << "========================================" << endl;
	cout << "          Find Client Screen          " << endl;
	cout << "========================================" << endl;	
	
	vector <stClient> vClients= LoadClientsFromFileToVector(ClientsFileName);
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number  :");
	stClient client;
	

	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		PrintClientCard(client);
	}else{
		cout << "Client With Account Number [ "<< AccountNumber << " ] is unavailable :-(" << endl;
	}
	
}
// ======== Find clients End ======






// ======== Manage Users Screen Start ======

bool UserExistsByUsername(string username,string FileName){
	fstream File;
	vector <stUser> vUsers = LoadUserFromFileToVector(FileName);
	File.open(FileName,ios::in);
	
	if(File.is_open()){
		string line="";
		stUser User;
		
		while(getline(File, line)){
			
			User = ConvetUserLineStringTostUser(line);
			if(User.Username == username){
				File.close();
				return true;	
			}
			
		} 
		
		File.close();
	}
	
	return false;
}





bool FindUserByUserName(string Username,vector<stUser>vUsers){
	stUser User;
	
	if(UserExistsByUsername(Username,UsersFileName)){
		PrintUserInfo(User);
		return true;
	}
	else{
		cout << "User With Username [ "<< Username<<" ]is Not Found" << endl;
		return false;
	}
	
	
}



// Show All Users Screen
void ShowAllUsersScreen(){
	system("cl");
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	
	cout << setw(10)<<" Users List ("<<vUsers.size()<<") User(s)" << endl;
	
	
	cout<<"============================================"<<endl;
	cout<<"| Username     | Password     | Permissions |"<<endl;
	cout<<"============================================"<<endl;
	if(vUsers.size()==0){
		cout << "\t Not Available Isers In The System" << endl;	
	}else{
		
		for (stUser &user : vUsers) {
			PrintUserRecord(user);
		}
	}
	cout<<"============================================"<<endl;
	
}
// Show List Users Screen
void ShowListUsersScreen(){
	ShowAllUsersScreen();
}



// Read New User 
stUser ReadNewUser(){
	
	stUser User;
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	cout << "Enter Username :" ;
	getline(cin >> ws,User.Username);
	
	while(UserExistsByUsername(User.Username,UsersFileName)){
		cout << "Username ["<< User.Username << "] is already Exist"<< endl;
		cout << "Enter Username :" ;
		getline(cin >> ws,User.Username);
	}
	
	cout << "Enter Password :" ;
	getline(cin >> ws,User.Password);
	

	User.Permissions = ReadPermissionsToSet();
	
	
	return User;
}

// Add New User to File
void AddNewUser(){
	stUser NewUser;
	NewUser = ReadNewUser();
	
	AddDataLineToFile(UsersFileName,ConvertRecordToOneLine(NewUser));
	
}


string ReadUserName(){
	string Username;
	cout << "Enter Username :" ;
	// cin >> Username;
	getline(cin>>ws,Username);
	
	return Username;
}
// Add New Users
void AddNewUsers(){
	bool AddmoreBool = false;
	string Addmore="N";
	do{
		
		
		if(AddmoreBool && Addmore=="Y"||Addmore=="y"){
			system("cl");
			cout<<"============================================"<<endl;
	cout<<"          Add New Users Screen" <<setw(10)<< endl;
	cout<<"============================================"<<endl;
		}
		AddNewUser();
		cout << "Do You Want To Add More Users?(Y/N):";
		
		cin >> Addmore;
		
	}while(Addmore=="Y"||Addmore=="y");

	
}
// Add New Users Screen
void ShowAddNewUserScreen(){
	system("cl");
	cout<<"============================================"<<endl;
	cout<<"          Add New Users Screen" <<setw(10)<< endl;
	cout<<"============================================"<<endl;
	
	AddNewUsers();
}


bool MarkForDeleteUserByUserName(string Username,vector <stUser>&vUsers){
	
	for (stUser &user : vUsers) {
		if(user.Username == Username ){
			user.MarkForDelete=true;
			return true;
		}
	}
	return false;
	
}

bool DeleteUserByUserName(string Username,vector <stUser>&vUsers){
	stUser User;
	char Answer;
	
	
	if(UserExistsByUsername(Username,UsersFileName)){
		PrintUserInfo(User);
		
		cout << "\nAre you sure you want delete this user? y/n : " ;
		cin >> Answer;
		if(toupper(Answer)=='Y'){
			
			MarkForDeleteUserByUserName(Username,vUsers);
			
			SaveUsersToFile(UsersFileName,vUsers);
			vUsers = LoadUserFromFileToVector(UsersFileName);
			
			cout << "User Deleted Successfully." << endl;
			
		}
		
	}else{
		cout << "User With Username [ "<< Username<<" ]is Not Found" << endl;
		return false;
	}
	return false;
}
// Delete User Screen 
void DeleteUserScreen(){
	system("cl");
	cout<<"============================================"<<endl;
	cout<<"            Delete Users Screen" << endl;
	cout<<"============================================"<<endl;
	
	stUser User;
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	
	User.Username = ReadUserName();
	
	if(User.Username == UserLogin.Username){
		cout << "This user cannot be deleted :-(!" << endl;	
	}else{
		DeleteUserByUserName(User.Username,vUsers);	
	}
		
	
	
	
}
stUser ChangeUserRecord(string Username){
	stUser User;
	
	User.Username=Username;
	cout << "\n\nEnter Password :" ;
	cin >>  User.Password;
	
	User.Permissions = ReadPermissionsToSet();		
	
	return User;
}	

//Update User By Username
bool UpdateUserByUserName(string Username,vector <stUser>vUsers){
	
	stUser User;
	char Answer;
	
	if(UserExistsByUsername(Username,UsersFileName)){
		
		PrintUserInfo(User);
		cout << "\nAre you sure you want update this user? y/n : " ;
		cin >> Answer;
		if(toupper(Answer)=='Y'){
		
			for (stUser &user : vUsers) {
				if(user.Username==Username){
					user = ChangeUserRecord(Username);	
					break;
				}
			}
			
			
			SaveUsersToFile(UsersFileName,vUsers);
			
		}
		
	}
	else{
		cout << "User With Username [ "<< Username<<" ]is Not Found" << endl;
		
	}
	return false;
}
// Update User Screen
void UpdateUserScreen(){
	system("cl");
	cout<<"============================================"<<endl;
	cout<<"             Update User Screen            " << endl;
	cout<<"============================================"<<endl;
	
	stUser User;
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	
	User.Username = ReadUserName();
	
	UpdateUserByUserName(User.Username,vUsers);
}



// Find User Screen
void FindUserScreen(){
	system("cl");
	
	cout<<"============================================"<<endl;
	cout<<"             Find User Screen            " << endl;
	cout<<"============================================"<<endl;
	
	stUser User;
	vector <stUser> vUsers = LoadUserFromFileToVector(UsersFileName);
	
	User.Username = ReadUserName();
	
	FindUserByUserName(User.Username,vUsers);
}
void PerformUsersOpation(enUserMenuOptions UserOption){
	
	switch(UserOption){
		
		case enUserMenuOptions::ListUsers:
			ShowListUsersScreen();
			GoToUsersManageScreen();
			break;
		
		case enUserMenuOptions::AddUser:
			ShowAddNewUserScreen();
			GoToUsersManageScreen();
			break;
		case enUserMenuOptions::DeleteUser:
			DeleteUserScreen();
			GoToUsersManageScreen();
			break;
		case enUserMenuOptions::UpdateUser:
			UpdateUserScreen();
			GoToUsersManageScreen();
			break;
		case enUserMenuOptions::FindUser:
			FindUserScreen();
			GoToUsersManageScreen();
			break;
		case enUserMenuOptions::MainMenue:
			ShowMainMenueScreen();
			break;
	}
	
}


void ManageUsersScreen(){
	
	if(!CheckAccessPermission(enPermissions::ManageUsers)){
		AccessDenidScreen();
		ShowAccessDeniedMessage();
		return;	
	}
	system("cl");
	cout << "======================================" << endl;
	cout << "            Manage Users Screen       " << endl;
	cout << "======================================" << endl;
	
	cout << "\t[1] List Users " << endl;
	cout << "\t[2] Add New User " << endl;
	cout << "\t[3] Delete User " << endl;
	cout << "\t[4] Update User " << endl;
	cout << "\t[5] Find User " << endl;
	cout << "\t[6] Main Menue " << endl;
	
	PerformUsersOpation((enUserMenuOptions)ReadUsersMenueOptions());
}
// ======== Manage Users Screen End ======

void PerFormMainMenuOpation(enMainMenuOptions Opation ){
	switch(Opation){
		
		case enMainMenuOptions::eShowAllClients:
			system("cl");
			ShowAllClientsScreen();
			GoBackToMainMenu();
			break;
		
		case enMainMenuOptions::eAddNewClients:
			system("cl");
			ShowAddNewClientsScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eDeleteClients:
			system("cl");
			ShowDeleteClientsScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eUpdateClient:
			system("cl");
			ShowUpDateClientScreen();
			GoBackToMainMenu();
			break;
				
		case enMainMenuOptions::eTransactions:
			system("cl");
			ShowTransacionsMainMenueScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eFindClient:
			system("cl");
			ShowFindClientScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eManageUsers:
			system("cl");
			ManageUsersScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eLogout:
			Login();
			break;
			
	}
}
// This Function To Show Banner Main Menue 
void ShowMainMenueScreen(){
	system("cl");
	cout << "========================================" << endl;
	cout << "          Main Menue Screen             " << endl;
	cout << "========================================" << endl;
	cout << "   [1] Show Client List." << endl;
	cout << "   [2] Add  Client." << endl;
	cout << "   [3] Delete Client." << endl;
	cout << "   [4] Update Client Info." << endl;
	cout << "   [5] Transacions." << endl;
	cout << "   [6] Find Client." << endl;
	cout << "   [7] Manage Users." << endl;
	cout << "   [8] Logout" << endl;
	cout << "========================================" << endl;
	
	PerFormMainMenuOpation((enMainMenuOptions)ReadMainMenueOpation());
}






void Login(){
	
	string username,password;
	bool LoginFalid = false;
		
	do{
		system("cl");
		cout << "- - - - - - - - - - - - - - - - -" << endl;
		cout << "          Login Screen           " << endl;
		cout << "- - - - - - - - - - - - - - - - -" << endl;
		
		if(LoginFalid){
			cout << "Invalid Username And Password :-(" << endl;	
		}
		
		cout << "Enter Username :" ;
		getline(cin >>ws,username);
	
		cout << "Enter Password :" ;
		getline(cin>>ws,password);	
		
		LoginFalid =!LoadUserInfo(username,password);
	}while(LoginFalid);
	
	
	
	ShowMainMenueScreen();
	// cout << "Login Done" << endl;
}


int main(){
	system("cl");
	
	Login();
	return 0;
};