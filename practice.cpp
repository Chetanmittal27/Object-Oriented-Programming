#include<iostream>
#include<string>

using namespace std;

class Student {

    public:
        int id;
        int age;
        string name;
        int nos;

        Student(int id , int age , string name , int nos){
            cout << "Student parameterised constructor called" << endl;

            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;
        }

        Student(const Student &srcobj){
            cout << "Copy Constructor called" << endl;

            this -> id = srcobj.id;
            this -> age = srcobj.age;
            this -> name = srcobj.name;
            this -> nos = srcobj.nos;
        }

        void study(){
            cout << this -> name << " studying" << endl;
        }

        void sleep(){
            cout << this -> name << " sleeping" << endl;
        }

        void bunk(){
            cout << this -> name << " bunking" << endl;
        }


        ~Student(){
            cout << this -> name << " default destructor called" << endl;
        }
};


int main(){
    
    Student A(1 , 21 , "Chetan" , 6);
    
    Student C = A;


    return 0;
}