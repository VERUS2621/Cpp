# 클래스와 객체

앞서 설명한 **구조체**는 **클래스**의 일종이다.

## 클래스(Class)와 구조체(struct)의 차이점

키워드 struct 대신 class를 사용하면, 구조체 대신 클래스가 된다.

```cpp
class Car
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState() { . . . . }
    void Accel() { . . . . }
    void Break() { . . . . }
};
```

키워드만 바뀐 것이 코드상의 유일한 차이점이다.
그런데 이렇게 키워드를 바꿔놓으면 다음의 방식으로 변수(구조체 변수)를 선언하지 못한다.

Car run99 = {"run99", 100, 0}; (X)

이유는 클래스 내에 선언된 함수가 아닌, 다른 영역에서 변수를 초기화하려 했기 때문이다.
클래스는 기본적으로(별도의 선언을 하지 안흥면) 클래스 내에 선언된 변수는 클래스 내에 선언된 함수에서만 접근 가능하다.
따라서 다음과 같이 클래스 변수를 선언해야 한다.

Car run99;

따라서 클래스는 접근과 관련해서 별도의 선언을 하여 클래스 내에서 변수를 초기화 해야 한다.

## 접근제어 지시자(접근제어 레이블)

C++의 접근제어 지시자는 다음과 같이 3가지가 존재한다.

- public : 어디서든 접근허용
- private : 클래스 내(클래스 내에 정의된 함수)에서만 접근허용
- protected : 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용

예제를 통해서 살펴보자
```cpp
#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN=20, MAX_SPD=200, FUEL_STEP=2,
        ACC_STEP=10, BRK_STEP=10
    };
}

class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(const char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(const char * ID, int fuel) 
// 변수는 동일 클래스 내에 정의된 함수이므로 접근 가능
{ // 클래스 함수는 public 이므로 main 함수에서 호출이 가능하다. 따라서 main에서 함수 호출해서 변수 초기화 가능
    strcpy(gamerID, ID);
    fuelGauge=fuel;
    curSpeed=0;
}
/*
void Car::InitMembers(const char * ID, int fuel) 
// 노란줄은 C++에서 문자열 상수는 변경할 수 없는 상수 이므로
// 이러한 상수를 가리키는 포인터를 변경하려고 할 때 경고가 발생함 
/ 안정성을 보장하기 위해, 변경하지 않음을 나타내는 const 상수
*/
void Car::ShowCarState()
{
    cout<<"소유자ID: "<<gamerID<<endl;
    cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<curSpeed<<"km/s"<<endl<<endl;
}
void Car::Accel()
{
    if(fuelGauge<=0)
        return;
    else
        fuelGauge-=CAR_CONST::FUEL_STEP; // 연료 감소

    if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD)
    {
        curSpeed=CAR_CONST::MAX_SPD; // 최대 속도로 조절
        return;
    }

    curSpeed+=CAR_CONST::ACC_STEP;
}
void Car::Break()
{
    if(curSpeed<CAR_CONST::BRK_STEP)
    {
        curSpeed=0;
        return;
    }
    curSpeed-=CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}
```
위 예제를 통해서 다음 사실을 알 수 있다.
- 접근제어 지시자 A가 선언되면, 이 후에 등장하는 변수나 함수는 A에 해댕하는 범위 내에서 접근이 가능하다.
- 그러나 새로운 접근제어 지시자 B가 선언되면, 그 이후에 등장하는 변수나 함수는 B에 해당하는 범위 내에서 접근이 가능하다.
- 함수의 정의를 클래스 밖으로 빼도, 클래스의 일부이기 때문에, 함수 내에서는 ++private으로 선언된 변수에 접근이 가능++하다.
- **키워드 struct**를 이용해서 정의한 구조체(클래스)에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 **public으로 선언**된다.
- **키워드 class**를 이용해서 정의한 클래스에 선언된 변수와 함수에 별도에 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 **private으로 선언**된다.

위에서 설명하는 struct와 class의 **[선언에 따른 차이](/DOCUMENT/03/03-2/class&structdif.md)**가 구조체와 클래스의 유일한 차이점이다.
즉, 구조체도 클래스도 접근제어 지시자의 선언이 가능하고, 그 의미도 동일하다.


## 용어 정리

구조체 변수, 클래스 변수라는 표현은 사실 어울리지 않는다. 
왜냐하면 구조체와 클래스는 변수의 성격만을 지니는 것이 아니기 때문이다.

그래서 변수라는 표현 대신 **객체(Object)** 라는 표현을 사용한다.

따라서 위에서 선언된 "run99"는 객체이다.

그리고 클래스를 구성하는(클래스 내에 선언된) 변수를 가리켜 '멤버변수'라고 하고,
클래스를 구성하는(클래스 내에 선언된) 함수를 가리켜 '멤버함수'라고 한다.

멤버 변수
- char gamerId[CAR_CONST::ID_LEN];
- int fuelGauge;
- int curSpeed;

멤버 함수
- void InitMembers(char * ID, int fuel)
- void ShowCarState();
- void Accel();
- void Break();

멤버는 구성원이라는 의미를 가지고 있다.

## [C++에서의 파일 분할](/DOCUMENT/03/03-2/sperate.md)
