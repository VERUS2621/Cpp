#include <iostream>

int Adder(int num1=1, int num2=2);

int main(void){
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(5)<<std::endl;
    std::cout<<Adder(5, 3)<<std::endl;
    return 0;
}

int Adder(int num1, int num2)
{
    return num1+num2;
}


// 디폴트 값 선언은 함수의 원형을 별도로 선언하는 경우 원형 선언에만 위치시켜야 한다.