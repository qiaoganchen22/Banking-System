#ifndef Account_H
#define Account_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account
{
    string first_name;
    string last_name;
    long account_number;
    double account_balance;
    static long account_number_counter;

public:
    Account();
    Account(string first_name, string last_name, double account_balance);
    void withdraw(double amount);
    void deposit(double amount);
    void set_account_number_counter(long account_number);
    double get_account_balance();
    long get_account_number();
    friend ostream &operator<<(ostream &result, Account &account);
    friend ifstream &operator>>(ifstream &result, Account &account);
    friend ofstream &operator<<(ofstream &result, Account &account);
};
#endif