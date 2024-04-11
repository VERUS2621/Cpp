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
    strcpy(message, a);
}

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