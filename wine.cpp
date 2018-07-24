#include<bits/stdc++.h>
using namespace std;
int cost(int *a,int n,int yr)
{
    if(n==1)
        return yr*a[n-1];


         int ans1=INT_MIN,ans2=INT_MIN;
         ans1=yr*a[0]+cost(a+1,n-1,yr+1);
         ans2=yr*a[n-1]+cost(a,n-1,yr+1);
         return max(ans1,ans2);



}
int main()
{
    int n;
    cin>>n;

    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=cost(a,n,1);
    cout<<ans;
}
