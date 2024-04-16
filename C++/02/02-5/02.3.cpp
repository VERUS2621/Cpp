#include <iostream>
using namespace std;

typedef struct __Point // 구조체 선언
{
    int xpos;
    int ypos;
} Point; // 구조체를 Point 로 이름 정의

// 위 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고
// (덧셈결과는 함수의 반환을 통해서 얻게 한다)

// Point PntAdder(const Point &p1, const Point &p2)
// {
//     Point result; // 구조체 객체 선언
//     result.xpos = p1.xpos + p2.xpos;
//     result.ypos = p1.ypos + p2.ypos;
//     return result;
// };

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point* result=new Point;
    result->xpos = p1.xpos + p2.xpos; // 점 1개
    result->ypos = p1.ypos + p2.ypos; // 점 2개
    return *result; // 반환
};
// delete &result;


/*
임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자
단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며, 
할당된 메모리 공간의 소멸도 철저해야 한다. 참고로 이 문제의 해결을 위해서는
다음 두 질문에 답을 할 수 있어야 한다.

- 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
- 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가? -? 포인터
*/

int main(void)
{
    Point *a =new Point;
    Point *b =new Point;

    cin >> a->xpos;
    cin >> a->ypos;
    cin >> b->xpos;
    cin >> b->ypos;

    Point& result = PntAdder(*a, *b);
    cout << "Sum: (" << result.xpos << ", " << result.ypos << ")" << endl;
    
    delete a;
    delete b;
    return 0;
}