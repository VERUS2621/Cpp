#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout<<"So simple function!"<<std::endl;
        std::cout<<"In namespace Hybrid!"<<std::endl;
    }
}

int main(void)
{
    using Hybrid::HybFunc; // 위 선언은 HybFunc를 이름공간 Hybrid에서 찾으라 라는 일종의 선언이다.
    HybFunc(); 
    return 0;
}
