/*
 4. 크기가 100인 배열에 키보드로 입력을 받다가 0이 입력되면 반대 순서로 배열 출력하기
 - 배열에 입력하는 코드는 함수에 구현할 것 (반드시 100개 원소를 다 채울 필요가 없음)
 - 입력 값 중 0 이 입력되면 입력을 중지하도록 구현
 - 배열을 반대로 출력하는 코드는 main에 구현할 것 
*/

#include <iostream>
using namespace std;

int arr(int arr[])
{
        int size = 0;
        for (int i=0; i < 100; i++)
        {
            cout << "배열의 들어갈 숫자를 입력하세요: " << endl;
            cin >> arr[i];
            size += 1; // 입력된 갯수
            if (arr[i] == 0) break; // 0 입력되면 입력 중지
        }
    return size;
    
}

int main()
{
    int arr_input[100];

    int size = arr(arr_input);
    
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr_input[i] << "\t";
    }
    cout << endl;

    return 0;
}