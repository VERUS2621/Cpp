/* 5. 반지름 길이가 r인 원넓이 출력하기
 - 원 넓이를 계산하는 함수를 작성
 - 원 반지름은 main에서 키보드로 입력하도록 구현*/

#include <iostream>
using namespace std;
#define pi 3.14

float circle(int r) // 원 넓이 계산 함수
{
    float area = r * r * pi; 
    return area;
}

int main()
{
    float r;
    cout << "원의 반지름 길이를 입력하세요 : ";
    cin >> r; // 메인에서 입력
    
    cout << "원의 넓이 :" << circle(r) << endl;
}