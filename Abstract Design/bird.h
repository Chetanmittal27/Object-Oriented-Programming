#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>
using namespace std;

class Bird {
    public: 
        virtual void eat() = 0;
        virtual void fly() = 0;

        // sub classes that inherits this class 
        // have to implement pure virtual functions.
};

class Sparrow : public Bird {
    public:
        void eat(){
            cout << "Sparrow is eating" << endl;
        }

        void fly(){
            cout << "Sparrow is flying" << endl;
        }
};

class Eagle : public Bird {
    public:
        void eat(){
            cout << "Eagle is eating" << endl;
        }

        void fly(){
            cout << "Eagle is flying" << endl;
        }
};

#endif // BIRD_H
