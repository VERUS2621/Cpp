#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
char message[100];
public:
void SetString(const char a[]); // const 입력받은 문자열이 함수내에서 수정되지 않았음을 알림
void ShowString();    
};

void Printer::SetString(const char a[])
{
    strcpy_s(message, a); // strcpy를 사용하면 컴파일러가 비추천 함수를 사용할 때 경고를 출력함
}

// std::string은 C 스타일의 문자열보다 더 안전하고 편리하며, C++ 표준 라이브러리에서 제공함

/*
private:
    std::string message; // std::string을 사용하여 문자열을 저장합니다.
public:
    void SetString(const std::string& a); // std::string을 인자로 받도록 변경합니다.

void Printer::SetString(const std::string& a)
{
    message = a; // 간단히 대입 연산자를 사용하여 문자열을 복사합니다.
}
*/

void Printer::ShowString()
{
    cout << message << endl;
}
int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}