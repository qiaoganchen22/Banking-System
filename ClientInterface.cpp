#include "Bank.h"

int main()
{
    int value;
    Bank bank;
    do
    {
        cout << "============================\n";
        cout << "--WELCOME TO THE BANKING SYSTEM--\n";
        cout << "--CHOOSE A OPTION        --\n";
        cout << "--1. Open Account        --\n";
        cout << "--2. Check Account       --\n";
        cout << "--3. Withdraw            --\n";
        cout << "--4. Deposit             --\n";
        cout << "--5. Delete Account      --\n";
        cout << "--6. Close Bank          --\n";
        cout << "--7. Exit                --\n";
        cout << "============================\n\n";
        cout << "Enter an option: ";
        cin >> value;
        switch (value)
        {
        case 1:
        {
            cout << "---------------------------\n";
            cout << "Open Account\n";
            string first_name, last_name;
            double amount;
            cout << "Enter first name: \n";
            cin >> first_name;
            cout << "Enter last name: \n";
            cin >> last_name;
            cout << "Enter amount: \n";
            cin >> amount;
            bank.open_account(first_name, last_name, amount);
            cout << "---------------------------\n\n";
        }
        break;
        case 2:
        {
            cout << "---------------------------\n";
            cout << "Check Account\n";
            long account_number;
            cout << "Enter account number: \n";
            cin >> account_number;
            cout << "---------------------------\n";
            bank.check_account(account_number);
            cout << "---------------------------\n\n";
        }
        break;
        case 5:
        {
            cout << "---------------------------\n";
            cout << "Delete Account\n";
            long account_number;
            cout << "Enter account number: \n";
            cin >> account_number;
            cout << "---------------------------\n";
            bank.delete_account(account_number);
            cout << "---------------------------\n\n";
        }
        break;
        case 3:
        {
            cout << "---------------------------\n";
            cout << "Withdraw\n";
            long account_number;
            double amount;
            cout << "Enter account number: \n";
            cin >> account_number;
            cout << "Enter amount: \n";
            cin >> amount;
            cout << "---------------------------\n";
            bank.withdraw(account_number, amount);
            cout << "---------------------------\n\n";
        }
        break;
        case 4:
        {
            cout << "---------------------------\n";
            cout << "Deposit\n";
            long account_number;
            double amount;
            cout << "Enter account number: \n";
            cin >> account_number;
            cout << "Enter amount: \n";
            cin >> amount;
            cout << "---------------------------\n";
            bank.deposit(account_number, amount);
            cout << "---------------------------\n\n";
        }
        break;
        case 6:
        {
            cout << "---------------------------\n";
            bank.close_bank();
            cout << "---------------------------\n";
        }
        break;
        case 7:
        {
            return 0;
        }
        default:
        {
            cout << "Choose a correct option.\n";
        }
        }
    } while (value != 7);
}