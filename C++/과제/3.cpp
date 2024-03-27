/*
3. 구구단 a단부터 b단까지 출력하기
 - a단, b단 숫자는 main에서 받도록 한다. (단 b는 a보다 크도록 할 것)
 - 구구단을 계산하고 출력하는 것은 함수에서 가능하도록 작성할 것
*/

#include <iostream>
using namespace std;

void gugudan(int a, int b)
{
 for (int i = a; i <= b; i++)
 {
    for(int j = 1; j<10; j++)
    {
        cout << i << " * " << j << " = " << j*i << endl;
    }
    cout << endl;
 }
}




int main()
{
    int a, b;
    cout << "a단 부터 b단 구구단을 출력합니다. a, b 순서대로 입력하세요(띄어쓰기로 구분)" << endl;;
    cin >> a >> b; 
    gugudan(a, b);
    return 0;
}

