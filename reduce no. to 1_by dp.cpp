#include <bits/stdc++.h>
#include<queue>
using namespace std;
int dp[10000]={0};
int mini(int n)
{

    if(n==1)
    return 0;
    if(dp[n]>0)
        return dp[n];
    int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
    if(n%3==0)
    ans1= 1+mini(n/3);
    if(n%2==0)
    ans2= 1+mini(n/2);
    ans3=1+mini(n-1);
    dp[n]=min(ans1,min(ans2,ans3));
    return dp[n];
}
int mini_bottom_up_dp(int n)
{
    int dp[10000];
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int curnum=4;curnum<=n;curnum++)
    {
         int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
    if(curnum%3==0)
    ans1= 1+dp[curnum/3];
    if(curnum%2==0)
    ans2= 1+dp[curnum/2];
    ans3=1+dp[curnum-1];
    dp[curnum]=min(ans1,min(ans2,ans3));
    }
    return dp[n];

}
int main()
{
     int n;
    cin>>n;
    int ans=mini_bottom_up_dp(n);
    cout<<ans<<endl;

}
