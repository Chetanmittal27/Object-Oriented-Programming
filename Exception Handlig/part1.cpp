// Handling Exceptions using if-else


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
                cout << "Amount should be greater than zero" << endl;
            }
        }


        // Withdraw Money
        void withdraw(int amount){
            if(amount > 0 && amount <= balance){
                balance = balance - amount;
                cout << "Amount Debited Successfully" << endl;
            }

            else if(amount < 0){
                cout << "Amount should be greater than zero" << endl;
            }

            else{
                cout << "Your balance is low" << endl;
            }
        }
};


int main(){
    
    Customer A("Chetan" , 12345678 , 30000);
    A.deposit(10000);
    A.withdraw(50000);
    return 0;
}