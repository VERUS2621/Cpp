
## 함수 오버로딩 (Function Overloading)

### C 언어와 C++의 함수 정의 차이

C 언어에서는 동일한 이름의 함수를 정의할 수 없다. 예를 들어, 다음과 같은 코드는 컴파일 오류를 발생시킨다:

```c
int MyFunc(int num)
{
    num++;
    return num;
}

int MyFunc(int a, int b)
{
    return a + b;
}
```

반면 C++에서는 매개변수의 형태(자료형)와 개수에 따라 호출되는 함수를 구분할 수 있어, 동일한 이름의 함수 정의를 허용한다.
예를 들어:

```cpp
#include <iostream>

int main(void)
{
    MyFunc(20); // MyFunc(int num) 함수 호출
    MyFunc(30, 40); // MyFunc(int a, int b) 함수 호출
    return 0;
}
```

### 함수 오버로딩의 정의

C++에서는 "함수 오버로딩(Function Overloading)"이라고 하며, 이는 매개변수의 자료형 또는 개수가 다를 때 동일한 이름의 함수를 정의할 수 있음을 의미한다.

- **C 언어**: 함수 이름으로 호출 대상을 찾음
- **C++ 언어**: 함수 이름과 매개변수의 형태(자료형) 및 개수로 호출 대상을 찾음

### 함수 오버로딩 예시

```cpp
#include <iostream>

void MyFunc(void)
{
    std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
    std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b)
{
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void)
{
    MyFunc();         // MyFunc(void) 호출
    MyFunc('A');      // MyFunc(char c) 호출
    MyFunc(12, 13);   // MyFunc(int a, int b) 호출
    return 0;
}
```

### 요약 정리

- **함수 중복**: 동일한 이름의 함수가 공존할 수 있음
- **다형성**: C 언어에서는 불가능
- **Function Overloading**: 함수 중복이 가능한 범위
  - 보통 함수들 사이
  - 클래스의 멤버 함수들 사이
  - 상속 관계에 있는 기본 클래스와 파생 클래스의 멤버 함수들 사이

### 함수 중복 성공 조건

- 중복된 함수들의 이름이 동일해야 함
- 중복된 함수들의 **매개변수 타입**이 다르거나 **개수**가 달라야 함
- 반환 타입은 함수 중복과 무관
