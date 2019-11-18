/*một dãy A = (a1, a2, .., an) được gọi là xâu nhị phân  độ dài n nếu với mọi a[i] là kí tự  0 hoặc 1. Ví dụ xâu A = “01010101” là dãy nhị phân  độ dài 8. Cho số tự nhiên N và số tự nhiên K (1<= K<= N<= 15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu nhị phân  có độ dài N chứa duy nhất một dãy K kí tự 0 liên tiếp.  

Đầu vào
Dữ liệu vào chỉ có một dòng ghi hai số N và K.

Đầu ra
- Dòng đầu tiên ghi lại số các xâu nhị phân thỏa mãn yêu cầu bài toán;

- Những dòng kế tiếp, mỗi dòng ghi lại một xâu nhị phân thỏa mãn.

Lưu ý Các xâu được ghi ra theo thứ tự từ điển.
*/



#include<iostream>
#include<math.h>
using namespace std;
int n,k,X[20],t=0;
void print()
{
    int s=0, dem0=0,t=0;
    for(int i=1;i<=n;i++)
        {
            if(X[i]==0)
            {
                dem0++;
                if(dem0>=k) s++;
            }
            else dem0=0;
        }
    if(s==1)
    {
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<X[i];
        }
    }
}
void check()
{
    int s=0, dem0=0;
    for(int i=1;i<=n;i++)
        {
            if(X[i]==0)
            {
                dem0++;
                if(dem0>=k) s++;
            }
            else dem0=0;
        }
    if(s==1)
    {
        t++;
    }
}
void dem(int a)
{
    int y;
    for(y=0;y<=1;y++)
        {
            X[a]=y;
            if(a==n) check();
            else dem(a+1);
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
    cin>>n>>k;
    dem(1);
    cout<<t;
    create(1);
    return 0;
}
