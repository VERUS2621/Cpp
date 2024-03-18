#include <iostream>
using std::cout;
using std::endl;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int main(void)
{
    AAA::BBB::CCC::num1=20;
    AAA::BBB::CCC::num2=30;

    namespace ABC=AAA::BBB::CCC; //위 처럼 이름공간에 별칭을 줄 수 있다.
    cout<<ABC::num1<<endl;
    cout<<ABC::num2<<endl;
    return 0;
}