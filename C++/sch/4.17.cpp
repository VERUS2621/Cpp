/* 
사용자로부터 원의 갸수를 입력 받을 수 있도록 구현할 것(동적배열을 할당)
원의 개수만큼 반지름도 입력 받을 수 있도록 구현
*/
#include <iostream>
using namespace std;

class Circle
{
    int radius; // 원의 반지름
public:
    void setRadius(int radius){ radius = radius; }
    double getArea(){ return radius*radius*3.14; }
};

int main(void)
{
    int n=0;
    while(true)
    {
    cout << "원의 개수 :";
    cin >> n;
    Circle *ptr =new Circle[n];
    if (n>0) { break; }
    }
    Circle *ptr = ;
    for (int i=0; i<n; i++)
    {
        int a=0;
        cout << "원 " << i+1 << "의 반지름 >> ";
        cin >> p[i].setRadius(a);
}