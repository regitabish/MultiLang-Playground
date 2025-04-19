#include <iostream>
class veryLongNameClass{
public:
    int id;
    using integer = int;
    void setId(integer newId);
    integer getId();
};
using C = veryLongNameClass;

void C::setId(integer newId){
    id = newId;
}
C::integer C::getId(){
    return id;
}

int main(){
    
    C c;
    c.id = 1;
    std::cout << c.id << std::endl;
    
    C c2;
    c2.setId(2);
    std::cout << c2.getId() << std::endl;
}