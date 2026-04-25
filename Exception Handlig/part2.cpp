// Exception Handling using try & catch.


// Exception : An exception is an unexpected problem that arises during the execution of the program and the program terminates with some errors or issues. Exception occurs during the execution of program (at run time , nor at compile time).

// Try : Try keyword represents a block of code that may throw an exception during the execution of program, when placed inside the try block. Its followed by one or more catch blocks. If an exception occurs, try block can throw an exception.

// Catch : Catch keyword represents a block of code that may be executed when an exception is thrown by try block.

// throw : throw keyword is used to throw an exception in c++.

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
    try{
        A.deposit(10000);
        A.withdraw(50000);
    }
    catch(const char *e){
        cout << "Exception Occured : " << e;
    }


    // Customer B("Riya" , 34569038 , 20000);
    // A.deposit(30000);
    // A.withdraw(-1);
    return 0;
}