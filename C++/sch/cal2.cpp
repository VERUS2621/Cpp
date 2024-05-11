#include <iostream>
#include <string>

using namespace std;

// 스택 노드 구조체 정의
struct StackNode {
    float data;
    StackNode* next;
    StackNode(float val) : data(val), next(nullptr) {}
};

// 스택 클래스 정의
class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(float val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
    }

    float pop() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        float val = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    float peek() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        return top->data;
    }

    bool isEmpty() {
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
    string postfix;
    Stack operators;

    for (char token : infix) {
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
    Stack operands;

    size_t i = 0;
    while (i < postfix.size()) {
        if (isdigit(postfix[i])) {
            string numStr = "";
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                numStr += postfix[i++];
            }
            operands.push(stof(numStr)); // 문자열을 float로 변환하여 스택에 push
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            float operand2 = operands.pop();
            float operand1 = operands.pop();
            float result;
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

    // 문자열 숫자 입력시 공백 있는 경우 새로운 문자열 작성(부가점1)
    for (int i = 0; i < old.length(); i++){
       // 현재 문자가 공백이 아닌 경우에만 새로운 문자열에 추가
        if (s[i] != ' ') {
            s += old[i];
        }
    }
    string postfix =  infixToPostfix(s);
    float result = evaluatePostfix(postfix);

  cout << "계산 결과: " << result << endl;
}