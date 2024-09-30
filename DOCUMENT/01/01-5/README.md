# 이름공간의 등장 배경

프로그램이 대형화되면서 이름의 충돌 문제가 등장하였습니다. 예를 들어, 은행 관리 시스템을 개발하는 데 3개의 회사가 참여했다고 가정해 보겠습니다. 대형 프로젝트인 만큼 각 회사는 독립적으로 작업을 진행한 후, 모듈을 하나로 통합하기로 했습니다.

하지만 시간이 지나고 각 회사가 구현한 모듈을 통합하려고 하니, BestCom에서 정의한 함수의 이름과 ProgCom에서 정의한 함수의 이름이 같았습니다! 이로 인해 팀장 간의 갈등이 발생하였습니다. "우리는 매우 바쁘니, 당신네 회사에서 양보해 주셔야 합니다!"라는 식의 주장입니다.

그러나 이 문제는 더욱 심각해졌습니다. HybridCom사에서 구현한 함수들도 BestCom과 ProgCom의 함수 이름과 겹쳤습니다. 결과적으로 제한된 시간 안에 프로젝트는 완성되지 않았고, 프로젝트는 실패로 돌아갔습니다.

## 해결책

함수와 변수의 이름을 미리 정해 충돌이 발생하지 않도록 하는 것이 해결책이 될 수 있지만, 이는 한계가 있는 방법이므로 근본적인 해결책이 되지 못합니다. 그래서 C++ 표준에서는 `이름공간(namespace)`이라는 문법을 정의하여 이러한 문제에 대한 근본적인 해결책을 제시하고 있습니다.

## 이름공간의 기본 원리

예를 들어, "철수"라는 이름을 가진 두 사람이 있다고 가정해 보겠습니다. 만약 "철수야!!"라고 부르면 어떤 철수를 부르는지 알 수 없습니다. 그러나 서로 다른 집에 살고 있다면 문제가 없습니다. "201호에 사는 철수"와 "202호에 사는 철수"로 구분할 수 있기 때문입니다.

이것이 이름공간의 기본 원리입니다.

### 예제 코드

```cpp
#include <iostream>

namespace BestComImp1 {
    void SimpleFunc(void) {
        std::cout << "BestCom이 정의한 함수" << std::endl;
    }
}

namespace ProComImp1 {
    void SimpleFunc(void) {
        std::cout << "ProgCom이 정의한 함수" << std::endl;
    }
}

int main(void) {
    BestComImp1::SimpleFunc(); // 이름공간 안에 정의된 함수 호출
    ProComImp1::SimpleFunc();
    return 0;
}
```

### 실행 결과
```
BestCom이 정의한 함수
ProgCom이 정의한 함수
```

위 예제에서 사용된 `::` 연산자는 '범위 지정 연산자(Scope resolution operator)'로, 이름공간을 지정할 때 사용됩니다.

## 이름공간 기반의 함수 선언과 정의 구분

일반적으로 함수는 선언과 정의를 분리하는 것이 일반적입니다. 함수의 선언은 헤더파일(.h)에, 정의는 소스파일(.cpp 등)에 저장하는 것이 보통입니다.

### 예제 코드

**헤더 파일 (`SimpleFunc.h`)**:
```cpp
namespace BestComImp1 {
    void SimpleFunc(void);
}

namespace ProComImp1 {
    void SimpleFunc(void);
}
```

**소스 파일 1 (`SimpleFunc.cpp`)**:
```cpp
#include "SimpleFunc.h"
#include <iostream>

void BestComImp1::SimpleFunc(void) {
    std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProComImp1::SimpleFunc(void) {
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}
```

**소스 파일 2 (`SimpleFuncMain.cpp`)**:
```cpp
#include "SimpleFunc.h"
#include <iostream>

int main(void) {
    BestComImp1::SimpleFunc();
    ProComImp1::SimpleFunc();
    return 0;
}
```

## 이름공간의 중첩

이름공간은 다른 이름공간 안에 삽입될 수 있습니다.

### 예제 코드

```cpp
#include <iostream>

namespace Parent {
    int num = 2;
    namespace SubOne {
        int num = 3;
    }
    namespace SubTwo {
        int num = 4;
    }
}

int main(void) {
    std::cout << Parent::num << std::endl;        // 2
    std::cout << Parent::SubOne::num << std::endl; // 3
    std::cout << Parent::SubTwo::num << std::endl; // 4
    return 0;
}
```

## `std` 이름공간

C++ 표준 라이브러리에서 제공하는 요소들은 이름공간 `std`에 선언되어 있습니다.

- `std::cout`
- `std::cin`
- `std::endl`

따라서, 다음과 같은 이름공간의 구성을 이해할 수 있습니다.

```cpp
namespace std {
    cout ...
    cin ...
    endl ...
}
```

## `using`을 이용한 이름공간의 명시

`using`을 통해 특정 이름공간 내의 요소를 쉽게 사용할 수 있습니다.

### 예제 코드

```cpp
#include <iostream>

namespace Hybrid {
    void HybFunc(void) {
        std::cout << "So simple function!" << std::endl;
        std::cout << "In namespace Hybrid!" << std::endl;
    }
}

int main(void) {
    using Hybrid::HybFunc; // HybFunc를 이름공간 Hybrid에서 찾는다.
    HybFunc(); 
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;

int main(void){
    int num;
    cin >> num;
    cout << num << endl;
    return 0;
}
```

전역적으로 사용하려면 함수 밖에 `using`을 선언해야 합니다.

## 이름공간의 별칭 지정

이름공간에 별칭을 줄 수 있습니다.

### 예제 코드

```cpp
#include <iostream>

namespace AAA {
    namespace BBB {
        namespace CCC {
            int num1;
            int num2;
        }
    }
}

int main(void) {
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    namespace ABC = AAA::BBB::CCC; // 이름공간에 별칭을 준다.
    std::cout << ABC::num1 << std::endl;
    std::cout << ABC::num2 << std::endl;
    return 0;
}
```

## 범위 지정 연산자의 또 다른 기능

지역변수의 이름이 전역변수의 이름과 같을 경우, 전역변수는 지역변수에 의해 가려집니다. 전역변수에 접근하려면 범위 지정 연산자를 사용해야 합니다.

### 예제 코드

```cpp
int val = 100; // 전역변수

int SimpleFunc(void) {
    int val = 20; // 지역변수
    val += 3; // 지역변수 val의 값 3 증가
    ::val += 7; // 전역변수 val 값 7 증가
}
```

## 오늘의 정리
- 이름공간의 정의
- 범위 지정 연산자 (::)
- 이름공간 기반의 함수 선언 및 정의 구분
- 이름공간의 중첩
- [C언어 파일의 분할 (헤더파일, 소스파일)](https://blog.naver.com/revrow2621/223330588963)
- `using`을 이용한 이름공간의 명시
- 이름공간의 별칭 지정(namespace 변수 = 대체할 namespace)
- 범위 지정 연산자(::)의 또 다른 기능
