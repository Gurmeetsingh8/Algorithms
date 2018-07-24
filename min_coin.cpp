#include<bits/stdc++.h>
using namespace std;
int deno[]={1,2,5,10};
int memo[1000]{0};
int mincoin(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(memo[n]>0)
        return memo[n];
    int ans=INT_MAX;
    for(int i=0;i<4;i++)
    {
        if(n-deno[i]>=0){
        int ans1=1+mincoin(n-deno[i]);
        if(ans1!=INT_MAX)
            ans=min(ans,ans1);
        }
    }
    memo[n]=ans;
    return ans;
}
int mincoin_bottom_up(int n)
{
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int rupee=1;rupee<=n;rupee++)
    {
        for(int i=0;i<4;i++)
        {
            if(deno[i]<=rupee)
            {
                int smallans=dp[rupee-deno[i]];
                if(smallans!=INT_MAX)
                {
                    dp[rupee]=min(dp[rupee],1+smallans);
                }
            }
        }
    }
    return dp[n];


}
int main()
{
    int n;
    cin>>n;
    cout<<mincoin_bottom_up(n)<<endl;
    cout<<mincoin(n);
}
