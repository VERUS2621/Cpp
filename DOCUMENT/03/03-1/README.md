# C++ 구조체 

## 구조체 등장배경

사실 C언어에서 배운 구조체하고 내용은 동일하며 사실 이미 알고 있다.
C언어로 프로그램을 구현한다면, 구조체의 정의는 항상 뒤를 따르기 때문이다.

사실 중요한 내용은 아래와 같다.

> 연관있는 데이터를 하나로 묶으면, 프로그램의 구현 및 관리가 용이하다.

소프트웨어를 단순히 표현하면 다음과 같다. 
 **소프트웨어 = 데이터의 표현 + 데이터의 처리**

따라서 **구조체는 연관 있는 데이터를 묶을 수 있느 문법적 장치** 이다.

예를 들어 레이싱 캐릭터로 등장하는 자동차를 표현한다고 하자.
그럼 자동차는 다음과 같은 유사한 정보들이 모여서 자동차가 표현되어야 한다.

- 소유주
- 연료량
- 현재속도
- 취득점수
- 취득아이템

게임 사용자가 게임을 로그아웃하면, 위의 정보는 데이터베이스(또는 파일)에 함께 저장되어야 하며, 로그인 하면, 저장된 위의 정보는 모두 복원되어야 한다.
따라서 위 정보를 이용해서 구조체를 정의하면 프로그래밍이 한결 수월해진다.

```c
struct Car
{
    char gameId[ID_LEN]; // 소유주 ID, ID_LEN은 매크로 상수
    int fuelGauge; // 연료량
    int curspeed;
// 취득 아이템, 취득 점수를 제외하고 구현하였다.
};
```

## C++ 에서의 구조체 변수 선언

C 언어에서 구조체 변수를 선언하는 방법은 다음과 같다.
```c
struct Car basicCar;
struct Car simpleCar;
```
앞에 삽입된 키워드 struct는 이어서 선언된 자료형이 구조체를 기반을 정의된 자료형임을 나타낸다.
이 키워드 struct=를 생략하려면 별도의 typedef 선언을 추가해야 한다.

하지만 C++에서는 기본 자료형 변수의 선언방식이나 구조체를 기반으로 정의된 자료형의 변수 선언 방식에 차이가 없다.
즉, C++ 에서는 별도의 typedef 선언 없이도 위와 같이 선언할 수 있다.
```cpp
Car basicCar;
Car simpleCar;
```

### 구조체 예제

```cpp
#include <iostream>
using namespace std;

#define ID_LEN  20
#define MAX_SPD 200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10

struct Car
{
    char gamerID[ID_LEN]; // 소유자 아이디
    int fuelGauge;      // 연료량
    int curSpeed;       // 현재 속도
};

void ShowCarState(const Car &car)
{
    cout<<"소유자ID: "<<car.gamerID<<endl;
    cout<<"연료량 : "<<car.fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
}

void Accel(Car &car)
{
    if(car.fuelGauge<=0)
        return;
    else
        car.fuelGauge-=FUEL_STEP; // 연료 감소

    if(car.curSpeed+ACC_STEP>=MAX_SPD)
    {
        car.curSpeed=MAX_SPD; // 최대 속도로 조절
        return;
    }

    car.curSpeed+=ACC_STEP;
}

void Break(Car &car)
{
    if(car.curSpeed<BRK_STEP)
    {
        car.curSpeed=0;
        return;
    }
    car.curSpeed-=BRK_STEP;
}

int main(void)
{
    Car run99={"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);

    Car sped77={"sped77", 100, 0};
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);
    return 0;
}
```

## 구조체 안에 함수 삽입

만약 구조체에 함수를 삽입한다면 위에 예제에서 이 부분이 달라지게 된다.

아까 위에 예제에서는 매개변수를 통해서 연산의 대상정보를 전달받았다.
그리고 함수 내에서 참조자 car(**const Car &car**)를 대상으로 연산을 한다.

```cpp
void ShowCarState(const Car &car)
{
    cout<<"소유자ID: "<<gamerID<<endl;
    cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<curSpeed<<"km/s"<<endl<<endl;
}
```

이를 통해서
```cpp
run99.Accel();
run99.ShowCarState();
run99.Break();
```
위와 같이 구조체 변수 안에 존재하는 함수로 선언된 변수에 접근하는 방법과 동일한 방식으로 함수 호출이 이루어진다.

반면 구조체 안에 삽입된 함수의 정의에는 이들 정보가 존재하지 않는다.
함수가 구조체 안에 삽입되면서 구조체 내에 선언된 **변수에 ++직접접근++**이 가능해 졌기 때문이다.

```cpp
Car run99={"run99", 100, 0};
Car sped77={"sped77", 100, 0};
```

각 구조체는 함수가 별도로 존재하지 않고 모든 구조체 변수가 하나의 함수를 공유한다.
하지만 논리적으로 각각의 변수가 자신의 함수를 별도로 지니는 같은 효과 및 결과를 보이기 때문에 잘 구분하여 이해하는 것이 좋다.

## 구조체 안에 enum 상수의 선언

위의 예제에서 매크로 상수들이 존재했다.
하지만 이 매크로 상수들은 구조체 Car에게만 의미가 있는 상수들이기 때문에, 이 상수들도 구조체 내에 포함시키는 것이 좋을 수도 있다.
(상황마다 조금씩 다르다.)

따라서 이러한 경우에는 [열거형 enum](/DOCUMENT/03/03-1/enum.md)을 이용해서 다음과 같이 구조체 내에서만 유효한 상수를 정의하면 된다.

```cpp
struct Car
{
    enum
    {
        ID_LEN      =20,
        MAX_SPD     =200,
        FUEL_STEM   =2,
        ACC_STEM    =10,
        BRK_STEP    =10
    };
    char gamerID[ID_LEN]; // 소유자 아이디
    int fuelGauge;      // 연료량
    int curSpeed;       // 현재 속도

    void ~~ 함수
};
```

## 함수는 외부로 뺄 수 있다.

우리는 함수가 포함되어 있는 C++ 구조체를 보는 순간, 다음의 정보들을 바로 알 수 있도록 코드를 짜는 것이 유리하다.
- 선언되어 있는 변수의 정보
- 정의되어 있느 함수의 정보

보통 프로그램을 분석할 때, 흐름 및 골격의 위주로 분석을 한다.
이러한 경우에는 기능만 파악하지, 함수의 세부 구현까지 신경을 쓰지 않는다.
따라서 구조체를 보는 순간, 정의되어 있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 짜는 것이 좋다.

따라서 구조체 내에 정의된 함수의 수가 많아지거나 그 길이가 길어진다면, 구조체 밖으로 함수를 빼낼 필요가 있다.

이렇게 말이다.

```cpp
struct Car
{
    void ShowCarstate();
    void Accel();
};

void Car::ShowCarstate()
{
    ....
}

voud Car::Accel()
{
    ....
}
```

즉, 함수의 원형선언은 구조체 안에 두고, 함수의 정의를 구조체 밖에 빼는 것이다.
다만 빼낸 함수가 어디에 정의되어 있는지 정보만 추가하면 된다.

구조체 안에 있는 함수는 함수를 [인라인](/DOCUMENT/01/01-4/README.md)으로 처리를 한다.
하지만 밖에 빼놓은 순간 이러한 의미가 사라지기 때문에
**inlie** 선언을 하고 싶다면 명시적으로 지시해야 한다.

