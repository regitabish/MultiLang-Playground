#include <iostream>

int main(){
    //1
    int i=0;
    int& j = i;
    j = 42;
    std::cout << i << std::endl;

    //2
    const int i2 = 42;
    const int& r = i2;
}