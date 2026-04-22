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
            cout << "Drawing Circle..." << endl;
        }
};


class Rectangle : public Shape {
    public:
        
        void draw(){
            cout << "Rectangle Drawing..." << endl;
        }
};


class Triangle : public Shape {
    public:
        
        void draw(){
            cout << "Triangle Drawing..." << endl;
        }
};


// I want that i will make a base class pointer and using that i can call relevant draw methods.
void shapeDrawing (Shape *s){
    s -> draw();
}


int main(){

    Circle C;
    Rectangle R;

    shapeDrawing(&C);
    shapeDrawing(&R);

    Triangle *t = new Triangle();
    shapeDrawing(t);

    return 0;
}