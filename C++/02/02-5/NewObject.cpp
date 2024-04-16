#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
    public:
        Simple()
        {
            cout <<"I'm simple constructor!"<<endl;
        }
};

int main(void)
{
    cout<< "case 1: ";
    Simple * sp1=new Simple; // 생성자 호출 함

    cout<< "case 2: ";
    Simple * sp2=(Simple*)malloc(sizeof(Simple)*1); // 생성자 호출 안함

    cout<<endl<<"end of main"<<endl;
    delete sp1;
    free(sp2);
    return 0;
}