/*
1. 1부터 n까지 홀수의 합, 짝수의 합 구하기 
 - 짝수 합을 구하는 함수 1개, 홀수 합을 구하는 함수 1개를 각각 작성할 것
 - 50 이하의 정수를 입력 받도록 구현하되 main()에서 입력 받도록 구현할 것
 - 두 개의 함수에서 결과를 바로 출력하도록 구현할 것
 */

#include <iostream>
using namespace std;

void even(int a)
{
 int even_sum = 0;
 for (int i=0; i <= a/2; i++)
 {
    even_sum += (2 * i);
 }
 cout << "짝수의 합은 : " << even_sum << endl;
}

void odd(int b)
{
 int odd_sum = 0;
 for (int i=0; i <= b/2; i++)
 {
    odd_sum += (2 * i + 1);
 }
 cout << "홀수의 합은 : " << odd_sum << endl;
}

int main(void)
{
    int num; // 숫자 n
    
    cout << "50 이하의 정수를 입력하세요 : ";
    cin >> num;
    
    while(true)
    {
    if (num > 50) continue; // 조건 위배시 계속 무한 루프
    else break; // 아닐 경우 진행
    };
    
    odd(num); // 결과 바로 출력
    even(num);
   
    return 0;
}