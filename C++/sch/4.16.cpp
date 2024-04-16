// Circle 클래스를 완성할 것
// Main 함수를 작성하라
/* Circle 객체 배열 (3칸 크기)을 선언하라
반지름 값을 사용자로부터 입력 받을 수 있도록 구현
면적이 100보다 큰 원의 개수를 출력하도록 하라
*/

#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    void setRadius(int radius)
    {
        radius = radius;
    }
    double getArea();
};

double Circle::getArea()
{
    return radius*radius*3.14;
}

int main(void)
{
    Circle red[3];
    for (int i=0; i<4; i++)
    {
        int k = 0;
        cin >> k;
        red[i].setRadius(k);
    }
    int num=0;
    

    return 0;
    
}