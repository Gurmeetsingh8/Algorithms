#include<bits/stdc++.h>
using namespace std;
int memo[100][100]={0};
int knapsack(int *wts,int *price,int n,int maxwt)
{
    if(n==0||maxwt==0)
        return 0;
        int opt1=0;
        int opt2=0;
    if(memo[n][maxwt]>0)
        return memo[n][maxwt];
    if(wts[n-1]<=maxwt)
    opt1=price[n-1]+knapsack(wts,price,n-1,maxwt-wts[n-1]);
    opt2=knapsack(wts,price,n-1,maxwt);
    memo[n][maxwt]=max(opt1,opt2);
    return memo[n][maxwt];
}
int knapsack_bottom_up(int *wts,int *price,int n,int maxwt)
{
     int dp[100][100];
     if(n==0||maxwt==0)
        return 0;
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=maxwt;j++)
         {
             if(i==0||j==0)
                dp[i][j]=0;
             else
             {
                 int opt1=0,opt2=0;
                 if(wts[i-1]<=j)
                    opt1=price[i-1]+dp[i-1][j-wts[i-1]];
                 opt2=dp[i-1][j];
                 dp[i][j]=max(opt1,opt2);
             }
         }
     }
     return dp[n][maxwt];
}
int main()
{
    int wts[]={2,7,3,4};
    int price[]={5,20,20,10};
    int maxwt;
    cin>>maxwt;
    int n=4;
    cout<<knapsack_bottom_up(wts,price,n,maxwt);
    /*for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=maxwt;j++)
        cout<<memo[i][j]<<" ";
        cout<<endl;

    }*/

}
