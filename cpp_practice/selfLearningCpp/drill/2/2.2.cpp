#include <iostream>

class Product{
    int id;
    int price;
    int stock;
public:
    int getId();
    int getPrice();
    int getStock();
    void setAll(int newId,int newPrice,int newStock);
};

int Product::getId(){
    return id;
}

int Product::getPrice(){
    return price;
}

int Product::getStock(){
    return stock;
}

void Product::setAll(int newId, int newPrice, int newStock){
    id = newId;
    price = newPrice;
    stock = newStock;
}

int main(){
    Product p;
    Product* ptr = &p;
    ptr->setAll(0,100,200);
    std::cout << ptr->getId() << std::endl;
    std::cout << ptr->getPrice() << std::endl;
    std::cout << ptr->getStock() << std::endl;
}