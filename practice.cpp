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


        Complex operator+(const Complex &obj){
            Complex temp;
            temp.real = this -> real + obj.real;
            temp.imag = this -> imag + obj.imag;
            
            return temp;
        }

        bool operator == (const Complex &obj){
            if((this -> real == obj.real) && (this -> imag == obj.imag)){
                return true;
            }

            return false;
        }


    public:
        void print(){
            cout << "{" << this -> real << " + " << "i" << this -> imag << "}" << endl;
        }
};


int main(){

    Complex A(4 , 7);
    A.print();

    Complex B(2 , 8);
    B.print();


    Complex C = A + B;
    C.print();

    bool d = A == B;
    cout << d;

    return 0;
}