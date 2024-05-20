#include<iostream>
using namespace std;

class Person
{
    int id;
    double weight;
    string name;

public:    
    Person(int id, string name) // 입력 매개변수 2개
    {
        this->id = id;
        this->name = name;
        this->weight = weight = 20.5;
    }
 
    Person(int id, string name, double weight) // 입력 매개변수 3개
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    
    Person() // 생성자
    {
        id = 1;
        name = "Grace";
        weight = 20.5;
    }

    /*
    Person(int id=1, string name="Grace", double weight=20.5)
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    */

    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
}; 

int main() 
{
    Person grace, ashley(2, "Ashley"), helen(3, "Hellen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
    return 0;
} 
