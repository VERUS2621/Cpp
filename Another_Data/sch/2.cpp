/* 덧셈, 뺼셈, 곱셈, 나눗셈, 나머지의 정수 5칙 연산을 할 수 있는 프로그램을 작성하라. 
식은 다음과 같은 형식으로 입력된다. 정수와 연산자는 하나의 빈칸으로 분리된다.
3 + 6 과 같은 형태로 입력함
0 1 2(연산기호) 3 4*/

#include <iostream>
#include <sstream> // 문자열 스트림을 사용하기 위한 헤더 파일
using namespace std;

int main(){
    char abc[10];
    int a, b;
    char op;

    cout << "식을 입력하세요: ";
    cin.getline(abc, 10); // 길이가 10인 문자열을 abc 변수에 저장함.

    // 문자열 스트림을 사용하여 문자열을 분리하고 정수로 변환
    stringstream ss(abc); // abc라는 문자열을 가지고 있는 'stringstream' 객체 'ss'를 생성, 이 객체로 문자열을 스트림 처리할 수 있음
    ss >> a >> b >> op; // 입력된 연산의 순서에 관계없이 각 값들은 적절한 변수에 할당됨

    // 연산자에 따라 적절한 연산 수행
    switch(op) {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            // 나눗셈 전에 0으로 나누는지 확인
            if (b != 0)
                cout << a / b << endl;
            else
                cout << "0으로 나눌 수 없습니다." << endl;
            break;
        case '%':
            // 나머지 연산 전에 0으로 나누는지 확인
            if (b != 0)
                cout << a % b << endl;
            else
                cout << "0으로 나눌 수 없습니다." << endl;
            break;
        default:
            cout << "잘못된 연산자입니다." << endl;
    }

    return 0;
}
