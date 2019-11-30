/*Một người mỗi ngày phải uống đúng một nửa viên thuốc. Anh ta lấy ra từ lọ thuốc một viên ngẫu nhiên sau đó tách ra làm đôi, dùng một nửa rồi lại bỏ một nửa vào lọ. Hôm sau cũng vậy, nếu lấy ra ngẫu nhiên được một nửa viên thì dùng ngay, còn nếu lấy ra một viên còn nguyên thì lại tách làm đôi.

Giả sử mỗi lần lấy ra một viên nguyên thì ghi ra chữ W, nếu lấy ra một nửa viên thì ghi chữ H. Bài toán đặt ra là cho trước một số lượng viên thuốc trong lọ. Hãy xác định xem có bao nhiêu cách uống hết chỗ thuốc đó (tức là có bao nhiêu xâu ký tự khác nhau có thể được tạo ra). 

Input
Gồm không quá 1000 bộ test, mỗi bộ test ghi số nguyên dương là số viên thuốc trong lọ (không quá 30). Dòng cuối cùng ghi số 0. 

Output
ghi trên một dòng số nguyên dương là số cách khác nhau tìm được. 

Example
Input:
6

1

4

2

3

30

0

Output:
132

1

14

2

5

3814986502092304
*/


#include <iostream>

using namespace std;
long long int G[50][50];
long long drink(long long n)
{
    for (int i=0;i<=30;i++)
    {
        for (int j=1;j<=30;j++)
        {
            if (i==0){
                G[i][j]=1;
            }
            else if (j==1&&i!=0)
            {
                G[i][j-1]=0;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            G[i][j]=G[i][j-1]+G[i-1][j+1];
        }

    }
    return G[n][1];
}

int main()
{
    int F[1000];
    long long n,i=0;
    while (n!=0)
    {
        cin>>n;
        F[i]=n;
        i++;
    }
    for (long long j=0;j<i-1;j++)
        if (F[j]==30) cout<<drink(F[j])+1<<endl;
        else cout<<drink(F[j])<<endl;

}
