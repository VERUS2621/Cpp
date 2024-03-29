/*
3. 구구단 a단부터 b단까지 출력하기
 - a단, b단 숫자는 main에서 받도록 한다. (단 b는 a보다 크도록 할 것)
 - 구구단을 계산하고 출력하는 것은 함수에서 가능하도록 작성할 것
*/

#include <iostream>
using namespace std;

void gugudan(int a, int b) // 계산 출력 함수에서 
{
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = a; j <= b; j++)
        {
            cout << j << " * " << i << " = " << j * i << "\t"; 
        }
        cout << endl;
    }
}

int main()
{
    int a, b;
    while (true)
    {
        cout << "a단 부터 b단 구구단을 출력합니다. a, b 순서대로 입력하세요(띄어쓰기로 구분)" << endl;
        cin >> a >> b; // a 단 b 단 main에서 받음
        if (a < b) break;
    }
    gugudan(a, b);
    return 0;
}


