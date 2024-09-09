#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string accountOwner, double initialBalance) {
        owner = accountOwner;
        balance = initialBalance;
    }

    void checkBalance() {
        cout << "Account owner: " << owner << endl;
        cout << "Current balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            checkBalance();
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
            checkBalance();
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

int main() {
    string name;
    double initialBalance;
    int choice;
    double amount;

    cout << "Enter account owner's name: ";
    getline(cin, name);
    
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    do {
        cout << "\n=== Bank Menu ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.checkBalance();
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                account.deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
