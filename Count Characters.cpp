//input is a string S with length not pass 10^6 include characters from a to z.
//The requirement for you is count which letter appears the most in the string!!!
//This code was authorized by Duong Minh Hoang
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int count[26];
int main()
{
    char c;
    int max=0,index,a;
    do
    {
        c=getwchar();
        a=(int) c;
        if (a<97)
            break;
        count[a-97]++;
    }
    while (1);
    for (a=97;a<123;a++)
    {
        if (count[a-97]>max)
        {
            max=count[a-97];
            index=a-97;
        }
    }
    cout<<char(index+97);
}
