# 이번 챕터에서는 참조자의 활용과 관련해서 이야기 한다.

앞서 참조자의 이해를 위해서 다음과 같은 코드를 수 차례 제시하였는데, 이렇게 변수와 참조자를 동시에 선언할 필요가 있는가?

```cpp
int num = 20;
int &ref = num;
```

이는 어디까지나 학습을 위한 코드이다. 참조자의 활용에는 함수가 큰 위치를 차지한다. 
따라서 함수와 관련해서 참조자를 이야기하자.

## Call-by-value vs Call-by-reference

여러분이 C언어를 공부하면서 배운 함수의 두 가지 호출방식은 다음과 같다.

- **Call-by-value** : 값을 인자로 전달하는 함수의 호출 방식
- **Call-by-reference** : 주소 값을 인자로 전달하는 함수의 호출 방식

### Call-by-value

```cpp
int Adder(int num1, int num2)
{
    return num1 + num2;
}
```

위 함수는 두 개의 정수를 인자로 요구하고 있다. 따라서 Call-by-value 기반의 함수이다.

그런데 Call-by-value의 형태로 정의된 함수의 내부에서는 함수 외부에 선언된 변수에 접근이 불가능하다. 
따라서 두 변수에 저장된 값을 서로 바꿔서 저장할 목적으로 다음과 같이 함수를 정의하면 원하는 결과를 얻을 수 없다. 
예를 한번 보자.

```cpp
void SwapByValue(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
```

위 함수를 대상으로 `main` 함수에서 실행해보자.

```cpp
int main(void)
{
    int val1 = 10;
    int val2 = 20;
    SwapByValue(val1, val2); // val1과 val2의 값이 바뀌기를 기대함
    cout << "val1: " << val1 << endl; // 10 출력
    cout << "val2: " << val2 << endl; // 20 출력
    return 0;
}
```

하지만 위의 함수를 실행하면 다음과 같은 출력 결과를 얻게 된다.

```
val1: 10
val2: 20
```

이것을 보면 `val1`과 `val2`의 값이 바뀌지 않았음을 의미한다. (즉, 함수 안 지역변수의 값만 바뀌고, 전역변수에는 영향을 주지 못함을 알 수 있다.) 
그래서 필요한 것이 **Call-by-reference** 이다.

### Call-by-reference

