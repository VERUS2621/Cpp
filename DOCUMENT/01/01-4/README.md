
## Inline 함수의 의미

- **inline**은 `내부`를 의미하고, **line**은 `프로그램 코드라인`을 의미합니다.
- **inline 함수**는 "프로그램 코드라인 안으로 들어가 버린 함수"라고 해석할 수 있습니다.

-----------------------------
## 매크로 함수

### 장점
- 매크로 함수의 대표적인 장점은 **일반적인 함수에 비해 실행 속도에서 이점**이 있다는 점입니다.

### 단점
- 매크로 함수는 **정의하기 어렵고**, 복잡한 함수를 매크로 형태로 정의하는 데 한계가 있습니다.

### 매크로 함수의 정의
- 매크로 함수는 함수처럼 인자를 설정할 수 있는 매크로입니다.
- 매크로 함수 이름에 괄호와 인자 목록이 있습니다.
- 매크로 함수는 단순히 치환만 하므로 실제 함수는 아닙니다.
- 자료형에 독립적이며, 매크로 내부에서 자기 자신을 호출할 수 없습니다.

### C 언어에서의 매크로 함수 정의

```c
#define ADD(a,b) a+b // 예시
#include <stdio.h>

#define MUL1(x,y) x*y
#define MUL2(x,y) (x)*(y)

int main()
{
    int num1 = 5;
    int num2 = 4;

    printf("매크로 함수(MUL1) : %d * %d = %d\n", num1 + 1, num2 + 1, MUL1(num1 + 1, num2 + 1));  
    // num1 + 1 * num2 + 1로 변환
    
    printf("매크로 함수(MUL2) : %d * %d = %d\n", num1 + 1, num2 + 1, MUL2(num1 + 1, num2 + 1));  
    // (num1 + 1) * (num2 + 1)로 변환

    return 0;
}
```

### 출력 결과
```
10
30
```

### 매크로 함수 예제 (C++)

```cpp
#include <iostream>
#define SQUARE(x) ((x)*(x))

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    return 0;
}
```

### 전처리 과정 후의 코드

```cpp
#include <iostream>
#define SQUARE(x) ((x)*(x))

int main(void)
{
    std::cout << ((5)*(5)) << std::endl; // SQUARE(5) -> ((5)*(5))
    return 0;
}
```
-----------------------------------------
### 인라인 함수

- 매크로 함수의 장점은 살리되, 단점을 제거하고 싶다는 욕구를 충족시키는 것이 바로 C++의 **인라인 함수**입니다.
-> 사실 완전히 장점을 다 살리지는 못했다.

### C++의 인라인 함수 정의

```cpp
#include <iostream>
using namespace std;

inline int SQUARE(int x) // inline 함수 정의
{
    return x * x;
}

int main(void)
{
    cout << SQUARE(5) << endl;
    cout << SQUARE(12) << endl;
    return 0;
}
```

### 실행 결과
```
25
144
```

### 매크로 함수와 인라인 함수의 차이

- 매크로 함수는 **전처리기**에 의해 처리되지만, 인라인 함수는 **컴파일러**에 의해 처리됩니다.

컴파일러는 함수의 인라인화가 오히려 성능에 해가 된다고 판단할 경우 -> 키워드를 무시해버리기도 함.
또, 필요한 경우 일부 함수를 임의로 인라인 처리하기도 함.

![전처리기 <-> 컴파일러 차이](/DOCUMENT/01/01-4/preprocessor-compiler-dif.md)

### 매크로 함수의 장점 (자료형 독립성)

```cpp
#define SQUARE(x) ((x)*(x)) // 자료형에 의존적이지 않음

cout << SQUARE(5);    // int형 함수 호출
cout << SQUARE(3.15); // double형 함수 호출
```

```
cout << ((12)*(12));
cout << ((3.15)*(3.15));
```


- 위의 경우 매크로 함수인 경우 -> 데이터 손실이 이루어 지지 않음

### 인라인 함수의 한계

```cpp
inline int SQUARE(int x) { return x * x; }

std::cout << SQUARE(3.15); // 0.15가 손실되어 9가 출력
```

```
std::cout << SQUARE(3.15) // 0.15가 손실되어서 3*3의 결과인 9가 출력된다.
```

- 함수의 오버로딩을 통해 해결할 수 있지만, 여러 개의 함수를 추가로 정의해야 합니다.
-> 한번만 정의하면 되는 매크로 함수와의 장점과는 거리가 멀어짐.

### C++ 템플릿을 이용한 자료형 독립적 함수

```cpp
#include <iostream>
using namespace std;

template <typename T>
inline T SQUARE(T x) { return x * x; }

int main(void)
{
    cout << SQUARE(5.5) << endl;
    cout << SQUARE(12) << endl;
    return 0;
}
위 코드를 실행해보면, 데이터의 손실이 발생하지 않음을 알 수 있다.

## 요약 정리

### Inline 함수는 코드라인에 직접 삽입되는 함수로, 성능 향상을 목적으로 사용됨.

- 매크로 함수는 전처리기에 의해 처리되며, 자료형에 독립적이나 정의가 어려움.
- 인라인 함수는 컴파일러에 의해 처리되며, 성능을 저해할 경우 무시될 수 있음.
##### **매크로 함수 <-> 인라인 함수**
매크로 함수는 데이터 손실 없이 다양한 자료형을 처리하지만, 인라인 함수는 오버로딩이 필요함.

C++의 템플릿을 사용하면 자료형에 독립적인 인라인 함수 정의가 가능함.