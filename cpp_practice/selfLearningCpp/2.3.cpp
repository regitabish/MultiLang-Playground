#include <iostream>

struct S{
    int a;
    int b;
    int c;
};

union U{
    int a;
    int b;
    int c;
};

int main(){
    S s;
    std::cout << "s.aのアドレスは"<< &s.a << std::endl;
    std::cout << "s.bのアドレスは"<< &s.b << std::endl;
    std::cout << "s.cのアドレスは"<< &s.c << std::endl;

    S* sp;
    std::cout << "sp->aのアドレスは"<< &sp->a << std::endl;
    std::cout << "sp->bのアドレスは"<< &sp->b << std::endl;
    std::cout << "sp->cのアドレスは"<< &sp->c << std::endl;

    U u;
    std::cout << "u.aのアドレスは"<< &u.a << std::endl;
    std::cout << "u.bのアドレスは"<< &u.b << std::endl;
    std::cout << "u.cのアドレスは"<< &u.c << std::endl;

    U* up;
    std::cout << "up->aのアドレスは"<< &up->a << std::endl;
    std::cout << "up->bのアドレスは"<< &up->b << std::endl;
    std::cout << "up->cのアドレスは"<< &up->c << std::endl;

    U uInit = {42};
    std::cout << "uInit.b;" << uInit.b << std::endl;
}