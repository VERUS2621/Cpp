# malloc & free -> new & delete

```cpp
#include <iostream>
#include <string.h>
#include <stdlib.h> // C++에서도 C언어의 헤더파일을 추가하는 것도 가능하다.
using namespace std;

char * MakeStrAdr(int len)
{
    char * str=(char*)malloc(sizeof(char)*len); // 문자열 저장을 위한 배열을 힙 영역에 할당하고 있다.
    return str;
}

int main(void)
{
    char * str=MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str); // 힙에 활당된 메모리 공간을 소멸하고 있다.
    return 0;
}
```

위 예제는 C언어에서의 동적할당을 보이기 위한 것이다. (malloc, free 사용법을 알고 있다고 가정)
[C언어 동적할당 방법(malloc & free)](https://blog.naver.com/revrow2621/223338770720)

그런데 위 방법에는 두 가지 불편한 상황이 있다.

- 할당할 대상의 정보를 무조건 바이트 크기 단위로 전달해야 한다.
- 반환형이 void 포인터 형이기 때문에 **적절한 형 변환**을 거쳐야 한다.

그런데 C++ 에서 제공하는 키워드인 new & delete를 사용하면 이러한 불편한 점이 사라진다.

- int형 변수의 할당 int * ptr1=new int;
- double형 변수의 할당 double * ptr2=new double;
- 길이가 3인 int형 배열의 할당 int * arr1=new int[3];
- 길이가 7인 double형 배열의 할당 double * arr2=new double[7];
-----------------------------------------------------------
- 앞서 할당한 int형 변수의 소멸 delete ptr1;
- 앞서 할당한 double형 변수의 소멸 delete ptr2;
- 앞서 할당한 int형 배열의 소멸 delete []arr1;
- 앞서 할당한 double형 배열의 소멸 delete []arr2;

만약 할당된 영역이 배열의 구조라면 []를 반드시 추가해야 한다.

```cpp
#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrADr(int len)
{
    // char * str=(char *)malloc(sizeof(char)*len);
    char * str=new char[len];
    return str;
}

int main(void)
{
    char * str=MakeStrADr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    // free(str);
    delete []str;
    return 0;
}
```

이제는 C++ 에서는 malloc & free -> new & delete
특히, C++ 에서는 malloc와 free 함수의 호출이 문제가 될 수도 있다는 것을 기억해야 한다.

### 객체의 생성에서는 반드시 new & delete

```cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
    public:
        Simple()
        {
            cout <<"I'm simple constructor!"<<endl;
        }
};

int main(void)
{
    cout<< "case 1: ";
    Simple * sp1=new Simple; // 생성자 호출 함

    cout<< "case 2: ";
    Simple * sp2=(Simple*)malloc(sizeof(Simple)*1); // 생성자 호출 안함

    cout<<endl<<"end of main"<<endl;
    delete sp1;
    free(sp2);
    return 0;
}
```

실행결과
```
case 1: I'm simple constructor!
case 2:
end of main
```

간단히 말하면 "클래스(~구조체)를 안다고 가정했을 때"
생성자 호출이 다르다는 것을 알 수 있다.

따라서
>> new와 malloc 함수의 동작방식에는 차이가 있다.

라는 것만 알고 있으면 될것이다.

### 힙에 할당된 변수 -> 이제 포인터를 사용 X 접근 O

C++에서는 new 연산자를 이용해서 할당된 메모리 공간도 변수로 간주하여 / 참조자 선언이 가능하도록 하고 있다.

```cpp
int *ptr=new int;
int &ref=*ptr; // 힙 영역에 할당된 변수에 대한 참조자 선언
ref=20;
cout <<*ptr << endl; // 출력결과는 20!
```

포인터 연산 없이도 참조자의 선언을 통해서 힙 영역에 접근할 수 있다.

-----------------------------------------

책을 참고하는 중 좋은 문제 인거 같아 몇 문제만 참고하도록 제시함.

구조체에 대한 복습을 겸할 수 있는 문제를 제시 하겠다. 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.

```cpp
typedef struct __Point
{
    int xpos;
    int ypos;
} Point;
```
위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고(덧셈결과는 함수의 반환을 통해서 얻게 한다.)
```cpp
Point& PntAdder(const Point &p1, const Point &p2);
```
임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자. 
단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며, 할당된 메모리 공간의 소멸도 철저해야 한다.
참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할수 있어야 한다.

- 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
- 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?

[정답](homework.md)