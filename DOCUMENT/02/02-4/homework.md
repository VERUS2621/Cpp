```cpp
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
    Point* result = new Point;
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
    - 역참조(포인터가 가리키는 메모리 주소에 저장된 값에 접근하는 과정)를 통해 변수 자체를 전달해야 함.

- 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가? 
    - 함수 내에서 동적 할당된 메모리를 참조 반환한다.
*/

int main(void)
{
    // 동적으로 두 개의 Point 구조체 할당
    Point *a =new Point;
    Point *b =new Point;

    cout << "Enter x and y for Point 1: ";
    cin >> a->xpos >> a->ypos;
    
    cout << "Enter x and y for Point 2: ";
    cin >> b->xpos >> b->ypos;

    Point& result = PntAdder(*a, *b); // 역참조를 통해서 전달.
    cout << "Sum: (" << result.xpos << ", " << result.ypos << ")" << endl;
    
    delete a;
    delete b;
    delete &result; // 함수 내부에서 할당된 동적 메모리 해제.
    return 0;
}
```