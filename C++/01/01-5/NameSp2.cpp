#include <iostream>

namespace BestComImp1
{
      void SimpleFunc(void);
}

namespace ProComImp1
{
       void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProComImp1::SimpleFunc();
    return 0;
}

void BestComImp1::SimpleFunc(void)
{
        std::cout<<"BestCom이 정의한 함수"<<std::endl;
}

void ProComImp1::SimpleFunc(void)
{
    std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}