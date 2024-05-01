#include <iostream>
using namespace std;

class Person {
    string name;
public:
    Person(){ }
    Person(string name) { this->name = name; }
    string getName() {return name;}
    void setName(string name) { this->name = name; }
};

class Family {
    Person* p; // Person배열 포인터
    string familyName;
    int size; // Person 배열 크기, 가족 구성원 수
public:
    Family(string name, int size) {
        this->familyName=name;
        this->size = size;
        p = new Person[size];
    } // size 갯수만큼 Person 배열 동적 생성
    void show() // 가족의 이름 출력
    {
        cout << familyName << "가족은 다음과 같이 " << size << "명 입니다." << endl;
        for ( int i = 0; i < size; i++) {
            cout << p[i].getName() << "\t";
        }
    } 
    void setName(int index, string name)
    {
        if (index >= 0 or index < size) {
            p[index].setName(name);
    }
    }
    ~Family()
    { delete []p; }
};

int main() {
    Family* simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr.Simpson");
    simpson->setName(1, "Mrs.Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson -> show();
    delete simpson;
    return 0;
}