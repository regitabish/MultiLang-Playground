#include<iostream>
class A{
public:
    A();
    ~A();
};

A::A(){
    std::cout << "コンストラクタ" << std::endl;
}

A::~A(){
    std::cout << "デストラクタ"<< std::endl;
}

int main(){
    A a;
    std::cout << "Main関数" << std::endl;
}