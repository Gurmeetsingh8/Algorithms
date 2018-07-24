#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000],b[1000],m,n;
ll dp[1000][1000][8];
int kordered_lcs(ll i,ll j,ll k)
{
    if(i==m||j==n)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int res=0;
    if(a[i]==b[k])
    {
        res=1+kordered_lcs(i+1,j+1,k);

    }
    else
    {
        if(k>0)
            res=1+kordered_lcs(i+1,j+1,k-1);
        res=max(res,kordered_lcs(i+1,j,k));
        res=max(res,kordered_lcs(i,j+1,k));
    }
    return res;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll k;
    cin>>m>>n>>k;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    cout<<kordered_lcs(0,0,k);
}
