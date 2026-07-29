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


// abstract class
class ShoppingCart {

    private:
        vector<Product*>products;

    public:
        void addProduct(Product* P){
            products.push_back(P);
        }

        const vector<Product*>& getProducts(){
            return products;
        }


        int calTotalAmount(){
            double total = 0;

            for(auto product : products){
                total = total + product -> price;
            }

            return total;
        }

};

class ShoppingCartPrinter {

    private:
        ShoppingCart* sc;

    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this -> sc = cart;
        }

        void printInvoice(){
            cout << "Shopping Cart Invoice" << endl;

            for(auto product : sc -> getProducts()){
                cout << product -> name << " -$" << product -> price << endl;
            }

            cout << "Total Amount : " << sc -> calTotalAmount() << endl;
        }
};


class DBPersistence {
    private:
        ShoppingCart* sc;

    public:

        virtual void saveToDB(ShoppingCart* cart) = 0;
};


class MySQLDBStorage : public DBPersistence {

    public:

        void saveToDB(ShoppingCart* cart) override {
            cout << "Shopping cart stored in MySql Database" << endl;
        }
};


class MongoDBStorage : public DBPersistence {

    public:

        void saveToDB(ShoppingCart* cart) override {
            cout << "Shopping Cart stored in MongoDB Database" << endl;
        }
};


int main(){

    ShoppingCart* cart = new ShoppingCart();

    cart -> addProduct(new Product({"Laptop" , 40000}));
    cart -> addProduct(new Product({"Mouse" , 1000}));

    cart -> getProducts();
    cout << endl;

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer -> printInvoice();
    cout << endl;


    DBPersistence* storeSQL = new MySQLDBStorage();
    storeSQL -> saveToDB(cart);

    DBPersistence* storeMongo = new MongoDBStorage();
    storeMongo -> saveToDB(cart);
    return 0;
}