#ifndef Bank_H
#define Bank_H
#include "Account.h"
#include <map>

class Bank
{
    map<long, Account> my_bank;

public:
    Bank();
    void open_account(string first_name, string last_name, double account_balance);
    void check_account(long account_number);
    void delete_account(long account_number);
    void withdraw(long account_number, double amount);
    void deposit(long account_number, double amount);
    void close_bank();
    ~Bank();
};
#endif