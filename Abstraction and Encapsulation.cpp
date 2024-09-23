//Simple Bank account system
//Requirements
//Validation of value | Balance check(Must have a minimum balance) | Multiple accounts | Must have a main menu
//At the start of the program there should be 0 value
//Include ALL types of validations
//Deadline september 23 (Monday)
#include <iostream>

using namespace std;

class Display{
	public:
		virtual void displayMenu() = 0;			//Pure virtual for displaying menu
};

class MainMenu : public Display {
	public:		
	
		void displayMenu() override {
			cout << "=======[Welcome to NexBanking]======\n";
			cout << "[input the number of desired action]\n";
			cout << "[1] - Savings Account\n";
			cout << "[2] - Current Account\n";
			cout << "[3] - Exit\n";
			cout << "==========================\n";
		}
};

class SubMenu : public Display {
	public:
		void displayMenu() override {
			cout << "======[Savings Menu]======\n";
			cout << "[1] - Deposit\n[2] - Withdraw\n[3] - Check Balance\n[4] - Back\n";
			cout << "==========================\n";
		}	
};

class Bank{
	private:
		double account;
		int account_number;
		
		int temp_choice;
		
	public:
		Bank() : account(){}		//Constructor
	
		//Savings Account
		void deposit(double temp_val){
			cout << "Enter amount to deposit: ";
			cin >> temp_val;
			
			if (account >= 1000 or temp_val >= 1000){
				account += temp_val;
			}
			
			else if (account < 1000){
				cout << "Minimum saving account balance can't be under 1000\n";
				cin.clear();
				cin.ignore(1000, '\n');  
			}
			
			else{
				cout << "invalid input\n";
				cin.clear();
				cin.ignore(1000, '\n'); 
			}
			
			cout << "New account balance: " << account << endl;
		}
		
		
		void Witdraw(double temp_val){
			cout << "Enter amount to withdraw: ";
			cin >> temp_val;
			
			if(account - temp_val < 1000){
				cout << "Mimimum balance cannot be under 1000\n";
				cin.clear();
				cin.ignore(1000, '\n'); 
			}
			else if(temp_val < 0){
				cout << "Don't use negative numbers\n";
				cin.clear();
				cin.ignore(1000, '\n'); 
			}
			
			else{
				account -= temp_val;
				cout << "You withdrawn " << temp_val << " from your account\n";
				cout << "New savings account balance: " << account << endl;
			}
		}
		
		void checkBalance(){
			if (account >= 1000){
				cout << "======[Savings Balance]======\n";
				cout << "Your current balance is: " << account << endl;

			}
			
			if (account < 1000 ){
				cout << "Your account is empty\n";
			}
		}
		
			void ClearBank(){
				account = 0;
			}
		
};

class CurrentAccount{
		private:
		double c_account;
		
		int temp_choice;
		
	public:
		CurrentAccount() : c_account() {}		//Constructor
	
		//Current Account
		void deposit(double c_temp_val){
			cout << "Enter amount to deposit: ";
			cin >> c_temp_val;
			
			if (c_temp_val > 0){
				c_account += c_temp_val;
			}
			
			cout << "New current account balance: " << c_account << endl;
		}
		
		
		void Witdraw(double c_temp_val){
			cout << "Enter amount to withdraw: ";
			cin >> c_temp_val;
			
			if(c_temp_val < 0){
				cout << "Don't use negative numbers\n";
			}
			
			else{
				c_account -= c_temp_val;
				cout << "You withdrawn " << c_temp_val << " from your account\n";
				cout << "New account balance: " << c_account << endl;
			}
		}
		
		void checkBalance(){
			if (c_account > 0){
				cout << "======[Current Balance]======\n";
				cout << "Your current balance is: " << c_account << endl;
			}
			
			if (c_account <= 0 ){
				cout << "Your account is empty\n";
			}
		}
		
		void ClearCurrent(){
			c_account = 0;
		}
		
		
};

class Reset{
	private:
		int account_ch;
	public:			
	void newAccount(){
		cout << "Make new account? [1 - yes] [2 - no]\n";
	}	
		
};


int main(){
//Main menu
	MainMenu m1;
	SubMenu s1;
	Bank b1;
	CurrentAccount c1;
	Reset r1;
	
//Main variables
	int ch_main;
	int ch_sub;
	double temp_val;
	double c_temp_val;
	int exit;
	
//Looper
bool main_temp = true;
	while(main_temp){
	
//Process
	m1.displayMenu();
	cin >> ch_main;
		switch (ch_main){
			case 1:{
				system("pause");
				system("cls");
				bool temp1 = true;
				while (temp1){				
				s1.displayMenu();
				cin >> ch_sub;

				switch (ch_sub){
				case 1:{
					b1.deposit(temp_val);
					temp1 = false;
					break;
				}
				case 2:{
					b1.Witdraw(temp_val);
					temp1 = false;
					break;
				}
				case 3:{
					b1.checkBalance(); 
					temp1 = false;
					break;
				}
				case 4:{
					temp1 = false;
					break;
				}
				default:{
					cout << "Invalid input\n";
					cin.clear();
					cin.ignore(1000, '\n'); 
					system("pause");
					system("cls");
					break;
				}
				}
				}
				break;
			}
		
			
			case 2:{
			system("pause");
				system("cls");
				bool temp1 = true;
				while (temp1){				
				s1.displayMenu();
				cin >> ch_sub;

				switch (ch_sub){
				case 1:{
					c1.deposit(c_temp_val) ;
					temp1 = false;
					break;
				}
				case 2:{
					c1.Witdraw(c_temp_val); 
					temp1 = false;
					break;
				}
				case 3:{
					c1.checkBalance();
					temp1 = false;
					break;
				}
				case 4:{
					temp1 = false;
					break;
				}
				default:{
					cout << "Invalid input\n";
					cin.clear();
					cin.ignore(1000, '\n'); 
					system("pause");
					system("cls");
					break;
				}
				}
				}
				break;
			}
				
			
			case 3:{
		bool tempR = true;
		while(tempR){
			r1.newAccount();
			cin >> exit;
			switch (exit){
				case 1:{
					c1.ClearCurrent();
					b1.ClearBank();
					tempR = false;
					break;
				}
				
				case 2:{
					return 1;
					break;
				}
				default:{
					cout << "Invalid input\n";
					cin.clear();
					cin.ignore(1000, '\n'); 
					system("pause");
					system("cls");
					break;
				}
			}
		}
				break;
			}
			default:{
				cout << "Invalid input\n";
				cin.clear();
				cin.ignore(1000, '\n');  
				system("pause");
				system("cls");
				break;
			}
				
		}
		cout << endl;
		system("pause");
		system("cls");
			
}
return 0;
}