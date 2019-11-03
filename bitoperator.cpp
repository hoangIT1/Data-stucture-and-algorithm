#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,i,a=0;
    do
    {
        cin>>n;
    }
    while (n>150||n<0);
    vector<char>input1(n);
    vector<char>input2(n);
    vector<char>input3(n);
    for (i=0;i<n;i++)
    {
        cin>>input1.at(i);
        cin>>input2.at(i);
        cin>>input3.at(i);
    }
    for (i=0;i<n;i++)
    {
        if (input1.at(i)=='+'||input2.at(i)=='+'||input3.at(i)=='+')
            a+=1;
        if (input1.at(i)=='-'||input2.at(i)=='-'||input3.at(i)=='-')
            a-=1;
    }
    cout<<a;
}
