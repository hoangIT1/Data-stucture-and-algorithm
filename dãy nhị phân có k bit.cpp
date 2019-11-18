/*Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần

Input
Dòng đầu tiên là số lượng bộ test T (T <= 20).

Mỗi test gồm 2 số nguyên N, K (1 <= K <= N <= 16).

Output
Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
*/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int n,k,A[20],B[20],X[20],T;
void print()
{
    int b=0;
    for(int i=1;i<=n;i++)
    {
        if(X[i]==1) b++;
    }
    if(b==k)
    {   
    	printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d",X[i]);
        }
    }
}
void create(int a)
{
    int y;
    for(y=0;y<=1;y++)
        {
            X[a]=y;
            if(a==n) print();
            else create(a+1);
        }
}
int main()
{
    int T;
    cin>>T;
    vector<int>input1(T);
    vector<int>input2(T);
    for (int i=0;i<T;i++)
    {
        cin>>input1.at(i)>>input2.at(i);
    }
    for (int i=0;i<T;i++)
    {
    	n=input1.at(i);
        k=input2.at(i);
        create(1);
    }
    return 0;
}
