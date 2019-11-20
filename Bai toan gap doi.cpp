/*Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:  Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A. Ví dụ với 2 bước biến đổi.

ta có [1] ->  [1 2 1] -> [1 2 1 3 1 2 1]. Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input
Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2^N - 1).

Output
Với mỗi test, in ra đáp án trên một dòng.
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long n,j,i=0;
int finded(long long m, long long k)
{
    if (k<(m-1)/2)
    {
        i++;
        return finded((m-1)/2,k);
    }
    if (k==(m-1)/2)
    {
        return n-i;
        i=0;
    }
    if (k>(m-1)/2)
    {
        i++;
        return finded((m-1)/2,k-(m+1)/2);
    }
}
void print(long long n,long long j)
{
    long long s=1;
    for (int i=1;i<n;i++)
        s=2*s+1;
    cout<<finded(s,j-1)<<endl;
    i=0;
}
int main()
{
    long long T,s=1;
    cin>>T;
    vector <long long> input1(T);
    vector <long long> input2(T);
    for (int i=0;i<T;i++)
    {
        cin>>input1.at(i)>>input2.at(i);
    }
    for (int i=0;i<T;i++)
    {
        n=input1.at(i);
        j=input2.at(i);
        print(n,j);
    }
}
