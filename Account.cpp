#include<iostream>
#include"s1061460_Account.h"
using namespace std;

Account::Account(double money)
{
    balance = money;
}

void Account::credit(double money)
{
    balance += money;
    
}

bool Account::debit(double money)
{
    if (money <= balance){
        balance -= money;
        cout << "Attempting to debit $35.00 from a class Account" << endl;
        return true;
    }
    
    else{
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

void Account::setBalance(double money)
{
    balance = money;
}

double Account::getBalance()
{
    return balance;
}

SavingsAccount::SavingsAccount(double money, double rate)
    :Account(money)
{
    if (rate > 0.0) {
        interestRate = rate;
    }
    else{
        interestRate = 0.0;
    }
}

bool SavingsAccount::debit(double money)
{
    if (money <= balance) {
        balance -= money;
        cout << "Attempting to debit $35.00 from a class SavingsAccount" << endl;
        return true;
    }

    else {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

double SavingsAccount::calculateInterest()
{
    //return balance1 = balance * 0.03;
    return getBalance() * interestRate;
}

CheckingAccount::CheckingAccount(double money, double fee)
    :Account(money)
{
    if (fee > 0.0) {
        transactionFee = fee;
    }
    else{
        transactionFee = 0.0;
    }  
}

bool CheckingAccount::debit(double money)
{
    if (money <= balance) {
        balance -= money;
        cout << "Attempting to debit $35.00 from a class CheckingAccount" << endl;
        chargeFee();
        return true;
    }

    else {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

void CheckingAccount::credit(double money)
{
    Account::credit(money);
    chargeFee();
}

void CheckingAccount::chargeFee()
{
    Account::setBalance(getBalance() - transactionFee);
    cout << "$" << transactionFee << " transaction fee charged." << endl;
}