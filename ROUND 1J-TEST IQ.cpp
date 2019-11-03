#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i,t=0;
    vector<char>input1(4);
    vector<char>input2(4);
    vector<char>input3(4);
    vector<char>input4(4);
    for (i=0;i<4;i++)
    {
        cin>>input1.at(i);
        cin>>input2.at(i);
        cin>>input3.at(i);
        cin>>input4.at(i);
    }
    for (i=0;i<3;i++)
    {
        if (input1.at(i)==input2.at(i)&&input1.at(i)==input1.at(i+1))
            t++;
        else if (input2.at(i)==input3.at(i)&&input2.at(i)==input2.at(i+1))
            t++;
        else if (input3.at(i)==input4.at(i)&&input3.at(i)==input3.at(i+1))
            t++;
    }
    if (t>=1) cout<<"YES";
    else cout<<"NO";
}
