#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const oint &lr)
{
    if(ul.GetX()>lr.GetX() || ul.GetY()>lr.GetY())
    {
        cout <<"잘못된 위치 정보 전달" << endl;
    }
    upLeft=ul;
    lowRight=lr;
    return True;
}

void Rectangle::ShowRecInfo() CAR_CONST
{
    cout<<"좌 상단: "<<'['<< upleft.GetX() << ", ";
    cout<< upLeft.GetY() << ']'<< endl;
    cout << "우 하단: " <<'[' << lowRight.GetX() << ", ";
    cout<<lowRight.GetY()<<']'<<endl<<endl;
}