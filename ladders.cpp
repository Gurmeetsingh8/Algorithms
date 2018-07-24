#include<bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int ladder(int n)
{
    if(dp[n]>0)
        return dp[n];
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 1;

    dp[n]= ladder(n-1)+ladder(n-2)+ladder(n-3);
    return dp[n];
}
int ladderbottomup(int n)
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}
/// if no. ways are given as k
int ladderrec(int n,int k)
{

     if(n<0) return 0;
    if(n==0) return 1;
     int ans=0;
    for(int i=1;i<=k;i++)
       ans+=ladderrec(n-i,k);
    return ans;
}
int main ()
{
    int n;
    cin>>n;
   // cout<<ladder(n)<<endl;
    cout<<ladderrec(n,2);
    cout<<endl;
   // for(int i=0;i<n;i++)
       /// cout<<dp[i]<<" ";

}
