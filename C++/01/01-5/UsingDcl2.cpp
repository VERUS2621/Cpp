#include <iostream>

using std::cin;
using std::cout;
using std::endl; // 이렇게 적는 것이 좋은 습관이다.

// 위 3개를 일일이 선언하는 것이 귀찮다면
// using namespace std; 를 통해 명령할 수 있다.
// "이름공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략"

int main(void){
    int num = 20;
    cout << "Hello World!" << endl;
    cout << "Hello " << "World!" << endl;
    cout << num << ' ' << 'A';
    cout << ' ' << 3.14 << endl;
    return 0;
}

// 편하기는 하지만 이렇게 선언을 해버리면, 그만큼 이름충돌이 발생할 확률은 상대적을 높아진다.
// 따라서, 무조건 편한 것만을 선호하기 보다는 상활을 판단해서 적절히 혼용하는 지혜가 필요하다.