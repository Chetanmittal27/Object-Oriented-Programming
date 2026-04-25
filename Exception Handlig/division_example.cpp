#include<iostream>
using namespace std;

// Handling exception using if-else.
/*
int main(){

    int a , b;
    cin >> a >> b;

    if(b == 0){
        cout << "Divide any number by zero is not possible" << endl;
        return 0;
    }

    int c = a / b;
    cout << c;

    return 0;
}

*/



// Handling exception using try-catch

int main(){

    int a , b;
    cin >> a >> b;

    try{
        if(b == 0){
            throw "Division by zero is not possible";
        }

        int c = a / b;
        cout << c << endl;
    }

    catch(const char *err){
        cout << "Exception thrown : " << err << endl;
    }


    return 0;
}