#include <iostream>
using namespace std;

class Person {
    string name;
public:
    Person(){ }
    Person(string name) { this->name = name; }
    string getName() {return name;}
    void setName(string name); // 완성해야함
};

class Family {
    Person* p; // Person배열 포인터
    string familyName;
    int size; // Person 배열 큭, 가족 구성원 수
public:
    Family(string name, int size); // size 갯수만큼 Person 배열 동적 생성
    void show();
    void setName(int index, string name); // 완성해야함
    ~Family();
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