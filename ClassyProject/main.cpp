#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;


int main(){
	
	Account my_account;
	my_account.set_balance(1000.0);
	
	if(my_account.deposit(200.0)){
		cout << "Deposit OK" << endl;
	}
	else{
		cout << "Deposit Not allowed" << endl;
	}
	
	if(my_account.withdraw(300.0)){
		cout << "Withdrawal OK" << endl;
	}
	else{
		cout << "You are poor" << endl;
	}
	
	if(my_account.withdraw(1300.0)){
		cout << "Withdrawal OK" << endl;
	}
	else{
		cout << "You are poor" << endl;
	}
	
	return 0;
}