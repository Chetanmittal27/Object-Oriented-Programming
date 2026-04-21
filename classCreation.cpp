// Default constructor is used


#include<iostream>
#include<string>

using namespace std;


class Student {

    public:
        // Attributes
        int id;
        int age;
        string name;
        int nos;


        // Constructor: Default Constructor
        Student(){
            cout << "Student Default Constructor Called" << endl;
        }

        // Behaviour/Methods/Functions

        void study() {              
            cout << this -> name << " Studying" << endl;                  // this is used to represent the pointer to the current object of class.
        }

        void sleep() {
            cout << this -> name << " Sleeping" << endl;
        }

        void bunk() {
            cout << this -> name << " Bunking" << endl;
        }


        // Destructor
        ~Student(){
            cout << this -> name << " Student default destructor called" << endl;
        }
};


int main(){
    // instance
    Student A;
    A.id = 1;
    A.age = 21;
    A.name = "Chetan";
    A.nos = 6;

    A.study();


    Student B;
    B.id = 2;
    B.age = 20;
    B.name = "Rahul";
    B.nos = 5;

    B.sleep();

    return 0;
}
