//1

#include <iostream>
struct Product{
    int id;
    int price;
    int stock;
};

void show_product(Product& product){
    //std::cout << std::endl;
    std::cout << "id;" << product.id << std::endl;
    std::cout << "price;" << product.price << std::endl;
    std::cout << "stock;" << product.stock << std::endl;
}

/* int main(){
    Product p;
    Product* pen = &p;
    pen->id = 0;
    pen->price = 100;
    pen->stock = 200;
    show_product(p);
} */


//2
/* 共用体は同じメンバ変数がアドレスを持つ
構造体はメンバ変数が異なるアドレスを持つ */

//3
struct S{
    int x;
    int y;
};

union U{
    S s;
};

int main(){
    U u = {};
    u.s.x = 10;
    u.s.y = 20;
    std::cout << u.s.x << std::endl;
}
