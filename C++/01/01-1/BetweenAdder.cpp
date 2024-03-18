#include <iostream>

int main(void){

    int val1, val2;
    int result=0;
    std::cout<<"두 개의 숫자 입력: "; //두 개의 숫자를 입력 받음
    std::cin>>val1>>val2; //두 개의 숫자를 각각 val1, val2 변수에 저장함.
// std::cin>>'변수1'>>'변수2'; 다음의 구조를 통해서 연속적인 데이터의 입력을 요구할 수 있다.
    if(val1<val2) // 어떤 숫자가 더 큰지 비교 후
    {
        for(int i=val1+1; i<val2; i++) // 작은 숫자의 다음 숫자부터 각각 더해가며 result에 값을 더해감 i++ 는 result에 숫자를 합산한 수 +1 이 되는 후행연산자이다.
        result+=i;
    }
    else
    {
        for (int i=val2+1; i<val1; i++)
        result+=i;
    }
    std::cout<<"두 수 사이의 정수 합: "<<result<<std::endl; // 그 후 결과를 통해서 result 결과 값을 std::cout<< 를 통해서 출력하고 std::endl를 통해서 개행한다.
    return 0;
}
// 또 C 언어와 비슷하게 반복문 for문의 초기화 문장 내에서 변수 선언이 가능하다.
// int num;
// for(num=0; num<10; num++){ . . . }
// 다음과 같은 한 줄로 표현이 가능하다.
// for(int num=0; num<10; num++){ . . . }