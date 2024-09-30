#include <iostream>
using namespace std;

bool IsPosiitive(int num) // bool도 기본자료형이기 때문에 함수의 반환형으로도 선언이 가능하다.
{
    if(num<=0)
        return false;
    else
        return true;
}

int main(void)
{
    bool isPos; // bool형 변수 선언
    int num;
    cout<<"Input number: ";
    cin>>num;

    isPos=IsPosiitive(num); // 함수 IsPositive가 반환하는 bool형 데이터를 저장하고 있다.
    if(isPos)
        cout<<"Positive number"<<endl;
    else
        cout<<"Negative number"<<endl;

    return 0;
}