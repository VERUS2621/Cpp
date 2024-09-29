/* 다음과 같이 "yes"가 입력될 떄까지 종료하지 않는 프로그램을 작성하라.
 사용자로부터의 입력은 cin.getline 함수를 사용하라 */

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char abc[4]; // 배열 크기를 수정

    while(true){
        cin.getline(abc, 4); // 배열 크기에 맞게 수정
        abc[3] = '\0'; // 널 종단 문자 추가
        if(strcmp(abc, "yes")==0){
            cout<<"정확한 입력입니다"<<endl;
            break;
        }
        else
            cout<<"틀립니다. 다시 입력하세요"<<endl;
    }

    return 0; // main 함수에서 반환 값이 필요합니다
}

//  istream& getline (char* s, streamsize count, char delim);

/*
s: 문자열을 저장할 문자 배열의 포인터입니다.
count: 읽을 최대 문자 수입니다. 읽은 문자 수가 이 값보다 작거나 같을 때까지 문자를 읽습니다.
delim: (선택적) 문자열을 끝낼 구분 문자입니다. 기본값은 \n (개행 문자)입니다.

위 함수는 입력 스트림에서 문자를 읽어서 's'가 가리키는 문자 배열에 저장
개행 문자가 나타나거나 지정된 최대 문자 수에 도달할 때까지 문자를 읽음
그런 다음, 읽은 문자열에 널 종단문자주('\0')를 추가하여 C스타일의 문자열을 만듬

cin.getline() 함수는 보통 키보드 입력에서 사용되며, 사용자가 입력을 완료하고 엔터 키를 누르면 됨
그리고 읽은 문자열에는 마지막 개행 문자 즉 엔터('\n')가 입력되지 않음
*/
