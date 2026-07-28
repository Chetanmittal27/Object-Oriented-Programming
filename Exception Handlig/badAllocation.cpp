#include<iostream>
#include<exception>
using namespace std;

int main(){
    
    try{
        int *p = new int[1000000000000000];
        cout << "Memory allocated successfully" << endl;
        delete []p;
    }

    catch(const exception &err){
        cout << "Exception occured : " << err.what() << endl;
    }

    return 0;
}