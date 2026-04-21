// Copy constructor program


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
            cout << "Parameterised constructor called" << endl;
            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;
        }

        // Copy constructor
        Student(const Student &srcobj){

            cout << "Copy constructor called" << endl;
            this -> id = srcobj.id;
            this -> age = srcobj.age;
            this -> name = srcobj.name;
            this -> nos = srcobj.nos;
        }


        void study(){
            cout << this -> name << " studying" << endl;
        }

        void bunk(){
            cout << this -> name << " bunks" << endl;
        }

        void sleep(){
            cout << this -> name << " sleeping" << endl;
        }


        ~Student(){
            cout << this -> name << " default destructor called" << endl;
        }

};


int main(){

    Student A(1 , 21 , "Chetan" , 6);

    // copy object A to object C 
    Student C = A;
    cout << C.name << " & " << C.age << endl;
}