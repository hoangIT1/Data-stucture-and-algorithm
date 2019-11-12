/*Xét bàn cờ tổng quát kích thước n × n, người ta muốn đặt k quân tượng vào k ô hoàn toàn phân biệt sao cho chúng đôi một không ăn nhau. 
(Quân tượng có thể ăn quân khác nằm ở những ô cùng đường chéo với ô nó đang đứng).
Nhiệm vụ của các bạn là hãy tính xem có bao nhiêu cách đặt k quân tượng này?
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int N,k;
int f(int m,int k)
{
    if (k==0&&m>=0) return 1;
    if (m==N-1)
    {
        if(k==1) return 2;
        if (k>1) return 0;
    }
    if (m==N-2)
    {
        if (k==1) return 4;
        if (k==2) return 2;
        if (k>2) return 0;
    }
    if (m==0)
    {
        return f(m+2,k)+(N-m-k+1)*f(m+2,k-1);
    }
    if (k==1)
    {
        return f(m+2,k)+(N-m-k+1)*2*f(m+2,k-1);
    }
    else return f(m+2,k)+(N-m-k+1)*(2*f(m+2,k-1) + (N-m-k+2)*f(m+2,k-2));
}
int main()
{
    int s=0,i,j;
    scanf("%d",&N);
    scanf("%d",&k);
    for (i=0;i<=k;i++)
    {
        s+=f(0,i)*f(1,k-i);
    }
    printf("%d",s);
}
