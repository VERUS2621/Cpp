#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;


void Car::InitMembers(const char * ID, int fuel) // 변수는 동일 클래스 내에 정의된 함수이므로 접근 가능
{ // 클래스 함수는 public 이므로 main 함수에서 호출이 가능하다. 따라서 main에서 함수 호출해서 변수 초기화 가능
    strcpy(gamerID, ID);
    fuelGauge=fuel;
    curSpeed=0;
}
/*
void Car::InitMembers(const char * ID, int fuel) // 노란줄은 C++에서 문자열 상수는 변경할 수 없는 상수 이므로
{// 이러한 상수를 가리키는 포인터를 변경하려고 할 때 경고가 발생함 / 안정성을 보장하기 위해, 변경하지 않음을 나타내는 const 상수
    strcpy(gamerID, ID); 
    fuelGauge=fuel;
    curSpeed=0;
}
*/
void Car::ShowCarState()
{
    cout<<"소유자ID: "<<gamerID<<endl;
    cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<curSpeed<<"km/s"<<endl<<endl;
}
void Car::Accel()
{
    if(fuelGauge<=0)
        return;
    else
        fuelGauge-=CAR_CONST::FUEL_STEP; // 연료 감소

    if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD)
    {
        curSpeed=CAR_CONST::MAX_SPD; // 최대 속도로 조절
        return;
    }

    curSpeed+=CAR_CONST::ACC_STEP;
}
void Car::Break()
{
    if(curSpeed<CAR_CONST::BRK_STEP)
    {
        curSpeed=0;
        return;
    }
    curSpeed-=CAR_CONST::BRK_STEP;
}
