//  에스프레소 커피 1 물 1
// 아메리카노 커피1 물2
//설탕 커피 커피 1 물2 설탕 1

#include <iostream>
using namespace std;

class CoffeeMachine
{
public:
    int coffee;
    int water;
    int sugar;

    
    CoffeeMachine(int a, int b, int c){ coffee = a; water = b; sugar = c; }
    void drinksugarCoffee()
    {   coffee -= 1;
        water -= 2;
        sugar -= 1;
    }
    void drinkAmericano()
    {
        coffee -= 1;
        water -= 1;
    }
    void drinkEspresso()
    {
        coffee -= 1;
        water -= 2;
    }
    void show()
    {
        cout << "커피 : " << coffee << " 물 : " << water << " 설탕 : " << sugar << endl; 
    }
    void fill()
    {
        coffee = 10;
        water = 10; 
        sugar = 10;
    }
};

int main()
{
    CoffeeMachine java(5, 10, 3);
    java.drinkEspresso();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinksugarCoffee();
    java.show();
    java.fill(); // 모두 10으로 채움
    java.show();
    return 0;

}