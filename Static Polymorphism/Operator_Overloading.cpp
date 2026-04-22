#include<iostream>

using namespace std;

class Complex {

    public:
        int real;
        int imag;

        Complex(){
            real = -1;
            imag = -1;
        }


        Complex(int r , int i){
            this -> real = r;
            this -> imag = i;
        }


        // syntax
            /*
            Ret_type operator <op> (const Complex &B){
                  mlkdmk
                  return <>
            }
            */

            // for addition of two complex numbers
            Complex operator + (const Complex &B){
                Complex temp;
                temp.real = this -> real + B.real;
                temp.imag = this -> imag + B.imag;

                return temp;
            }


            // similarly for subtraction of two complex numbers
            Complex operator - (const Complex &B){
                Complex temp;
                temp.real = this -> real - B.real;
                temp.imag = this -> imag - B.imag;

                return temp;
            }


        void print(){
            cout << "{" << this -> real << " + " << "i" << this -> imag << "}" << endl;
        }
};


int main(){

    Complex A(2 , 7);
    A.print();
    Complex B(4 , 9);
    B.print();

    Complex C = A + B;
    C.print();

    Complex D = A - B;
    D.print();
    
    return 0;
}