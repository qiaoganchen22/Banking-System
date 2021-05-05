#include "Bank.h"

Bank::Bank()
{
    ifstream my_file("Database.txt");
    Account account;
    while (my_file >> account)
    {
        my_bank.insert(make_pair(account.get_account_number(), account));
    }
    account.set_account_number_counter(account.get_account_number());
    my_file.close();
}

void Bank::open_account(string first_name, string last_name, double account_balance)
{
    Account account(first_name, last_name, account_balance);
    my_bank.insert(make_pair(account.get_account_number(), account));
}

void Bank::check_account(long account_number)
{
    map<long, Account>::iterator itr = my_bank.find(account_number);
    if (itr != my_bank.end())
    {
        cout << itr->second << "\n";
        return;
    }
    cout << "Account number: " << account_number << " does not exist.\n";
}

void Bank::delete_account(long account_number)
{
    map<long, Account>::iterator itr = my_bank.find(account_number);
    if (itr != my_bank.end())
    {
        if (itr->second.get_account_balance() != 0)
        {
            cout << "Withdraw from account number " << itr->first << ".\n";
            return;
        }
        my_bank.erase(account_number);
        cout << "Account Number: " << account_number << " deleted.\n";
        return;
    }
    cout << "Account number: " << account_number << " does not exist.\n";
}

void Bank::withdraw(long account_number, double amount)
{
    map<long, Account>::iterator itr = my_bank.find(account_number);
    if (itr != my_bank.end())
    {
        itr->second.withdraw(amount);
        return;
    }
    cout << "Account number: " << account_number << " does not exist.\n";
}

void Bank::deposit(long account_number, double amount)
{
    map<long, Account>::iterator itr = my_bank.find(account_number);
    if (itr != my_bank.end())
    {
        itr->second.deposit(amount);
        return;
    }
    cout << "Account number: " << account_number << " does not exist.\n";
}

void Bank::close_bank()
{
    for (auto itr = my_bank.begin(); itr != my_bank.end(); itr++)
    {
        if (itr->second.get_account_balance() != 0)
        {
            cout << "Withdraw from account number " << itr->first << ".\n";
            return;
        }
    }
    my_bank.clear();
    cout << "Bank closed.\n";
}

Bank::~Bank()
{
    ofstream my_file("Database.txt");
    for (auto itr = my_bank.begin(); itr != my_bank.end(); itr++)
    {
        my_file << itr->second;
    }
    my_file.close();
}