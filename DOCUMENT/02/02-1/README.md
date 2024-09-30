# 자료형 bool 
#### '참'을 의미하는 `true`와 '거짓'을 의미하는 `false`

`bool` 형은 C언어에는 존재하지 않고, C++ 에만 존재하는 자료형이었다. 
그러나 C의 최근 표준에서는 `bool`을 기본자료형에 추가하였다. 
하지만 여전히 `bool`은 C++의 기본자료형으로 인식되는 경우가 많다. 여전히 상당수의 C 컴파일러가 `bool`을 지원하지 않기 때문이다.

C와 C++ 모두, 정수 0은 '거짓'을 의미하는 숫자, 그리고 0이 아닌 모든 정수는 '참'을 의미하는 숫자로 정의하고 있다. 
따라서 참과 거짓의 표현을 위해서 다음과 같이 상수를 정의하는 것이 보통이다.

```c
#define TRUE 1
#define FALSE 0
```

이러한 참과 거짓의 표현방법은 C++ 에서도 여전히 사용된다. 
그러나 C++에서는 (그리고 새로운 C 표준에서는) 참과 거짓의 표현을 위한 키워드 `true`와 `false`를 정의하고 있기 때문에, 굳이 매크로 상수를 이용해서 참과 거짓을 표현할 필요가 없다.

다음 예제에서 보이는 바와 같이 논리적인 의미의 참과 거짓이 필요한 위치에서는 키워드 `true`와 `false`를 사용할 수 있기 때문이다.

```cpp
// TrueAndFalse.cpp
#include <iostream>
using namespace std;

int main(void)
{
    int num = 10;
    int i = 0;

    cout << "true: " << true << endl;
    cout << "false: " << false << endl;
    // 키워드 true와 false를 콘솔에 출력했을 때의 출력내용을 확인하기 위한 문장이다.

    while(true)
    // C언어에서는 무한루프를 형성하기 위해서 일반적으로 숫자 1을 사용한다.
    // C++에서도 물론 숫자 1을 사용할 수 있지만, 이렇게 true를 대신 사용할 수 있다.
    {
        cout << i++ << ' ';
        if (i > num)
            break;
    }
    cout << endl;

    cout << "sizeof 1: " << sizeof(1) << endl;
    cout << "sizeof 0: " << sizeof(0) << endl;
    // 상수 1과 상수 0의 데이터 크기를 확인하기 위한 문장
    cout << "sizeof true: " << sizeof(true) << endl;
    cout << "sizeof false: " << sizeof(false) << endl;
    // 참과 거짓을 의미하는 true와 false의 크기를 확인하기 위한 문장
    return 0;
}
```

### `TrueAndFalse.cpp` 실행결과

```text
true: 1
false: 0
0 1 2 3 4 5 6 7 8 9 10
sizeof 1: 4
sizeof 0: 4
sizeof true: 1
sizeof false: 1
```

위 예제의 실행결과를 통해서 다음과 같은 잘못된 오해를 하면 안 된다 (아쉽게도 이러한 오해를 하기가 쉽다).

> true와 false는 각각 1과 0을 의미하는 키워드이다.

그런데 `true`는 1이 아니며, `false` 역시 0이 아니다. 이 둘은 ++'참'과 '거짓'을 표현하기 위한 1바이트 크기의 데이터++일 뿐이다.

다만, `true`와 `false`가 정의되기 이전에는 참을 표현하기 위해서 숫자 1을, 거짓을 표현하기 위해서 숫자 0을 사용했기 때문에 (물론 지금도 주로 그렇게 사용하고 있지만), 이 둘을 출력하거나 정수의 형태로 형 변환하는 경우에 각각 1과 0으로 변환되도록 정의되어 있을 뿐이다.

그래서 위 예제에서도 `true`와 `false`를 출력하는 경우에 각각 1과 0이 출력되었으며, 다음과 같이 정수가 와야 할 위치에 `true`와 `false`가 오는 경우에도 각각 1과 0으로 변환이 된다.

```cpp
int num1 = true; // num1 에는 1이 저장된다
int num2 = false; // num2 에는 0이 저장된다
int num3 = true + false; // num3 = 1 + 0;
```

따라서 `true`와 `false`를 굳이 숫자에 연결시켜서 이해하려 들지 않았으면 좋겠다. 
`true`와 `false`는 그 자체를 '참'과 '거짓'을 나타내는 목적으로 정의된 데이터로 인식하는 것이 바람직하다.

## 자료형 `bool`

`true`와 `false`는 그 자체로 참과 거짓을 의미하는 데이터이기 때문에, 이를 데이터의 저장을 위한 자료형이 별도로 정의되어 있는 것은 당연하다. `true`와 `false`를 가리켜 `bool`형 데이터라 한다. 그리고 `bool`은 `int`, `double`과 마찬가지로 기본 자료형의 하나이기 때문에 다음과 같이 `bool`형 변수를 선언하는 것이 가능하다.

```cpp
bool isTrueOne = true;
bool isTrueTwo = false;
```

```cpp
// DataTypeBool.cpp
#include <iostream>
using namespace std;

bool IsPositive(int num) // bool도 기본 자료형이기 때문에 함수의 반환형으로도 선언이 가능하다.
{
    if (num <= 0)
        return false;
    else
        return true;
}

int main(void)
{
    bool isPos; // bool형 변수 선언
    int num;
    cout << "Input number: ";
    cin >> num;

    isPos = IsPositive(num); // 함수 IsPositive가 반환하는 bool형 데이터를 저장하고 있다.
    if (isPos)
        cout << "Positive number" << endl;
    else
        cout << "Negative number" << endl;

    return 0;
}
```

### `DataTypeBool.cpp` 실행결과

```text
Input number: 12
Positive number
```

위 예제를 통해서 `bool`도 기본 자료형의 하나임을 알 수 있고, 다른 기본자료형과 동일한 방식으로 사용할 수 있음을 보이고 있다.
