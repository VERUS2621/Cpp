#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrADr(int len)
{
    // char * str=(char *)malloc(sizeof(char)*len);
    char * str=new char[len];
    return str;
}

int main(void)
{
    char * str=MakeStrADr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    // free(str);
    delete []str;
    return 0;
}