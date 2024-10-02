// 교재 문제 03-1
// 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.

#include <iostream>
using namespace std;

struct Point
{
    int xpos;
    int ypos;

    void MovePos(int x, int y); // 점의 좌표이동
    void AddPoint(const Point &pos); // 점의 좌표증가
    void ShowPosition() // 현재 x, y 좌표정보 출력
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    };
};
void Point::MovePos(int x, int y)
{
    xpos += x;
    ypos += y;
};
void Point::AddPoint(const Point &pos)
{
    xpos += pos.xpos;
    ypos += pos.ypos;
};


int main(void)
{
    Point pos1={12, 4};
    Point pos2={20, 40};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition(); // [5, 14] 출력

    pos1.AddPoint(pos2);
    pos1.ShowPosition(); // [25, 44] 출력
    return 0;
}