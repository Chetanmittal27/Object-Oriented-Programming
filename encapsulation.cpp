#include<iostream>
#include<string>

using namespace std;

class Student 
{
    public:
        int id;
        int age;
        string name;
        int nos;

    private:
        int *gpa;
        string gf;

    
    public:
        Student(int id , int age , string name , int nos , float gpa , string gf){
            cout << "Student parameterised constructor called" << endl;

            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;
            this -> gpa = new int(gpa);
            this -> gf = gf;
        }


        Student(const Student &objsrc){
            cout << "Copy constructor called" << endl;

            this -> id = objsrc.id;
            this -> age = objsrc.age;
            this -> name = objsrc.name;
            this -> nos = objsrc.nos;
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

    
    private:
        void isChatting(){
            cout << this -> name << " chatting with gf" << endl;
        }
};



int main(){

    Student A(1 , 21 , "Chetan" , 6 , 8.00 , "Vanshika");
    
    cout << A.age << endl;
    // cout << A.gf << endl;                         cannot access gf attribute as it is private
    
}