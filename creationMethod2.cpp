// Parameterised Constructor is used.

#include<iostream>
#include<string>

using namespace std;

class Student {

    public:
        int id;
        int age;
        string name;
        int nos;

        // Constructor : Parameterised Constructor
        Student(int id , int age , string name , int nos){
            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;

            cout << name << " parameterised constructor called" << endl;
        }

        void study(){
            cout << this -> name << " Studying" << endl;
        }

        void sleep(){
            cout << this -> name << " Sleeping" << endl;
        }


        ~Student(){
            cout << this -> name << " default destructor called" << endl;
        }
};


int main(){

    // Object Creation
    Student A(1 , 21 , "Chetan" , 4);
    Student B(2 , 20 , "Rahul" , 5);
    // A.sleep();

    cout << A.name << " age is " << A.age << endl;
    B.sleep();

    return 0;
}