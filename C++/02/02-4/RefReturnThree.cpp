#include <iostream>
using namespace std;

int RefRetFuncTwo(int &ref) // 반환형이 기본 자료형 int 이다!
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int num2=RefRetFuncTwo(num1);

    num1+=1;
    num2+=100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    return 0;
}