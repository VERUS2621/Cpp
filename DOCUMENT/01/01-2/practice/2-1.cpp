#include <iostream>

void swap(int a, int b){ // 각각의 변수 형태에 따라서 선언해야함. swap(int a, b) 는 틀린 형태임.
    std::cout<<b<<' '<<a<<std::endl;
}

void swap(char c, char d){
    std::cout<<d<<' '<<c<<std::endl;
}

void swap(double e, double f){
    std::cout<<f<<' '<<e<<std::endl;
}
int main(void){
    swap(20, 30);
    swap('A', 'Z');
    swap(1.111, 5.555);
    return 0;
}