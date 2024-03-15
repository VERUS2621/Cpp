// 예제 DefaultValue3.cpp 에 정의된 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌,
// '함수 오버로딩' 의 형태로 재 구현해보자. 물론 main 함수는 변경하지 않아야 하며, 실행결과도 동일해야 한다.

#include <iostream>
int BoxVolume(int length, int width=1, int height=1);
int BoxVolume(int length, int width, char height);
int BoxVolume(int length, char width, char height);
int main(void)
{
    std::cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5, 'D')<<std::endl;
    std::cout<<"[7, D, D] : "<<BoxVolume(7, 'D', 'D')<<std::endl;
   // std::cout<<"[D, D, D]"<<BoxVolume()<<std::endl;
    return 0;
}

int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}
int BoxVolume(int length, int width, char height)
{
    if (height == 'D'){
        height = 1;
    }
    return length*width*height;
}
int BoxVolume(int length, char width, char height)
{
    if (height == 'D'){
        height = 1;
    }
    if (width == 'D'){
        width = 1;
    }
    return length*width*height;
}