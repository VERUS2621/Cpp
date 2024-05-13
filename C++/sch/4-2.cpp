#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
using namespace std;

class Book {
   char *title;
   int price;
public:
   Book(const char *title, int price)
   {
    this->price = price;
    int len = strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title);
   };

   // 복사 생성자
   Book(const Book& b)
   {
    this->price = price;
    int len = strlen(b.title);
    this->title = new char[len + 1];
    strcpy(this->title, b.title);
   }

   ~Book()
   {
      delete[] title;
   };

   void set(const char *title, int price)
   {
      // 기존의 동적 할당 메모리 해제
      delete[] this->title;
      
      // 새로운 문자열 할당
      int len = strlen(title);
      this->title = new char[len + 1];
      strcpy(this->title, title);

      this->price = price;
   };
   
   void show()
   {
      cout << title << ' ' << price << "원" << endl;
   }
};

int main() {
   Book cpp("명품C++", 10000);
   Book java = cpp; // 복사 생성자 호출
   java.set("명품자바", 12000);
   cpp.show();
   java.show();
   return 0;
}
