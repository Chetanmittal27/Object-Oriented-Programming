// Violates the Liskov Substituion Principle as FD Account is not replaceable to Account Class

/*
#include<iostream>
#include<vector>

using namespace std;

class Account {

    public:
        virtual void deposit(double Amount) = 0;
        virtual void withdraw(double Amount) = 0;
};


class SavingAccount : public Account {

    private:
        double balance;

    public:
        SavingAccount(){
            this -> balance = 0;
        }


        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in savings account. New Balance : " << balance << endl;
        }

        void withdraw(double amount) override {
            if(balance >= amount){
                balance = balance - amount;
                cout << "Withdrawn " << amount << " from savings account. New Balance : " << balance << endl;
            }

            else{
                cout << "Insufficient funds in the savings account" << endl;
            }
        }
};


class CurrentAccount : public Account {

    private:
        double balance;

    public:
        CurrentAccount(){
            this -> balance = 0;
        }


        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in current account. New Balance : " << balance << endl;
        }

        void withdraw(double amount) override {
            if(balance >= amount){
                balance = balance - amount;
                cout << "Withdrawn " << amount << " from current account. New Balance : " << balance << endl;
            }

            else{
                cout << "Insufficient funds in the current account" << endl;
            }
        }
};


class fixedDepositAccount : public Account {
    
    private:
        double balance;

    public:
        fixedDepositAccount(){
            this -> balance = 0;
        }


        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in FD account. New Balance : " << balance << endl;
        }

        void withdraw(double amount) override {
            throw logic_error("Withdrawal Not Allowed in Fixed Deposit Account");
        }
};


int main(){

    Account* A = new SavingAccount();
    A -> deposit(10000);
    A -> withdraw(5000);

    Account* B = new fixedDepositAccount();
    B -> withdraw(3000);

    return 0;
}

*/


// Implementation using Liskov Substitution Principle
#include<iostream>
#include<vector>

using namespace std;

// Base class - only guarantees what EVERY account can do: deposit
class Account {
    public:
        virtual void deposit(double amount) = 0;
        virtual ~Account() {}
};

// Separate interface for accounts that support withdrawal
class Withdrawable {
    public:
        virtual void withdraw(double amount) = 0;
        virtual ~Withdrawable() {}
};

class SavingAccount : public Account, public Withdrawable {

    private:
        double balance;

    public:
        SavingAccount() {
            this->balance = 0;
        }

        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in savings account. New Balance : " << balance << endl;
        }

        void withdraw(double amount) override {
            if (balance >= amount) {
                balance = balance - amount;
                cout << "Withdrawn " << amount << " from savings account. New Balance : " << balance << endl;
            }
            else {
                cout << "Insufficient funds in the savings account" << endl;
            }
        }
};

class CurrentAccount : public Account, public Withdrawable {

    private:
        double balance;

    public:
        CurrentAccount() {
            this->balance = 0;
        }

        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in current account. New Balance : " << balance << endl;
        }

        void withdraw(double amount) override {
            if (balance >= amount) {
                balance = balance - amount;
                cout << "Withdrawn " << amount << " from current account. New Balance : " << balance << endl;
            }
            else {
                cout << "Insufficient funds in the current account" << endl;
            }
        }
};

// FD Account only inherits Account -- NOT Withdrawable
// It never promises a withdraw() it can't fulfill
class FixedDepositAccount : public Account {

    private:
        double balance;
        double maturityAmount;

    public:
        FixedDepositAccount() {
            this->balance = 0;
        }

        void deposit(double amount) override {
            balance = balance + amount;
            cout << "Deposited " << amount << " in FD account. New Balance : " << balance << endl;
        }

        // Its own special method -- not part of any shared contract
        double withdrawOnMaturity() {
            cout << "FD matured. Withdrawing full amount: " << balance << endl;
            double amt = balance;
            balance = 0;
            return amt;
        }
};

int main() {

    // Use concrete class types directly -- no casting needed
    SavingAccount savings;
    savings.deposit(10000);
    savings.withdraw(5000);      // works directly, savings IS-A Withdrawable

    CurrentAccount current;
    current.deposit(15000);
    current.withdraw(7000);      // works directly, current IS-A Withdrawable

    FixedDepositAccount fd;
    fd.deposit(20000);
    fd.withdrawOnMaturity();     // its own special method
    // fd.withdraw(3000);        // <-- won't compile: FD has no withdraw() at all

    return 0;
}