#include <iostream>
using namespace std;

class Person
{
    int id;
    double weight;
    string name;

public:
    Person(int id=1, string name = "Grace", double weight = 20.5)
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }

    Person(int id, string name, double weight = 20.5)
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }

    Person(int id, string name, double weight)
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    /*Person(int a=1, string c = "grace", double b = 20.5)
    {
        this->id = id;
        this->name = name;
        this->weight = weight;
    }
    */
    void show() { cout << id << ' ' << weight << ' ' << name << endl;}
};

int main()
{
    Person grace, ashley(2, "Ashley"), helen(3, "Hellen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}
