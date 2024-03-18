// 사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자.(출력 결과는 교재 참조)

#include <iostream>

int main(void){
    int result;
    for (int a=1; a<6; a++){
        int b;
        std::cout<<a<<"번째 정수 입력: ";
        std::cin>>b;
        result += b;
    }
    std::cout<<"합계: "<<result<<std::endl;
    return 0;
}