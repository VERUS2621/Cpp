/* 
사용자로부터 원의 개수를 입력 받을 수 있도록 구현할 것(동적배열을 할당)
원의 개수만큼 반지름도 입력 받을 수 있도록 구현
*/
#include <iostream>
using namespace std;

class Circle
{
    int radius; // 원의 반지름
public:
    void setRadius(int radius){ Circle::radius = radius; } // 클래스 변수를 함수를 통해서 초기화
    double getArea(){ return radius*radius*3.14; } // 원의 넓이를 double형으로 반환하는 함수
};


int main(void)
{
    int n=0; // 전역변수

    while(true)
    {
    cout << "원의 개수 :";
    cin >> n;
    if (n>0) {  break; }
    }
    Circle *ptr = new Circle[n]; 
    Circle *p = ptr;
    for (int i=0; i<n; i++)
    {
        int a=0;
        cout << "원 " << i+1 << "의 반지름 >> "; // 프로포트로 원에 따른 반지름 입력
        cin >> a; // 반지름 입력
        p[i].setRadius(a); // 각각 인덱스에 맞는 반지름로 함수 초기화(설정)
    }
    int count =0; // 면적이 100이 넘는 개수를 카운트 하는 변수
    for(int i=0; i<n; i++) // i 가 원의 개수만큼 반복 -> 인덱스 호출을 위해서
    {
        cout << p->getArea() << ' '; // p->getArea() 를 통해서 함수 호출
        if(p->getArea()>100){ count +=1; } // 만약 원의 면적이 100 초과라면 count됨.
        p++; // 주소값 +1 증가 (인덱스 증가) -> 비슷한 개념
    }
    cout << "원의 면적이 100이 넘는 원의 개수는" << count << "개 입니다." << endl;

    delete[] ptr;
}