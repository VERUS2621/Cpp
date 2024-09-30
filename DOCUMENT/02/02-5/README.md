# C++에서 C언어의 표준함수 호출하기

C++ 로 프로그래밍을 하다 보면, 자신이 잘 알고 사용해온 C언어의 표준 함수를 싶을 때가 있다.
이럴 땐 어떻게 해야할 까?

## C를 더하고 .h를 빼라.

C언어의 라이브러리에는 매우 다양한 유형의 함수들이 정의되어 있다.
그런데 이러한 함수들은 C++ 표준 라이브러리에도 포함되어 있다. 따라서 어렵지 않게 사용이 가능하다.
다음은 C언어의 헤더파일에 대응하는 C++의 헤더정보를 일부만 정리한 것이다.

```cpp
#include <stdio.h> -> #include <cstdio>
#include <stdlib.h> -> #include <cstdlib>
#include <math.h> -> #include <cmath>
#include <string.h> -> #include <cstring>
```

예제를 살펴보자
```cpp
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[]="Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s: %f \n", str1, sin(0.14));
    printf("%s: %f \n", str2, abs(-1.25));
    return 0;
}
```
```cpp
// 결과
Result : 0.139543
Result : 1.250000
```

물론 stdio.h와 같은 C언어의 헤더파일을 이용해도 되지만, 가급적 C++ 의 헤더를 기반으로 예제를 작성하는 것이 좋다.

## C++의 헤더를 선언해야 하는 이유
C++ 관점에서, 여전히 다음 형태로 함수 호출을 허용하는 이유는 '하위 버전과의 호환성(backwards compatibility)' 때문이다.

```c
#include <stdio.h>
int main(void){
    printf("Hello world");
    return 0;
}
```

그리고 C++ 표준 라이브러리가 제공하는 함수들과 C 표준 라이브러리가 제공하는 함수들이 완전히 일치하는 것도 아니다.
예를 들어서 위 예제에서 호출한바 있는 abs 함수는 C 표준에서는 다음과 같다.

- int abs(int num);

반면 C++ 에서는 다음과 같이 [오버로딩](/DOCUMENT/01/01-2/README.md) 되어 있다.

- long abs(long num);
- float abs(float num);
- double abs(double num);
- long double abs(long double num);

C++ 에서는 함수 오버로딩이 가능하기 때문에 자료형에 따라서 함수의 이름을 달리해서 정의하지 않고
보다 사용하기 편하도록 함수를 오버로딩 해 놓은 것이다.
이렇듯 C++ 문법을 기반으로 개선된 형태로 라이브러리가 구성되어 있으므로, 가급적 C++ 표준 헤더를 이용해서 함수를 호출하는 것이 좋다.


