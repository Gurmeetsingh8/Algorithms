#include<bits/stdc++.h>
using namespace std;

int longest_subarray(int *a,int n,int b)
{
    if(n==0) return 0;
    if(n==1&&a[n-1]<=b)
    {
       return 1;
    }
    if(n>1&&(a[n-1]-a[0])<=b)
        return n;
    int best=0;
    for(int i=1;i<n;i++)
    {
        int curans=longest_subarray(a,i,b);
        //cout<<curans;
        best=max(best,curans);
    }
    return best;

}
int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int b;
    cin>>b;
    cout<<longest_subarray(a,n,b);



}
