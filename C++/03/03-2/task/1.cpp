#include <iostream>
using namespace std;

class Calculator
{
private:
    float num1;
    float num2;
    int countAdd=0;
    int countMin=0;
    int countDiv=0;
    int countMul=0; // 클래스 변수 선언할 때 0으로 초기화
public:
    void Init(){} // 멤버 변수를 초기화 하는 역할이지만 포인터로 연결하지 않았기 때문에
    // 위 형태 그대로 복붙해서 0으로 초기화 하면 지역변수로 함수 내에서만 초기화 됨
    // 따라서 Init 함수로 초기화 할거면 클래스 변수랑 포인터 연결을 해줘야함.
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