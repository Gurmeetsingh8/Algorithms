#include<bits/stdc++.h>
using namespace std;
int lis(int*a,int n)
{
    int dp[100];
    for(int i=0;i<n;i++)
        dp[i]=1;
        int best=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[i])
        {
            int curans=1+dp[j];
             dp[i]=max(dp[i],curans);

        }

        }
        best=max(best,dp[i]);

    }
    return best;
}
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<lis(a,n);
}