```cpp
void SwapByRef(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

위 함수는 두 개의 주소 값을 받아서, 그 주소 값이 참조하는 영역에 저장된 값을 직접 변경하고 있다.

```cpp
int main(void)
{
    int val1 = 10;
    int val2 = 20;
    SwapByRef(&val1, &val2); // val1과 val2의 값이 바뀌기를 기대함
    cout << "val1: " << val1 << endl; // 20 출력
    cout << "val2: " << val2 << endl; // 10 출력
    return 0;
}
```

실행 결과는 다음과 같다.

```
val1: 20
val2: 10
```

### Call-by-address? Call-by-reference!

최근 들어 주소 값을 전달하는 Call-by-reference 형태의 함수 호출이 **Call-by-address**라 불리는 경우를 종종 본다. 이는 잠시 후에 설명하는 **C++의 참조자(Reference) 기반의 함수 호출**과의 구분을 위함인데, 그럼에도 불구하고 필자는 이전의 방식, 즉, 주소 값을 전달하는 함수의 호출 형태를 가리켜 여전히 **Call-by-reference**라 표현하고자 한다. 이유는 다음 함수를 보면서 설명한다.

```cpp
int* SimpleFunc(int *ptr)
{
    // 함수 내용
}
```

여러분은 위의 함수가 어떤 종류의 함수라고 생각하는가? 아마 * 포인터가 있으니 Call-by-reference로 생각할 수 있다. 하지만 이는 **Call-by-reference**도 될 수 있고, **Call-by-value**도 될 수 있다.

#### Call-by-value 예시

```cpp
int* SimpleFunc(int *ptr)
{
    return ptr + 1; // 주소 값을 증가시켜서 반환
}
```

위 함수의 연산 주체는 값(value)이다. 다만 그 값이 **주소 값**일 뿐이다. 
주소 값에 1을 더한 결과를 반환하는 연산을 하니, 흔히 우리가 생각하는 **Call-by-reference**와는 거리가 멀다.

#### Call-by-reference 예시

```cpp
int* SimpleFunc(int *ptr)
{
    if (ptr == NULL)
        return NULL;
    *ptr = 20;
    return ptr;
}
```

이 함수에서는 주소 값을 이용해서 함수 외부에 선언된 변수를 '참조(reference)'했으니, 이는 분명 **Call-by-reference**이다.

### Call-by-reference와 Call-by-value의 구분

본래 C언어에서 말하는 **Call-by-reference**는 다음의 의미를 지닌다.

"주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출"

주소 값이 외부 변수의 참조 도구로 사용되는 **함수의 호출**을 뜻한다. 
이렇게 주소 값이 전달되었다는 사실이 중요한 게 아니라, **주소 값이 참조의 도구로 사용되었다는 사실이 중요한 것**이며, 
이것이 Call-by-value와 Call-by-reference를 구분하는 기준이 된다.

### C++에서의 두 가지 Call-by-reference 방식

C++에서는 함수 외부에 선언된 변수에 접근하는 방법으로 두 가지가 존재한다.

1. 주소 값을 이용한 방식
2. 참조자를 이용한 방식

글쓴이는 이를 이렇게 구분한다.

- 주소 값을 이용한 Call-by-reference
- 참조자를 이용한 Call-by-reference

C++에서는 두 가지 방식으로 Call-by-reference의 함수 정의가 가능하다. 그리고 실제로 여러분은 이 둘 중 어느 방식을 사용할지 고민하게 될 것이다.

### 참조자를 이용한 Call-by-reference

C++에서는 참조자를 기반으로도 Call-by-reference의 함수호출을 진행할 수 있다.
Call-by-reference의 가장 큰 핵심은 함수 내에서 함수외부에 선언된 변수에 접근할 수 있다는 것이다.

```cpp
#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
    int temp=ref1;
    ref1=ref2;
    ref2=temp;
}

