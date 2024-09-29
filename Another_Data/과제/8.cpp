/*
8. (3월27일 수요일 실습 문제 - 강의 시간 확인 여부와 상관 없이 전원 제출)
   배열과 배열 크기를 매개변수로 받아서 배열 원소 중 가장 큰 값과 작은 값을 반환하는 함수를 각각 작성 
 - 함수 이름은 maximum(), minimum()으로 한다. 
 - 배열: array[10] = { 9, 5, 11, 4, 1, 3, 7, 12, 2, 8 };
   (1) 함수를 작성하라. (함수 원형은 선언 하지 않아도 무방)
   (2) main에서 배열을 선언하고, 함수를 호출한 후 다시 main에서 결과를 출력하도록 하여 코드를 완성할 것
*/
#include <iostream>
using namespace std;

int maximum(int *p, int a)
{
  int max = p[0]; // 초기값
  for (int b=0; b < a; b++)
  {
    if (max < p[b])
    {
      max = p[b];
    }
  }
  return max;
}

int minimum(int *p, int a)
{
  int min = p[0]; // 초기값
  for (int b=0; b < a; b++)
  {
    if (min > p[b])
    {
      min = p[b]; 
    }
  }
  return min;
}

int main()
{
  int array[10] = { 9, 5, 11, 4, 1, 3, 7, 12, 2, 8 };
  cout << "가장 큰 값 : " << maximum(array, 10) << endl; // main 함수에서 함수 실행 후 결과를 출력
  cout << "가장 작은 값 : " << minimum(array, 10) << endl;

}