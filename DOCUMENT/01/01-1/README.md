[C++ 개발 환경 구축](https://blog.amylo.diskstation.me/algorithm/Starting_Algorithm_with_VSCode_C++/) <br/>
[C++ 컴파일러 사이트](https://www.programiz.com/cpp-programming/online-compiler/)

C++에서는 입출력에 관련된 하기 위해서는 <br/>
#include <**iostream**> 헤더파일 선언을 추가 해야 한다. -> 표준 헤더파일의 선언에서는 확장자를 생략하기로 약속되어 있다.

# C++ 기본 입출력

## 출력하기

출력을 위해서는 `std::cout`을 사용합니다.

- **기본 사용법**
  ```cpp
  std::cout << '출력대상';
  ```

- **여러 대상 출력**
  ```cpp
  std::cout << '출력대상1' << '출력대상2' << '출력대상3';
  ```

- **`std::endl` 사용**
  `std::endl`은 개행을 추가하는 역할을 합니다.
  ```cpp
  std::cout << "Hello World!" << std::endl;
  ```

## 입력하기

데이터의 입력을 위해서는 `std::cin`을 사용합니다.

- **기본 사용법**
  ```cpp
  std::cin >> '변수';
  ```

- **여러 변수 입력**
  ```cpp
  std::cin >> '변수1' >> '변수2';
  ```

## 예제 코드

### Hello World 출력

```cpp
#include <iostream>

int main(void) {
    int num = 20;
    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello " << "World!" << std::endl;
    std::cout << num << ' ' << 'A';
    std::cout << ' ' << 3.14 << std::endl;
    return 0;
}
```

### 두 숫자의 합 구하기

```cpp
#include <iostream>

int main(void) {
    double val1;
    std::cout << "첫번째 숫자 입력: ";
    std::cin >> val1;
    
    double val2;
    std::cout << "두번째 숫자 입력: ";
    std::cin >> val2;

    double result = val1 + val2;
    std::cout << "덧셈결과 : " << result << std::endl;
    return 0;
}
```

### 두 수 사이의 정수 합 구하기

```cpp
#include <iostream>

int main(void) {
    int val1, val2;
    int result = 0;
    std::cout << "두 개의 숫자 입력: ";
    std::cin >> val1 >> val2;

    if(val1 < val2) {
        for(int i = val1 + 1; i < val2; i++)
            result += i;
    } else {
        for (int i = val2 + 1; i < val1; i++)
            result += i;
    }
    std::cout << "두 수 사이의 정수 합: " << result << std::endl;
    return 0;
}
```

### 문자열 입출력

```cpp
#include <iostream>

int main(void) {
    char name[100];
    char lang[200];

    std::cout << "이름은 무엇입니까? ";
    std::cin >> name;

    std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
    std::cin >> lang;

    std::cout << "내 이름은 " << name << "입니다.\n";
    std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;
    return 0;
}
```

## 요약

- **출력**: `std::cout << '출력대상'`
- **여러 대상 출력**: `std::cout << '출력대상1' << '출력대상2';`
- **입력**: `std::cin >> '변수';`
- **여러 변수 입력**: `std::cin >> '변수1' >> '변수2';`