int main(void)
{
    int val1 = 10;
    int val2 = 20;

    SwapByRef2(val1, val2);
    cout << "val1 : " << val1 << endl;
    cout << "val2 : " << val2 << endl;
    return 0;
}
```

위 코드에서는 ref1과 ref2는 main에서 선언된 val1과 val2의 또 다른 이름이 된다.
그리고 SwapByRef2라는 함수 내에서는 이 두 참조자를 통해서 값의 교환 과정을 거치기 때문에, 그 결과는 val1과 val2의 값의 교환으로 이어진다.

```cpp
// 결과 
val1 : 20
val2 : 19
```
이렇듯
C++에서는 Call-by-reference의 구현 방법에 참조자를 이용하는 방법과 주소 값을 이용하는 방법, 두 가지 상존한다.

## 참조자를 이용한 Call-by-reference의 황당함과 const 참조자

포인터는 잘못 사용할 확률이 높고, 참조자의 활용이 상대적으로 포인터의 활용보다 쉽기 때문에, 참조자 기반의 함수정의가 더 좋은 선택이라고 생각할 수 있다. 그러나 참조자 기반의 함수정의에 좋은 점만 있는 것은 아니다. 이와 관련해서 아래의 코드를 보자

```
int num = 24;
HappyFunc(num);
cout << num << endl;
```

C언어의 관점에서는 100% 24가 출력된다. 그러나 C++에서는 얼마가 출력될지 알 수 없다.
함수가 다음과 같이 정의가 되어 있다면 24가 출력되겠지만

- void HappyFunc(int prm) { .. .. }

다음과 같이 정의 되어 있다면, 참조자를 이용해서 num에 저장된 내부 함수를 통해 외부 변수를 변경할 수도 있는 일이기 때문이다.

- void HappyFunc(int &ref){ .. .. }

이게 바로 참조자의 단점이다.
예로 들어 코드를 분석하는 과정이 있다면, 함수의 호출문장만 보고도 함수의 특성을 어느 정도 판단할 수 있어야 한다.
그러나 참조자를 사용하는 경우, 함수의 원형을 확인해야 하고, 확인결과 참조자가 매개변수의 선언에 와있다면, 함수의 몸체까지 문장 단위로 확인해서 참조자를 통한 값의 변경이 일어나는지를 확인해야 한다.

그렇다면 이러한 단점을 어떻게 해결하면 좋겠는가? 사실 완벽한 해결은 불가능하다.
C언어에서는 함수의 호출 문장만을 보고도 값이 변경되지 않음을 판단할 수 있지만 C++에서는 이것이 불가능하다.
따라서 완벽한 해결을 원한다면, 참조자 기반의 함수정의를 하지 말아야 한다.
그러나 const 키워드를 이용하면, 이러한 단점을 "어느 정도는" 극복할 수 있다.

``` 
void HappyFunc(const int &ref){ .. .. }
```
참조자 ref에 const 선언이 추가되었다. 이는 이러한 의미를 가진다.

>> 함수 HappyFunc 내에서 참조자 ref를 이용한 값의 변경을 하지 않겠다.(상수화 하겠다.)

여기서의 const 선언으로 인해서, 참조자 ref에 값을 저장하는 경우 컴파일 에러가 발생한다. 따라서 함수 내에서 
값의 변경이 이뤄지지 않음을 확신할 수 있는 것이다.

따라서 다음의 원칙을 정하고 가급적 이 원칙을 지켜주는 것이 좋다.

**함수 내에서, 참조자를 통한 값의 변경을 진행하지 않는 경우, 참조자를 const로 선언해서, 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있게 한다.**

### 반환형이 참조형(Reference Type)인 경우

```cpp
// RefRetFuncOne
#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
    int &num2 =RefRetFuncOne(num1);

    num1++;
    num2++;
    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;
    return 0;
}
```
```결과
num1 : 4
num2 : 4
```

참조자를 선언하고 반환하는 과정을 이해하기를 바란다.
```cpp
int num =1;
int &ref = num1; // 인자의 전달과정에서 일어난 일
int &num2 = ref; // 함수의 반환과 반환 값의 저장에서 일어난 일
```
-----------------------------------
```cpp
// RefRetFuncTwo
#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref) // RefReturnOne.cpp의 RefRetFuncOne과 동일!
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int num2=RefRetFuncOne(num1); // 여기만 변경됨  int& num2 -> int num2

    num1+=1;
    num2+=100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    return 0;
}
```
``` 결과
num1 : 3
num2 : 102
```

```cpp
int num1=1;
int &ref=num1; // 인자의 전달 과정에서 일어난 일
int num2=ref; // 함수의 반환과 반환 값의 저장에서 일어난 일
// 참조가 아닌 값을 복사한 별도의 변수
```
------------------------------------------
```cpp
// RefRetFuncThree
#include <iostream>
using namespace std;

int RefRetFuncTwo(int &ref) // 반환형이 기본 자료형 int 이다!
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int num2=RefRetFuncTwo(num1);

    num1+=1;
    num2+=100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    return 0;
}
```
``` 결과
num1 : 3
num2 : 102
```

실행결과를 보면 위 2번째 예제와 차이가 없다. 또한 실행의 과정에서 일어난 일도 똑같다.
하지만 차이가 있다.
반환형이 참조형인 RefRetFuncOne 함수는 반환 값을 다음과 같이 두 가지 형태로 저장할 수 있다.

- int num2=RefRetFuncOne(num1);  (O)
- int &num2=RefRetFuncOne(num1); (O)

하지만, 반환형이 기본자료형으로 선언된 RefRetFuncTwo 함수의 반환 값은 반드시 변수에 저장해야 한다. -> 상수이기 때문에

- int num2=RefRetFuncTwo(num1);     (O) -> 반환값 상수 이므로 반드시 변수에 저장
- int &num2=RefRetFuncTwo(num1);    (X)

### 잘못된 참조의 반환

```cpp
int& RetuRefFunc(int n)
{
    int num=20;
    num+=n;
    return num;
}

