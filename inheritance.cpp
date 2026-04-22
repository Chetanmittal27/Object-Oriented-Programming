// Implementing Inheritance

#include<iostream>
#include<string>

using namespace std;

// Creating Parent Class / Superclass = Vehicle

class Vehicle {

    protected:
        string name;
        string model;
        int noOFTyres;

    public:
    Vehicle(string _name , string _model , int _noOfTyres){

        cout << "Parameterised constructor for vehicle called" << endl;
        this -> name = _name;
        this -> model = _model;
        this -> noOFTyres = _noOfTyres;
    }


    // Behaviour / Methods
    public:
    void start_engine(){
        cout << "Engine is Starting for model " << this -> name << " " << this -> model << endl;
    }

    void stop_engine(){
        cout << "Engine is Stopping " << this -> name << " " << this -> model << endl;
    }

    string getName(){
        return this -> name;
    }

    ~Vehicle(){
        cout << "Vehicle Destructor Called" << endl;
    }

};


// Creating Sub Class = Car

class Car : public Vehicle {

    protected:
        int noOfDoors;
        string transmissionType;

    public:
    Car(string _name , string _model , int _noOfTyres , int _noOfDoors , string _transmissionType) : Vehicle(_name , _model , _noOfTyres){

        cout << "Parametrised Constructor created for Car called" << endl;
        this -> noOfDoors = _noOfDoors;
        this -> transmissionType = _transmissionType;
    }


    public:
        void startAC(){
            cout << "AC is Starting of " << name << " " << model << endl;
        }


        ~Car(){
            cout << "Car Destructor Called" << endl;
        }
};


class Motorcycle : public Vehicle {

    protected:
        string handleBarStyle;
        string suspensionType;

    public:
        Motorcycle(string _name , string _model , int _noOfTyres , string _handleBarStyle , string _suspensionType) : Vehicle(_name , _model , _noOfTyres) {

            cout << "Parameterised Constructor for Motorcycle Called" << endl;
            this -> handleBarStyle = handleBarStyle;
            this -> suspensionType = suspensionType;
        }

    public:
        void wheelie(){
            cout << "Wheelie kar rahi hai " << name << endl;
        }

        ~Motorcycle(){
            cout << "Motorcycle Destructor Called" << endl;
        }
};



int main(){

    // Vehicle A("Maruti 800" , "LXI" , 4);
    Car B("Maruti Suzuki" , "LXZZ" , 4 , 4 , "Manual");
    B.start_engine();
    B.startAC();
    B.stop_engine();

    // cout << B.name << endl;    // name is protected here

    cout << B.getName() << endl;

    Motorcycle M("Honda" , "XYZ" , 2 , "U" , "Hard");

    return 0;
}



// When instance for any child class is created, then its parent class constructor is called first and after that the constructor of child class is called.

// if some attribute in parent class is private then use concept of getter and setter to print or access that attribute . Studied this concept in Encapsulation.

// If attribute is protected then that attribute is accessible in derived classes but not to the main function.