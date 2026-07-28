#include<iostream>
using namespace std;

class Shape {

    public:
        virtual void draw(){
            cout << "Generic Drawing..." << endl;
        }
};


class Circle : public Shape {
    
    public:
        void draw(){
            cout << "Circle Drawing..." << endl;
        }
};


class Rectangle : public Shape {

    public:
        void draw(){
            cout << "Rectangle Drawing..." << endl;
        }
};


void shapeDrawing(Shape *c){
    return c -> draw();
}

int main(){

    Circle C;
    Rectangle R;

    shapeDrawing(&C);
    shapeDrawing(&R);
    return 0;
}