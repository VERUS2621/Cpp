#include <iostream>
#include <string>

using namespace std;

// 스택 노드 구조체 정의
struct StackNode {
    float data;         // 스택에 저장되는 데이터
    StackNode* next;    // 다음 노드를 가리키는 포인터
    // 생성자: 데이터와 다음 노드를 초기화
    StackNode(float val) {
        data = val;
        next = nullptr;
    }
};

// 스택 클래스 정의
class Stack {
private:
    StackNode* top;     // 스택의 맨 위를 가리키는 포인터

public:
    // 생성자: 스택 초기화
    Stack() {
        top = nullptr;
    }
    // 소멸자: 스택에 있는 모든 노드 제거
    ~Stack() {
        // 스택의 맨 위 노드를 제거하고 반복적으로 실행하여 스택을 비움
        while (top != nullptr) {
            StackNode* temp = top;      // 현재 top을 임시로 저장
            top = top->next;            // top을 다음 노드로 이동
            delete temp;                // 현재 top 제거
        }
    }

    // 스택에 데이터를 추가하는 함수
    void push(float val) {
        // 새로운 노드 생성
        StackNode* newNode = new StackNode(val);
        // 새로운 노드의 다음 노드를 현재 스택의 맨 위로 설정
        newNode->next = top;
        // 새로운 노드를 스택의 맨 위로 이동
        top = newNode;
    }

    // 스택에서 데이터를 제거하고 반환하는 함수
    float pop() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        // 제거할 노드의 데이터
        float val = top->data;
        // 제거할 노드의 포인터
        StackNode* temp = top;
        // 스택의 맨 위를 다음 노드로 이동
        top = top->next;
        // 제거된 노드의 메모리 반환
        delete temp;
        return val;
    }

    // 스택의 맨 위에 있는 데이터를 반환하는 함수
    float peek() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1); // 비정상 종료, 스택이 비어있으므로
        }
        // 스택의 맨 위에 있는 데이터 반환
        return top->data;
    }

    // 스택이 비어 있는지 확인하는 함수
    bool isEmpty() {
        // 스택의 맨 위가 nullptr이면 비어 있음
        return top == nullptr;
    }
};


// 연산자 우선순위를 반환하는 함수
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infixToPostfix(string infix) {
    string postfix;     // 후위 표기식을 저장할 변수
    Stack operators;    // 연산자를 저장하는 스택

    // 중위 표기식을 한 글자씩 순회하면서 후위 표기식으로 변환
    for (int i = 0; i < infix.size(); ++i) {
        char token = infix[i]; // 현재 문자

        if (token == ' ') continue; // 공백은 무시

        // 피연산자인 경우
        if (isdigit(token) || token == '.') {
            postfix += token;
            postfix += ' '; // 피연산자 뒤에 공백 추가
        }
        // 연산자인 경우
        else {
            // 연산자 우선순위가 높거나 같을 때까지 스택에서 pop하여 postfix에 추가
            while (!operators.isEmpty() && precedence(token) <= precedence(operators.peek())) {
                postfix += operators.pop();
                postfix += ' '; // 연산자 뒤에 공백 추가
            }
            operators.push(token); // 현재 연산자를 스택에 push
        }
    }

    // 스택에 남아있는 모든 연산자를 postfix에 추가
    while (!operators.isEmpty()) {
        postfix += operators.pop();
        postfix += ' '; // 연산자 뒤에 공백 추가
    }

    return postfix;
}

// 후위 표기식을 계산하는 함수
float evaluatePostfix(string postfix) {
    Stack operands;     // 피연산자를 저장하는 스택

    size_t i = 0;
    while (i < postfix.size()) {
        if (isdigit(postfix[i])) {
            string numStr = "";
            // 연속된 문자열을 읽어 실수로 변환하여 스택에 push
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                numStr += postfix[i++];
            }
            operands.push(stof(numStr)); // 문자열을 float로 변환하여 스택에 push
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            float operand2 = operands.pop();
            float operand1 = operands.pop();
            float result;
            // 연산자에 따라 연산을 수행하고 결과를 스택에 push
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            operands.push(result); // 연산 결과를 스택에 push
            i++;
        } else {
            i++; // 공백이면 넘어감
        }
    }

    return operands.pop(); // 최종 계산 결과 반환
}

int main() {
    string old;
    cout << "4+3*3/2와 같이 문자열을 입력하세요." << endl;
    getline(cin, old); // 문자열 입력

    string s = "";

    // 문자열에서 숫자와 연산자만 추출하여 새로운 문자열에 저장
    for (int i = 0; i < old.length(); i++){
       // 현재 문자가 공백이 아닌 경우에만 새로운 문자열에 추가
        if (s[i] != ' ') {
            s += old[i];
        }
    }
    string postfix =  infixToPostfix(s); // 중위 표기식을 후위 표기식으로 변환
    float result = evaluatePostfix(postfix); // 후위 표기식을 계산하여 결과 얻기

    // 결과 출력
    cout << "계산 결과: " << result << endl;

    return 0;
}
