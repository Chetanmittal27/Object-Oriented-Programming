#include<iostream>

using namespace std;

class Shape {
    public:
        
        void draw(){
            cout << "Generic Drawing..." << endl;
        }
};


class Circle : public Shape {
    public:
        
        void draw()  {
            cout << "Drawing Circle..." << endl;
        }
};


class Rectangle : public Shape {
    public:
        
        void draw() {
            cout << "Rectangle Drawing..." << endl;
        }
};


class Triangle : public Shape {
    public:
        
        void draw() {
            cout << "Triangle Drawing..." << endl;
        }
};


// I want that i will make a base class pointer and using that i can call relevant draw methods.
void shapeDrawing (Shape *s){
    s -> draw();                          // draw is polymorphic
} 


int main(){

    // Circle C;
    // Rectangle R;

    // shapeDrawing(&C);
    // shapeDrawing(&R);

    // Triangle *t = new Triangle();
    // shapeDrawing(t);


    // without virtual keyword
    Shape *s = new Shape();
    s -> draw();

    // Upcasting
    Shape *s1 = new Circle();
    s1 -> draw();


    Circle *c = new Circle();
    c -> draw();

    // Downcasting
    Shape *s2 = new Shape();
    Circle *c2 = (Circle *)s2;
    c2 -> draw();

    return 0;
}

