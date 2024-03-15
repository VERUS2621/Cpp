/* 덧셈, 뺼셈, 곱셈, 나눗셈, 나머지의 정수 5칙 연산을 할 수 있는 프로그램을 작성하라. 
식은 다음과 같은 형식으로 입력된다. 정수와 연산자는 하나의 빈칸으로 분리된다.
3 + 6 과 같은 형태로 입력함
0 1 2(연산기호) 3 4*/

#include <iostream>

using namespace std;

int main(){
    char abc[10];
    cin.getline(abc, 100);
    while(true){
        a = int(abc[0]);
        b = int(abc[4]); 
        if("+" = abc[2]){
            cout<<a+b<<endl;
        }
    }

}