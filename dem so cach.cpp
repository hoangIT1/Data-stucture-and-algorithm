/*Cho 1 dãy số gồm n số nguyên a[1], a[2], ..., a[n].
Input
Dòng đầu tiên chứa số n (1 ≤ n ≤ 5*10^5).

Dòng thứ 2 gồm n số nguyên a[1], a[2], ..., a[n] (0 <= |a[i]| <= 10^9) là các phần tử của dãy.

Output
In ra kết quả của bài toán.

Example
Test 1:

Input:

5

1 2 3 0 3

Output:

2

 

Test 2:

Input:

2

4 1

Output:

0
*/


#include <iostream>

using namespace std;
long long int a[500010]={};
int main()
{
    long long int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int n1;
        cin>>n1;
        a[i]=a[i-1]+n1;
    }
    long long int tong=0;
    long long int dem=0;
    for (int i=n-1;i>0;i--)
    {
        if (a[i]==a[n]/3)
        {
            tong+=dem;
        }
        if (a[i]==2*a[n]/3)
        {
            dem+=1;
        }
    }
    cout<<tong<<endl;
}
