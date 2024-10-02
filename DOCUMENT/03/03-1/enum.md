# enum 열거형

enum 열거형 : 상수들의 집합을 정의할 때 사용
- 관련된 상수들을 그룹화, 각 상수에 정수 값을 자동으로 할당할 수 있음
- 가독성 up, 프로그램의 명확성 up

```cpp
enum 열거형이름 {
    상수1 = 값1,
    상수2 = 값2,
    상수3 = 값3,
    // ...
};
```
- 0부터 자동할당됨.
```c
enum Weekday {
    SUNDAY,     // 0
    MONDAY,     // 1
    TUESDAY,    // 2
    WEDNESDAY,  // 3
    THURSDAY,   // 4
    FRIDAY,     // 5
    SATURDAY    // 6
};
```
- 명시적 값 지정 가능
```c
// ex
enum 열거형이름 {
    상수1 = 1,
    상수2, // 상수2는 2로 자동 할당
    상수3 = 100,
    상수4 // 상수4는 101로 자동 할당
};
```
- 타입 지정도 가능
```cpp
#include <stdio.h>

enum TrafficLight {
    RED = 1,
    YELLOW = 2,
    GREEN = 3
};

int main() {
    enum TrafficLight signal;  // TrafficLight 타입의 변수를 선언

    signal = YELLOW;  // 올바른 할당 (열거형 내 상수 중 하나)
    printf("현재 신호는: %d\n", signal);  // 출력: 2

    // signal = 4;  // 오류 발생: 열거형에 정의되지 않은 값을 할당할 수 없음
    return 0;
}
```
