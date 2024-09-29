// 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.

#include <iostream>

int main(void){
    char a[100];
    char b[100];
    std::cout<<"사용자의 이름을 입력해주세요 :";
    std::cin>>a;
    std::cout<<"사용자의 전화번호를 입력해주세요 :";
    std::cin>>b;

    std::cout<<"사용자의 이름은 " << a << " 입니다 \n";
    std::cout<<"사용자의 전화번호는 " << b << " 입니다."<<std::endl;
}