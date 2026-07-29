#include<iostream>
using namespace std;

class Parent {
    public:
        virtual void print(string msg) = 0;
};

// Wrong
// class Child : public Parent{

//     public:
//         void print(int msg) override {
//             cout << msg << endl;
//         }
// };

// Correct
class Child : public Parent{

    public:
        void print(string msg) override {
            cout << msg << endl;
        }
};

int main(){

    Parent* P = new Child();
    P -> print("Chetan");

    return 0;
}