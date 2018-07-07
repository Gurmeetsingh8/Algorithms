#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n;
    cin>>n;
    unsigned long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int v=k+1;v<n;v++)
                {
                    if((a[i]^a[j]^a[k]^a[v])==0)
                       {
                           cout<<"YES"<<endl;
                           return 0;
                       }
                }
            }
        }
    }

       cout<<"NO"<<endl;

    return 0;

}
