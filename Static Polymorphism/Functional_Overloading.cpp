#include<iostream>

using namespace std;

class Add {

    public:

        // Adding two integers x and y
        int sum(int x , int y){
            cout << "Sum of 2 int : ";
            return x + y;
        }


        // Sum of 3 integers x , y and z
        int sum(int x , int y , int z){
            cout << "Sum of 3 int : ";
            return x + y + z;
        }


        // sum of 2 doubles x and y
        double sum(double x , double y){
            cout << "Sum of 2 doubles : ";
            return x + y;
        }

};


int main(){
    
    int x = 10 , y = 23;
    int z = 44;

    Add A;
    cout << A.sum(x , y) << endl;
    cout << A.sum(x , y , z) << endl;

    cout << A.sum(5.4 , 2.2) << endl;
    
    return 0;
}