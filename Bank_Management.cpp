#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;

protected:
    int balance;

private:
    string password;

public:
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand() % 1000000000;
        this->balance = 0;
        cout << "Your Account Number is: " << this->account_number << endl;
    }
    int show_balance(string password)
    {
        if (this->password == password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password, int amount)
    {
        if (this->password == password)
        {
            this->balance += amount;
            cout << "Add money succesful\n";
        }
        else
        {
            cout << "Password didn't match\n";
        }
    }
    void deposit_money(string password, int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount\n";
            return;
        }
        if (this->balance < amount)
        {
            cout << "Insufficient balance\n";
            return;
        }
        if (this->password == password)
        {
            this->balance -= amount;
            cout << "Deposit money succesful\n";
        }
        else
        {
            cout << "Password didn't match\n";
        }
    }
    friend class MyCash;
};

class MyCash
{
protected:
    int balance;

public:
    MyCash()
    {
        this->balance = 0;
    }
    void add_money_from_bank(BankAccount *myAccount, string password, int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }
        if (myAccount->balance < amount)
        {
            cout << "Insufficient balance\n";
        }
        if (myAccount->password == password)
        {
            this->balance += amount;
            myAccount->balance -= amount;
            cout << "Add money from bank is succesful\n";
        }
        else
        {
            cout << "Password didn't match\n";
        }
    }
    int show_balance()
    {
        return balance;
    }
};

BankAccount *create_account()
{
    string account_holder, password, address;
    int age;
    cout << "CREATE ACCOUNT" << endl;
    cout << "Enter Account Holer Name: ";
    cin >> account_holder;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter an Age: ";
    cin >> age;
    cout << "Enter Correct Password: ";
    cin >> password;

    BankAccount *myAccount = new BankAccount(account_holder, address, age, password);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "ADD MONEY\n";
    cout << "Enter Correct Password: ";
    cin >> password;
    cout << "Enter an Amount: ";
    cin >> amount;
    myAccount->add_money(password, amount);
    cout << "Your Bank Balace is: " << myAccount->show_balance("Abc") << endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "DEPOSIT MONEY\n";
    cout << "Enter Correct Password: ";
    cin >> password;
    cout << "Enter an Amount: ";
    cin >> amount;
    myAccount->deposit_money(password, amount);
    cout << "Your Bank Balace is: " << myAccount->show_balance("Abc") << endl;
}

void add_money_from_bank(MyCash *MyCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "ADD MONEY FROM BANK\n";
    cout << "Enter Correct Password: ";
    cin >> password;
    cout << "Enter an Amount: ";
    cin >> amount;
    MyCash->add_money_from_bank(myAccount, password, amount);
    cout << "Your bank  Balnace is: " << myAccount->show_balance("Abc") << endl;
    cout << "MyCash balance is: " << MyCash->show_balance() << endl;
}

int main()
{
    BankAccount *myAccount = create_account();
Flag:
    cout << "Select Option: \n";
    cout << "1. Add Money to Bank\n";
    cout << "2. Deposit Money from Bank\n";
    cout << "3. Add Money from Bank\n";
    cout << "4. Exit\n";
    int option;
    cin >> option;
    if (option == 1)
    {
        add_money(myAccount);
        goto Flag;
    }
    else if (option == 2)
    {
        deposit_money(myAccount);
        goto Flag;
    }
    else if (option == 3)
    {
        MyCash *mycash = new MyCash();
        add_money_from_bank(mycash, myAccount);
        goto Flag;
    }
    else if (option == 4)
    {
        cout << "Thank you! Plase stay with us\n";
    }
    else
    {
        cout << "Invalid option\n";
        goto Flag;
    }
}
