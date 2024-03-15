/* 다음과 같이 "yes"가 입력될 떄까지 종료하지 않는 프로그램을 작성하라.
 사용자로부터의 입력은 cin.getline 함수를 사용하라 */

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char abc[10];

    while(true){
        cin.getline(abc, 10);
        if(strcmp(abc, "yes")==0){
            cout<<"정확한 입력입니다"<<endl;
            break;
        }
        else
            cout<<"틀립니다. 다시 입력하세요"<<endl;
    }


}
