// Implementing Inheritance

#include<iostream>
#include<string>

using namespace std;

// Creating Parent Class / Superclass = Vehicle

class Vehicle {

    private:
        string name;

    public:
        // string name;
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

    string getName(){
        return this -> name;
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
            cout << "AC is Starting of " << getName() << " " << model << endl;
        }
};


int main(){

    // Vehicle A("Maruti 800" , "LXI" , 4);
    Car B("Maruti Suzuki" , "LXZZ" , 4 , 4 , "Manual");
    B.start_engine();
    B.startAC();
    B.stop_engine();

    return 0;
}



// When instance for any child class is created, then its parent class constructor is called first and after that the constructor of child class is called.