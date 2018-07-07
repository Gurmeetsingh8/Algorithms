#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int t;
    cout<<"&";
    cin>>t;
    while(t--)
    {

        ll n;
        cin>>n;
        ll a[100000];
        ll prefix[100000]{0};
        for(int i=0;i<n;i++)
        {
             cin>>a[i];
             prefix[1+i]+=a[i];
        }

        ll freq[100000]{0};
        for(int i=0;i<n;i++)
        {
           int ans=prefix[i]%n;
           freq[ans]++;
        }
        ll answer=0;
        for(int i=0;i<n;i++)
        {
            ll no=freq[i];
            answer+=(no*(no-1))/2;
        }
        cout<<answer;
    }
}
