#include <iostream>
using namespace std;

class Point
{
public:
  int x; // x좌표의 범위는 0이상 100이하
  int y; // y좌표의 범위는 0이상 100이하
}; 

class Rectangle
{
public:
  Point upLeft;
  Point lowRight;

public:
  void ShowRecInfo()
  {
    cout << "좌 상단: " << '[' << upLeft.x << ", ";
    cout << upLeft.y << ']' << endl;
    cout << "우 하단: "<<'['<< lowRight.x<<", ";
    cout << lowRight.y << ']' << endl << endl;
  }
};

int main(void)
{
  Point pos1={-2, 4}; // 초기화 리스트를 이용해서 멤버 변수 순서대로 x = -2, y = 4로 초기화후 대입함
  /*
  if Point pos1 = {-2, 4, 5} 라고 했을 때 위에 클래스 멤버 변수 선언이 3개 즉, x, y, z 라면 각각 "순서대로" 대입됨
  */
  Point pos2={5, 9}; // 초기화 리스트 사용해 멤버변수 초기화
  Rectangle rec = {pos2, pos1}; // 초기화 리스트 사용해 멤버변수 초기화
  rec.ShowRecInfo();
  return 0;
}
    
/*
1. 점의 좌표는 0이상 100이하인데 그렇지 못한 Point 객체가 있다.
2. 직사각형을 의미하는 Rectangle 객ㅊ의 좌 상단 좌표 값이 우 하단 좌표값 보다 크다. -> 두 좌표의 값이 서로 바뀐 듯 함.
실수는 누구나 할 수 있기 때문에 어떻게든 발견해야한다. -> 코드 문법적으로 문제가 없기 때문에
*/

  
