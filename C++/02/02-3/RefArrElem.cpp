#include <iostream>
using namespace std;

int main(void)
{
    int arr[3]={1, 3, 5};
    int &ref1=arr[0];
    int &ref2=arr[1];
    int &ref3=arr[2];

    cout<<ref1<<endl;
    cout<<ref2<<endl;
    cout<<ref3<<endl;
    return 0;
} // 배열요소는(배열이 아니라, 배열의 요소는) 변수로 간주되어 참조자의 선언이 가능하다.