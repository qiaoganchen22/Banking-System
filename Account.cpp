#include "Account.h"

long Account::account_number_counter = 0;

Account::Account()
{
}

Account::Account(string first_name, string last_name, double account_balance)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->account_balance = account_balance;
    account_number = ++account_number_counter;
    cout << "Account created!\n";
}

void Account::withdraw(double amount)
{
    if (account_balance < amount)
    {
        cout << "Insufficent funds!\n";
        return;
    }
    account_balance -= amount;
    cout << "Withdraw completed!\n";
}

void Account::deposit(double amount)
{
    account_balance += amount;
    cout << "Deposit completed!\n";
}

ostream &operator<<(ostream &result, Account &account)
{
    result << account.first_name << " " << account.last_name << "\nAccount Number: " << account.account_number << "\nAccount Balance: " << account.account_balance << "\n";
    return result;
}

ifstream &operator>>(ifstream &result, Account &account)
{
    result >> account.first_name >> account.last_name >> account.account_number >> account.account_balance;
    return result;
}

ofstream &operator<<(ofstream &result, Account &account)
{
    result << account.first_name << "\n"
           << account.last_name << "\n"
           << account.account_number << "\n"
           << account.account_balance << "\n";
    return result;
}

long Account::get_account_number()
{
    return account_number;
}

void Account::set_account_number_counter(long account_number)
{
    account_number_counter = account_number;
}

double Account::get_account_balance()
{
    return account_balance;
}