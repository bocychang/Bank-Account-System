#include <iostream>
#include <iomanip> //***
#include "s1061460_Account.h" // Account, SavingsAccount, CheckingAccount class definition
#include <vector>
#include <string>
#include <typeinfo> //***
using namespace std;

bool PressEnterToContinue(string mesg = "Press ENTER to continue... ");

int main()
{
	cout << "My ID is s1061460" << endl;
	vector <Account*> accounts;
	accounts.push_back(new Account(30));
	accounts.push_back(new CheckingAccount(45.0, 1.5));
	accounts.push_back(new Account(10));
	accounts.push_back(new CheckingAccount(20, 1.5));
	accounts.push_back(new SavingsAccount(50.0, 0.03));
	accounts.push_back(new Account(20));
	accounts.push_back(new SavingsAccount(50.0, 0.03));
	accounts.push_back(new SavingsAccount(160.0, 0.03));
	accounts.push_back(new CheckingAccount(80.0, 1.5));
	accounts.push_back(new SavingsAccount(55.0, 0.03));
	accounts.push_back(new CheckingAccount(75.0, 1.5));
	accounts.push_back(new Account(260));
	accounts.push_back(new SavingsAccount(70.0, 0.03));
	accounts.push_back(new Account(80));
	accounts.push_back(new CheckingAccount(65.0, 1.5));

	for (int i = 0; i < (int)accounts.size(); i++) {
		cout << "--[" << i + 1 << "]-----------------------------------------" << endl;
		cout << "Balance of the " << typeid(*accounts[i]).name() << " is $" << fixed << setprecision(2) << accounts[i]->getBalance() << endl;
		
		accounts[i]->debit(35.00);
		
		cout << "Balance of the "<< typeid(*accounts[i]).name() <<" is $" << fixed << setprecision(2) << accounts[i]->getBalance() << endl;

		cout << "Credit $25.00 to a " << typeid(*accounts[i]).name() << endl;
		accounts[i]->credit(25.00);
		cout << "Balance of the "<< typeid(*accounts[i]).name() <<" is $" << fixed << setprecision(2) << accounts[i]->getBalance() << endl;

		SavingsAccount* savingsAccountPtr =dynamic_cast <SavingsAccount*> (accounts[i]);

		if (savingsAccountPtr != 0)
		{
			double interestEarned = savingsAccountPtr->calculateInterest();
			cout << "Credit $"<< interestEarned<<" interest into "<< typeid(*accounts[i]).name() << endl;
			savingsAccountPtr->credit(interestEarned);
			cout << "Balance of the "<<typeid(*accounts[i]).name() <<"is $" << fixed << setprecision(2) << accounts[i]->getBalance() << endl;
		} 
	}

	PressEnterToContinue();
} // end main

bool PressEnterToContinue(string mesg)
{
	int c;
	cout << mesg << endl;
	cout.flush();
	do c = getchar(); while ((c != '\n') && (c != EOF));
	return true;
}