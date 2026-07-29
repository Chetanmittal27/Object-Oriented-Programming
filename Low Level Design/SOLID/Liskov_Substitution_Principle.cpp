// Violates the Liskov Substituion Principle as FD Account is not replaceable to Account Class


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