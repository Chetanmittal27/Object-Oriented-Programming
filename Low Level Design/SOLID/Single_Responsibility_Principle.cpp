// Code without using SRP Principle

/*
#include<iostream>
#include<vector>
using namespace std;

class Product {

    public:
        string name;
        int price;

        Product(string name , int price){
            this -> name = name;
            this -> price = price;
        }
};


class ShoppingCart{

    private:
        vector<Product*>products;

    public:
        void addProduct(Product* P){
            products.push_back(P);
        }

        const vector<Product*>& getProducts(){
            return products;
        }

        // Calculates total price of cart
        int calculateTotal(){
            double total = 0;

            for(auto product : products){
                total = total + product -> price;
            }

            return total;
        }


        // Prints Invoice
        void printInvoice(){
            cout << "Shopping Cart Invoice" << endl;

            for(auto product : products){

                cout << product -> name << "- $" << product -> price << endl;
            }

            cout << "Total Amount is : " << this -> calculateTotal() << endl;
        }


        // Store in DB
        void saveInDB(){
            cout << "Saving Shopping Cart to Database" << endl;
        }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart -> addProduct(new Product({"Laptop" , 15000}));
    cart -> addProduct(new Product({"Mouse" , 1000}));

    cout << cart -> calculateTotal() << endl;
    cart -> printInvoice();
    cout << endl;

    cart -> saveInDB();

    return 0;
}

*/
// The above Class violating the SRP principle bcoz it is handling more than one responsibilities.



// Code using SRP Principle - Using Composition
#include<iostream>
#include<vector>

using namespace std;

class Product{
    public:
        string name;
        int price;

        Product(string name , int price){
            this -> name = name;
            this -> price = price;
        }
};


class ShoppingCart{

    private:
        vector<Product*>products;

    public:
        
        void addProduct(Product* P){
            products.push_back(P);
        }

        const vector<Product*>& getProducts(){
            return products;
        }


        // Calculates total price of cart
        int calPrice(){
            double total = 0;

            for(auto product : products){
                total = total + product -> price;
            }

            return total;
        }
};


// 2) ShoppingCartPrinters - responsible only to print Invoices
class ShoppingCartPrinter{

    private:
        ShoppingCart *sc;

    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this -> sc = cart;
        }

        void printInvoice(){
            cout << "Shopping Cart Invoice" << endl;

            for(auto product : sc -> getProducts()){
                cout << product -> name << " -$" << product -> price << endl;
            }

            cout << "Total Amount : " << sc -> calPrice() << endl;
        }
};


// 3) DBStorage - responsible only for saving in Database
class DBStorage{

    private:
        ShoppingCart* sc;

    public:
        DBStorage(ShoppingCart* cart){
            this -> sc = cart;
        }


        void savingToDB(){
            cout << "Saving Shopping Cart To Database" << endl;
        }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart -> addProduct(new Product({"Laptop" , 50000}));
    cart -> addProduct(new Product({"Keyboard" , 2000}));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);

    printer -> printInvoice();


    DBStorage* store = new DBStorage(cart);
    store -> savingToDB();


    return 0;
}