/*
2. 자연수를 입력받다가 100 이상의 값이 입력되면 평균과 합 출력하기
 - 입력 받은 값을 누적하고, 평균과 합을 계산하는 함수를 1개 작성할 것
 - 입력은 main에서 받아도 되고, 작성한 함수에서 작성해도 무방
 - 계산 결과의 출력 또한 main에서 해도 되고, 작성한 함수에서 해도 무방 
 - 최초로 100을 넘은 숫자는 합과 평균에 포함하거나 포함하지 않거나 선택하여 구현
 */
#include <iostream>
using namespace std;

void var()
{
    int num;
    int i = 0;
    int sum = 0;
    while(true)
    {
    cout << "자연수를 입력하세요 : ";
    cin >> num;
    i += 1;
    sum += num; 

    if (num >= 100) break; // 100을 넘은 숫자를 포함하는 경우로 코딩
    }
    cout << "평균은 : " << sum/i << endl;
    cout << "총 숫자의 합은 : " << sum << endl;

}

int main()
{
    var();
    return 0;
}