#include<iostream>
int main(){
    auto showValue = [](int a){
        std::cout << a << std::endl;
    };
    int a = 42;
    showValue(a);
}