위의 함수에서는 지역변수 num에 저장된 값을 반환하지 않고, num을  참조의 형태로 반환하고 있다.
따라서 다음의 형태로 함수를 호출하면

int &ref=RetuRefFunc(10);

지역변수 num에 ref라는 또 하나의 이름이 붙게 된다. 하지만 이게 끝이 아니다.
함수의 반환이 되면 정작 지역변수 num은 소멸이 된다.
따라서 위의 함수처럼 지역변수를 참조형으로 반환하는 일은 없어야 된다.

>> "에이, 잘못 구현했다면, 컴파일러가 알아서 에러메시지 던져 주겠죠~"

경고 메시지만 띄울 뿐, 에러메시지를 띄워주지는 않는다.
뿐만 아니라, 아직 채 소멸되지 않은(곧 소멸될), 찌꺼기의 형태로 남아있는 데이터를 참조해서 정상적인 출력결과를 보이기도 하니, 주의해야 한다.

### const 참조자의 또 다른 특징

```cpp
const int num=20;
int &ref=num;
ref+=10;
cout << num << endl;
```

const 선언을 통해서 변수 num을 상수화했는데, 참조자 ref를 통해서 값을 변경한다?
사실상 num 상수화는 의미가 없다. 상수화가 되었다면 어떠한 경로를 통하더라도 값의 변경을 허용하면 안된다.
그런데 다행이도 C++에서는 이를 허용하지 않는다. 위의 코드 중 다음 문장이 컴파일 에러를 일으킨다.
``cpp
int &ref = num;
```
따라서 변수 num과 같이 상수화된 변수에 대한 참조자 선언은 다음과 같이해야 한다.
'''cpp
const int num=20;
const int &ref=num;
```

이렇게 선언이 되면 ref를 통한 값의 변경이 불가능하기 때문에 상수화에 대한 논리적인 문제점은 발생하지 않는다.
그리고 const 참조자는 다음과 같이 상수도 참조가 가능하다.

```cpp
const int &ref = 5;
```

### 어떻게 참조자가 상수를 참조하는가??

int num = 20+30;

여기서 20, 그리고 30과 같은 프로그램상에서 표현되는 숫자를 가리켜 literal 또는 literal constant라 한다.
이들은 이러한 특징을 가진다.

- 임시적으로 존재하는 값 / 다음 행으로 넘어가면 존재하지 않는 상수

const int &ref=30;

이는 숫자 30이 메모리 공간에 계속 남아있을 때에 성립이 가능한 문장이다.
그래서 C++ 에서는 위의 문장이 성립할 수 있도록, const 참조자를 이용해서 상수를 참조할 때 **임시변수**라는 것을 만든다.

그럼 이러한 의문이 들 것이다.
"왜 임시변수라는 잘 와 닿지도 않는 개념까지 끌어들여서 상수의 참조가 가능하게 했대요?"

```cpp
int Adder(const int &num1, const int &num2)
{
    return num1+num2;
}
```
위와 같이 정의된 함수에 **인자의 전달을 목적으로 변수를 선언**한다는 것은 매우 번거로운 일이다.
그러나 임시변수의 생성을 통한 const 참조자의 상수 참조를 허용함으로써, 위의 함수는 다음과 같이 매우 간단하게 호출할 수 있다.

```cpp
cout << Adder(3,4) << endl;
```






