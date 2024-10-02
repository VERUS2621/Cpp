#include <iostream>
using namespace std;

class FruitSeller
{
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE=price;
        numOfApples=num;
        myMoney=money;
    }
    int SaleApples(int money)
    {
        int num=money/APPLE_PRICE;
        numOfApples-=num;
        myMoney+=money;
        return num; // 구매하는 사과의 개수를 반환
    }
    void ShowSaleResult()
    {
        cout << "남은 사과 : "<<numOfApples<<endl;
        cout<< "판매 수익 : " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money)
    {
        myMoney=money;
        numOfApples=0;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples+=seller.SaleApples(money); 
        
        // 이처럼 하나의 객체가 다른 하나의 객체에게 메시지를 전달하는 방법은
        // (어떠한 행위의 요구를 위한 메시지 전달) 함수 호출을 기반으로 한다.
        // 그래서 객체지향에서는 이러한 형태의 함수호출을 가리켜 메시지전달(Message Passing)이라 한다.
        myMoney-=money;
    }
    void ShowBuyResult()
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000); // 과일의 구매!

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSaleResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}