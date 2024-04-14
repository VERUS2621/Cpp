#ifndef __POINT_H_
#define __POINT_H_

class Point{
private: // 멤버변수를 private를 선언함으로 써 임의로 값이 저장되는 것을 막음 -> x, y 라는 정보를 은닉함
// 값을 저장 및 참조를 위한 함수를 추가로 정의하였다. 따라서 함수 내에서 멤버변수에 저장되는 값을 제한할 수 있게됨.
    int x;
    int y;

public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);    
};
#endif