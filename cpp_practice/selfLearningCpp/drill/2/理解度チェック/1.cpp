#include <iostream>
class vector3d{
    
public:
    using T = int;
    void setVector(T x,T y,T z);
    T getX(){
        return x;
    }
    T getY(){
        return y;
    }
    T getZ(){
        return z;
    }
private:
    T x;
    T y;
    T z;
};

void vector3d::setVector(T newx,T newy,T newz=0){
    x = newx;
    y = newy;
    z = newz;
}

int main(){
    int x=10, y=10, z;
    vector3d v;
    v.setVector(x,y);
    std::cout << v.getX() << "," << v.getY() << "," << v.getZ() << std::endl;
    std::cin >> x >> y >> z;
    v.setVector(x,y,z);
    std::cout << v.getX() << "," << v.getY() << "," << v.getZ() << std::endl;
}