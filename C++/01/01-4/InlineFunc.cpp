#include <iostream>
using namespace std; // 다음 챕터에 나옴

inline int SQUARE(int x) // inline 함수 정의, C언어 매크로 함수
{
    return x*x;
}

int main(void)
{
    cout << SQUARE(5) << endl;
    cout << SQUARE(12) << endl;
    return 0;
}