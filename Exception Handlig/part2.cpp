// Exception Handling using try & catch.

#include<iostream>
#include<string>

using namespace std;


class Customer {

    public:
        string name;
        int account_number;
        int balance;

    public:
        Customer(string name , int account_number , int balance){
            cout << name << " constructor called" << endl;
            this -> name = name;
            this -> account_number = account_number;
            this -> balance = balance;
        }


        // Deposit Money
        void deposit(int amount){
            if(amount > 0){
                balance = balance + amount;
                cout << "Amount Credited Successfully" << endl;
            }

            else{
                throw "Amount should be greater than zero";
            }
        }


        // Withdraw Money
        void withdraw(int amount){
            if(amount > 0 && amount <= balance){
                balance = balance - amount;
                cout << "Amount Debited Successfully" << endl;
            }

            else if(amount < 0){
                throw "Amount should be greater than zero";
            }

            else{
                throw "Your balance is low";
            }
        }
};


int main(){
    
    Customer A("Chetan" , 12345678 , 30000);
    A.deposit(10000);
    A.withdraw(0000);

    // Customer B("Riya" , 34569038 , 20000);
    // A.deposit(30000);
    // A.withdraw(-1);
    return 0;
}