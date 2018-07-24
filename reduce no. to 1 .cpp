#include <bits/stdc++.h>
#include<queue>
using namespace std;

int mini(int n)
{

    if(n==1)
    return 0;
    int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
    if(n%3==0)
    ans1= 1+mini(n/3);
    if(n%2==0)
    ans2= 1+mini(n/2);
    ans3=1+mini(n-1);
        return min(ans1,min(ans2,ans3));
}
int main()
{
     int n;
    cin>>n;
    int ans=mini(n);
    cout<<ans<<endl;

}
