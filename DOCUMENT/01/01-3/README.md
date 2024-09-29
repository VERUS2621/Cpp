
## 함수 매개변수의 디폴트 값 설정

C++에서는 함수 매개변수에 디폴트 값(Default Value)을 설정할 수 있습니다.
예를 들어:

```cpp
int MyFuncOne(int num = 7)
{
    return num + 1;
}

int MyFuncTwo(int num1 = 5, int num2 = 7)
{
    return num1 + num2;
}
```

### 함수 호출

- `MyFuncOne()` 호출 시, `num`에 7이 전달된 것으로 간주됩니다.
- `MyFuncOne(7)`과 동일하게 작동합니다.

- `MyFuncTwo()` 호출 시, `num1`에 5가, `num2`에 7이 전달된 것으로 간주됩니다.
- `MyFuncTwo(5, 7)`과 동일하게 작동합니다.

### 예제 코드

```cpp
#include <iostream>

int Adder(int num1 = 1, int num2 = 2)
{
    return num1 + num2;
}

int main(void)
{
    std::cout << Adder() << std::endl;      // 디폴트 값 사용
    std::cout << Adder(5) << std::endl;     // num1에 5, num2에 2 사용
    std::cout << Adder(5, 3) << std::endl;   // num1에 5, num2에 3 사용
    return 0;
}
```

### 실행 결과
```
3
7
8
```

### 디폴트 값 설정 규칙

- 매개변수에 디폴트 값이 설정된 경우, 호출 시 인자를 전달하지 않으면 디폴트 값이 사용됩니다.
- 인자는 **왼쪽**에서부터 채워지며, 부족한 부분은 디폴트 값으로 채워집니다.

### 원형 선언과 정의

```cpp
#include <iostream>

int Adder(int num1 = 1, int num2 = 2); // 함수 원형 선언

int main(void)
{
    std::cout << Adder() << std::endl;      // 디폴트 값 사용
    std::cout << Adder(5) << std::endl;     // num1에 5, num2에 2 사용
    std::cout << Adder(5, 3) << std::endl;   // num1에 5, num2에 3 사용
    return 0;
}

int Adder(int num1, int num2) // 함수 정의
{
    return num1 + num2;
}
```

### 디폴트 값 설정 주의 사항

- 디폴트 값은 함수의 **선언(원형)**에만 위치해야 합니다.
- 다음과 같이 일부만 디폴트 값을 설정할 수 있습니다:

```cpp
int YourFunc(int num1, int num2 = 5, int num3 = 7)
{
    // 함수 구현
}
```

### 호출 예시

```cpp
YourFunc(10);      // YourFunc(10, 5, 7)
YourFunc(10, 20);  // YourFunc(10, 20, 7)
```

### 디폴트 값 설정 불가능한 경우

다음과 같이 오른쪽 매개변수의 디폴트 값을 비우는 형태로는 디폴트 값을 지정할 수 없습니다:

```cpp
int YourFunc(int num1 = 3, int num2 = 5, int num3) { ... } // 오류
```

### 왜 오른쪽부터 채워야 할까?

- 함수에 전달되는 인자가 **왼쪽에서부터 오른쪽**으로 채워지기 때문입니다.
- 오른쪽 매개변수에 디폴트 값을 설정하면, 호출 시 인자를 빠짐없이 전달할 수 있습니다.

### 결론

디폴트 값 설정은 함수 호출의 유연성을 높여 주며, 오른쪽부터 매개변수의 디폴트 값을 채우는 것이 필수입니다. 
이는 함수의 호출 방식과 관련이 깊습니다.