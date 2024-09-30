#include <iostream>
#include <string.h>
#include <stdlib.h> // C++에서도 C언어의 헤더파일을 추가하는 것도 가능하다.
using namespace std;

char * MakeStrAdr(int len)
{
    char * str=(char*)malloc(sizeof(char)*len); // 문자열 저장을 위한 배열을 힙 영역에 할당하고 있다.
    return str;
}

int main(void)
{
    char * str=MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str); // 힙에 활당된 메모리 공간을 소멸하고 있다.
    return 0;
}
// 할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다.
// 반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 한다.