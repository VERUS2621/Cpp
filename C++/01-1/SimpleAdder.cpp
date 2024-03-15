#include <iostream>

int main(void){

    double val1;
    std::cout<<"첫번째 숫자 입력: "; // std::cout<< 를 통해서 출력함
    std::cin>>val1; // std::cin>> 을 통해서 변수 val1에 숫자를 저장함.
    
    double val2;
    std::cout<<"두번째 숫자 입력: "; // std::cout<< 를 통해서 출력함.
    std::cin>>val2; // std::cin>> 를 통해서 변수 val2에 숫자를 저장함.

    double result=val1+val2; // 변수를 선언하여 두 개의 숫자의 합을 더한 후 변수에 저장함.
    std::cout<<"덧셈결과 : "<<result<<std::endl; // std::cout<< 를 통해서 result 변수에 저장된 숫자를 출력하고 std::endl 를 통해서 개행을 함.
    return 0;
}