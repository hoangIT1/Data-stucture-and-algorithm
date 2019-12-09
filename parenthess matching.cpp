/*Cho các đoạn văn chứa các dấu ngoặc, có thể là ngoặc đơn đơn ( “()” ) hoặc ngoặc vuông ( “[]” ). Một đoạn văn đúng là đoạn mà với mỗi dấu mở ngoặc thì sẽ có dấu đóng ngoặc tương ứng và đúng thứ tự. Nhiệm vụ của bạn kiểm tra xem đoạn văn có đúng hay không.

Input
Gồm nhiều bộ test, mỗi bộ test trên một dòng chứa đoạn văn cần kiểm tra có thể bao gồm: các kí tự trong bảng chữ cái tiếng Anh, dấu cách, và dấu ngoặc (ngoặc đơn hoặc ngoặc vuông). Kết thúc mỗi bộ test là một dấu chấm. Mỗi dòng có không quá 100 kí tự.

Dữ liệu kết thúc bởi dòng chứa duy nhất một dấu chấm.

Output
Với mỗi bộ test, xuất ra trên một dòng “yes” nếu đoạn văn đúng, ngược lại in ra “no”.

Example
Input:
So when I die (the [first] I will see in (heaven) is a score list).

[ first in ] ( first out ).

Half Moon tonight (At least it is better than no Moon at all].

A rope may form )( a trail in a maze.

Help( I[m being held prisoner in a fortune cookie factory)].

([ (([( [ ] ) ( ) (( ))] )) ]).

 .

.

Output:
yes
yes
no
no
no
yes
yes
*/
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

bool parenthessmatching(string s)
{
    stack <char> a;
    char x;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!='('&&s[i]!='['&&s[i]!=')'&&s[i]!=']')
        {
            continue;
        }
        if (s[i]=='('||s[i]=='[')
        {
            a.push(s[i]);
            continue;
        }
        if (a.empty()) return false;
        switch (s[i])
        {
        case ')':
            {
                x=a.top();
                a.pop();
                if (x=='[') return false;
                break;
            }
        case ']':
            {
                x=a.top();
                a.pop();
                if (x=='(') return false;
                break;
            }
        }
    }
    return (a.empty());
}
void printresult(string s)
{
    if (parenthessmatching(s)==true) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int main()
{
    string dau;
    do{
    	getline(cin, dau);
    	if (dau==".") break;
        else 
        {
        	printresult(dau);
        }
    }
    while (1);
    return 0;
}
