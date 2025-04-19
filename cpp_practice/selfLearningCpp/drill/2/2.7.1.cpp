#include <iostream>
void showValue(int a){
    std::cout << a << std::endl;
}

int sum(int a,int b,int c,int d){
    return a+b+c+d;
}

int sum(int a,int b,int c){
    return sum(a,b,c,0);
}

int sum(int a,int b){
    return sum(a,b,0);
}

int main(){
    int x = sum(10,10);
    showValue(x);

    int y = sum(10,10,10);
    showValue(y);

    int z = sum(10,10,10,10);
    showValue(z);
}