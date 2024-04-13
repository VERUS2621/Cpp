#include <iostream>
using namespace std;

class Calculator
{
private:
    float num1;
    float num2;
    int countAdd;
    int countMin;
    int countDiv;
    int countMul; 
public:
    void Init()
    {
    countAdd=0;
    countMin=0;
    countDiv=0;
    countMul=0; // 클래스 변수 선언할 때는 초기화 불가함. (파이썬은 가능)
    } // 생성자로 변수 초기화
    float Add(float num1, float num2)
    { 
        countAdd += 1; 
        return num1+num2;
    }
    float Min(float num1, float num2)
    { 
        countMin += 1; 
        return num1-num2;
    }
    float Mul(float num1, float num2)
    { 
        countMul += 1;
        return num1*num2;
    }
    float Div(float num1, float num2)
    { 
        countDiv += 1;
        return num1/num2;
    }
    void ShowopCount()
    {
        cout << "덧셈 : " << countAdd << " 뺄셈 : "<< countMin << " 곱셈 : "<< countMul << " 나눗셈 : " << countDiv << endl;
    }

};

// 메인함수는 형태가 바뀌면 안됨 (조건)
int main(void)
{
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout<<"3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout<<"2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout<<"4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowopCount();


    Calculator cal1;
    cal1.Init();
    cout<<"3.2 + 2.4 = " << cal1.Add(3.2, 2.4) << endl;
    cout<<"3.5 * 1.7 = " << cal1.Mul(3.5, 1.7) << endl;
    cout<<"2.2 - 1.5 = " << cal1.Min(2.2, 1.5) << endl;
    cout<<"4.9 / 1.2 = " << cal1.Div(4.9, 1.2) << endl;
    cal1.ShowopCount();
    return 0;
}