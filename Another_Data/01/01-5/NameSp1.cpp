#include <iostream>

namespace BestComImp1 // 위 이름의 공간을 마련하였다. 그 안에 함수 SimpleFunc 정의
{                     // 따라서 이 함수는 'BestComImp1::SimpleFunc' 이라고 지칭하게 된다.
    void SimpleFunc(void)
    {
        std::cout<<"BestCom이 정의한 함수"<<std::endl;
    }
}

namespace ProComImp1
{
    void SimpleFunc(void)
    {
        std::cout<<"ProgCom이 정의한 함수"<<std::endl;
    }
}

int main(void)
{
    BestComImp1::SimpleFunc(); // 이름공간 안에 정의된 함수 호출
    ProComImp1::SimpleFunc();
    return 0;
}