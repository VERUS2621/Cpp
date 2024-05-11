// 연산순서가 지켜지지 않을 때 앞 부분부터 순서대로 계산하는 경우 + 띄어쓰기
// 4 + 3 * 3 / 2 이렇게 입력받는 경우에도 처리할 수 있을 것.
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "4+3*3/2와 같이 문자열을 입력하세요." << endl;
	getline(cin, s, '\n'); // 문자열 입력
	int sum = 0;
	int startIndex = 0; // 문자열 내에 검색할 시작 인덱스
    int 
	while(true) {
        sum += s[0];
        s = s.substr(1)
		int fIndex = s.find('+-*/', startIndex); // s.find(찾을 대상, 검색 시작위치)
		if(fIndex == -1) { // 연산자를 발견하지 못했을 때
			string part = s.substr(startIndex); // 부분 나누기 strat인덱스 시작부터 끝까지.
			if(part == "") break; // "2+3+", 즉 +로 끝나는 경우
			cout << part << endl;
			sum += stoi(part); // 문자열을 수로 변환하여 더하기
			break;
		}
        else {
		char op = s[fIndex]
        int nextfIndex = s.find('+-*/', fIndex); // s.find(찾을 대상, 검색 시작위치)


        int count = nextfIndex - fIndex; // 서브스트링으로 자를 문자 개수
		string part = s.substr(startIndex, count); // startIndex부터 count 개의 문자로 서브스트링 만들기
		cout << part << endl;

        if (op == '+') {
                sum += stoi(part)
                startIndex = fIndex + 1;
            } else if (op == '-') {
                startIndex = fIndex + 1;
            } else if (op == '*') {
                int nextIndex = s.find("0123456789", fIndex + 1);
                int num = stoi(s.substr(fIndex + 1, nextIndex - fIndex - 1));
                sum *= num;
                startIndex = fIndex + 1;
            } else if (op == '/') {
                int nextIndex = s.find_first_of("0123456789", fIndex + 1);
                int num = stoi(s.substr(fIndex + 1, nextIndex - fIndex - 1));
                if (num != 0) {
                    sum /= num;
                } else {
                    cout << "0으로 나눌 수 없습니다." << endl;
                    return 1; // 오류 코드 반환
                }
        }
        
        
	}
	cout << "숫자들의 계산 결과는  " << sum;
};
