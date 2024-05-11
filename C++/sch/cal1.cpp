#include <iostream>
#include <string>
using namespace std;

int main() {
    string old;
    cout << "4+3*3/2와 같이 문자열을 입력하세요." << endl;
    getline(cin, old); // 문자열 입력

    string s = "";

    // 문자열 숫자 입력시 공백 있는 경우 새로운 문자열 작성(부가점1)
    for (int i = 0; i < old.length(); i++){
       // 현재 문자가 공백이 아닌 경우에만 새로운 문자열에 추가
        if (s[i] != ' ') {
            s += old[i];
        }
    } 
    
    float sum = 0;
    int startIndex = 0; // 문자열 내에 검색할 시작 인덱스

    // 첫 번째 숫자를 미리 계산
    int fIndex = s.find_first_of("+-*/", startIndex);
    if (fIndex == -1) {
        cout << "잘못된 입력입니다." << endl;
        return 0;
    }
    sum = stof(s.substr(startIndex, fIndex - startIndex)); // 첫 번째 숫자 저장
    
    startIndex = fIndex + 1; // 다음 숫자의 시작 위치로 이동

    while (true) {
        // 현재 시작 인덱스부터 다음 연산자 위치 탐색
        fIndex = s.find_first_of("+-*/", startIndex);
        
        if (fIndex == -1) {
            string part = s.substr(startIndex); // 시작부터 끝까지
            if (part != "") { // 빈 문자열이 아니면 숫자이므로 연산
                switch (s[startIndex - 1]) { // 이전 연산자에 따라 연산 수행
                    case '+':
                        sum += stof(part);
                        break;
                    case '-':
                        sum -= stof(part);
                        break;
                    case '*':
                        sum *= stof(part);
                        break;
                    case '/':
                        // 0으로 나누는 경우 처리
                        if (stof(part) != 0) {
                            sum /= stof(part);
                        } else {
                            cout << "0으로 나눌 수 없습니다." << endl;
                            return 0;
                        }
                        break;
                }
            }
            break; // 루프 종료
        }
        
        string part = s.substr(startIndex, fIndex - startIndex); // 숫자 추출
        if (part != "") { // 빈 문자열이 아니면 숫자이므로 연산
            switch (s[startIndex - 1]) { // 이전 연산자에 따라 연산 수행
                case '+':
                    sum += stof(part);
                    break;
                case '-':
                    sum -= stof(part);
                    break;
                case '*':
                    sum *= stof(part);
                    break;
                case '/':
                    // 0으로 나누는 경우 처리
                    if (stof(part) != 0) {
                        sum /= stof(part);
                    } else {
                        cout << "0으로 나눌 수 없습니다." << endl;
                        return 0;
                    }
                    break;
            }
        }

        startIndex = fIndex + 1; // 다음 연산자의 위치로 이동
    }

    cout << "숫자들의 계산 결과는 " << sum << endl;

    return 0;
}
