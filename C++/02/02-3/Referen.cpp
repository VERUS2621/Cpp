#include <iostream>
using namespace std;

int main(void)
{
    int num1=1020;
    int &num2=num1;

    num2=3047; 
// 결국에는 num1, num2 가리키는 게 같으므로 같은 메모리 공간에서 값을 지우고 넣은 것.
    cout<<"VAL: "<<num1<<endl;
    cout<<"REF: "<<num2<<endl;

    cout<<"VAL: "<<&num1<<endl;
    cout<<"REF: "<<&num2<<endl;
    return 0;
}