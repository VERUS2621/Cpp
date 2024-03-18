#include <iostream>

int main(void)
{
    int num = 20;
    std::cout<<"Hello World!"<<std::endl; // std::cout<< ~ print 와 비슷한 역할을 한다.
    std::cout<<"Hello "<<"World!"<<std::endl;
    std::cout<<num<<' '<<'A';
    std::cout<<' '<<3.14<<std::endl; // std::endl 은 아직 무슨 역할 인지는 모르겠으나 개행을 하는 역할을 한다고 함.
    return 0;
}