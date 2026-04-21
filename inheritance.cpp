// Implementing Inheritance

#include<iostream>
#include<string>

using namespace std;

// Creating Parent Class / Superclass = Vehicle

class Vehicle {

    public:
        string name;
        string model;
        int noOFTyres;

    Vehicle(string _name , string _model , int _noOfTyres){

        cout << "Parameterised constructor for vehicle called" << endl;
        this -> name = _name;
        this -> model = _model;
        this -> noOFTyres = _noOfTyres;
    }


    // Behaviour / Methods

    void start_engine(){
        cout << "Engine is Starting for model " << this -> name << " " << this -> model << endl;
    }

    void stop_engine(){
        cout << "Engine is Stopping " << this -> name << " " << this -> model << endl;
    }
};


// Creating Sub Class = Car

class Car : public Vehicle {

    public:
        int noOfDoors;
        string transmissionType;

    Car(string _name , string _model , int _noOfTyres , int _noOfDoors , string _transmissionType) : Vehicle(_name , _model , _noOfTyres){

        cout << "Parametrised Constructor created for Car called" << endl;
        this -> noOfDoors = _noOfDoors;
        this -> transmissionType = _transmissionType;
    }


    public:
        void startAC(){
            cout << "AC is Starting of " << this -> name << " " << this -> model << endl;
        }
};


int main(){

    Vehicle A("Maruti 800" , "LXI" , 4);

    return 0;
}