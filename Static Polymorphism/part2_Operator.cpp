#include<iostream>
using namespace std;

class Complex {

    public:
        int real;
        int imag;

        Complex(){
            this -> real = -1;
            this -> imag = -1;
        }

        Complex(int r , int i){
            this -> real = r;
            this -> imag = i;
        }


        bool operator == (const Complex &B){

            if((this -> real == B.real)  &&  (this -> imag == B.imag)){
                return true;
            }

            return false;
        }
};


int main(){

    Complex A(3 , 5);
    Complex B(6 , 10);

    bool a = A == B;
    cout << a << endl;

    Complex C(3 , 5);
    bool b = A == C;
    cout << b << endl;

    return 0;
}