#include<bits/stdc++.h>
using namespace std;
bool caniput(int soduku[][9],int n,int i,int j,int number)
{
    for(int x=0;x<n;x++)
    {
        if(soduku[x][j]==number||soduku[i][x]==number)
            return false;
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
           if(soduku[x][y]==number)
           return false;
    }
    return true;
}
bool solvesoduku(int soduku[][9],int n,int i,int j)
{
    if(i==n)
    {
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<soduku[i][j]<<" ";
             cout<<endl;
        }

        return true;
        }
    if(j==n)
    {
         return solvesoduku(soduku,n,i+1,0);
    }
    if(soduku[i][j]!=0)
        return solvesoduku(soduku,n,i,j+1);
    for(int number=1;number<=n;number++)
    {
        if(caniput(soduku,n,i,j,number))
        {
            soduku[i][j]=number;
           bool aagesolve=solvesoduku(soduku,n,i,j+1);
           if(aagesolve)
            return true;
        }
    }
    soduku[i][j]=0;
    return false;

}
int main()
{
    int n;
    cin>>n;
    int soduku[9][9];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>soduku[i][j];

    solvesoduku(soduku,9,0,0);


    return 0;
}
