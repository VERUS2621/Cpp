// 다음과 같은 형태로의 함수 오버로딩은 문제가 있다. 어떠한 문제가 있는지 설명해보자.

int SimpleFunc(int a=10)
{
    return a+1;
}

int SimpleFunc(void)
{
    return 10;
}

SimpleFunc(); // 이런 형태에서 위 함수에 디폴트 값인지 void 값인지 구분할 수 없어 오버로딩 오류가 발생함.

SimpleFunc('숫자') // 이런 형태면 계산은 이루어짐