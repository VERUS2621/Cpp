class SimpleClass
{
private:
    int num;
public:
    void InitNum(int n)
    {
        num=n;
    }
    int GetNum() // const 선언이 추가되어야 아래의 컴파일 에러 소멸
    {
        return num;
    }
    void ShowNum() const
    {
        std::cout<<GetNum()<<endl; // 컴파일 에러 발생
    }
}
/*
위의 클래스 정의에서 ShowNum 함수는 const 함수로 선언되었다.
그리고 실제로 함수 내에서는 멤버변수 num의 값을 변경하지 않는다.
그럼에도 불구하고 GetNum 함수를 호출하는 문장에서 컴파일 에러가 발생한다.

" const 함수 내에서는 const가 아닌 함수의 호출이 제한된다. "

const 로 선언되지 않은 함수는 아무리 멤버변수에 저장된 값을 변경하지 않더라도, 변경할 수 있는 능력을 지닌 함수이다.
따라서 이러한 변경이 가능한 함수의 호출을 아예 허용하지 않는 것이다.
*/

class EasyClass
{
private:
    int num;
public:
    void InitNum(int n)
    {
        num=n;
    }
    int GetNum() // const 선언이 추가되어야 아래의 컴파일 에러 소멸
    {
        return num;
    }
};
class LiveClass
{
private:
    int num;
public: // C++에서는 const 참조자를 대상으로 값의 변경 능력을 가진 함수의 호출을 허용하지 않는다.(실제 값의 변경여부에 상관없이)
void InitNum(const EasyClass &easy) // easy는 'const 참조자' 이다.
{
    num=easy.GetNum(); // 컴파일 에러 발생
}
};

// 따라서 const 참조자를 이용해서는 const 함수만 호출이 가능하다.