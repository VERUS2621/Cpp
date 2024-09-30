#include <iostream>
using namespace std;

int main(void)
{
    int num=12;
    int *ptr=&num;
    int **dptr=&ptr;
    
    int &ref=num;
    int *(&pref)=ptr;
    int **(&dpref)=dptr; 
// 포인터 변수의 참조자 서언도 & 연산자를 하나 더 추가하는 형태로 진행이 된다.
// 이미 잘 아는 10행의 참조자 선언과 비교하기 바란다.
    cout<<ref<<endl;
    cout<<*pref<<endl; 
// pref는 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값이 출력된다.
    cout<<**dpref<<endl; 
// dpref는 포인터 변수 dptr의 참조자 이므로, 변수 num에 저장된 값이 출력된다.
    return 0;
}