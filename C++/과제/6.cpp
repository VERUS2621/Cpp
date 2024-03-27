/* 6. n!(n 팩토리얼)을 계산하는 프로그램 작성
 - n은 main에서 입력 받도록 구현 
 - 팩토리얼은 함수로 구현
 - 팩토리얼은 반복, 또는 순환(재귀) 중 선택하여 구현 가능*/

#include <iostream>
using namespace std;

int factorial(int a)
{
    if (a <= 1)
    {
        return 1;
    }
   else
   {
    return a * factorial(a-1);  
   }
}

int main()
{
    int n;
    cout << "팩토리얼 계산을 위한 숫자 입력 : ";
    cin >> n;
    cout << n << "! = " << factorial(n);
}