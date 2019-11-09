#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int count1=0;
int R,C;
vector<vector <char> > matrix;
int movex[]={1,1,1,-1,0,0,-1,-1};
int movey[]={1,-1,0,0,1,-1,-1,1};
int count2(int x,int y)
{
    int c=0,i;
    for (i=0;i<8;i++)
    {
        if (x+movex[i]>=0&&x+movex[i]<R&&y+movey[i]>=0&&y+movey[i]<C)
        {
            if (matrix.at(x+movex[i]).at(y+movey[i])=='o')
                c++;
        }
    }
    return c;
}
int main()
{
    int i,j,max=0;
    cin>>R>>C;
    matrix.resize(R);
    for (i=0;i<R;i++)
    {
        matrix.at(i).resize(C);
        for (j=0;j<C;j++)
        {
            cin>>matrix.at(i).at(j);
        }
    }
    for (i=0;i<R;i++)
    {
        for (j=0;j<C;j++)
        {
            int tmp=count2(i,j);
            if (matrix.at(i).at(j)=='o')
                count1+=tmp;
            else
            {
                if (tmp>max)
                    max=tmp;
            }
        }
    }
    cout<<count1/2+max;
}
