#include<bits/stdc++.h>
using namespace std;
int maxprofit(int *price,int totallen)
{
    if(totallen==0)
        return 0;
    int best=0;
    for(int len=1;len<=totallen;len++)
    {
       int curans=price[len]+maxprofit(price,totallen-len);
       best=max(best,curans);
    }
    return best;


}
int maxprofit_bottom_up(int* price,int totallen)
{
    int dp[100]={0};
    for(int len=1;len<=totallen;len++)
    {
        int best=0;
        for(int cut=1;cut<=len;cut++)
        {
            best=max(best,price[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[totallen];
}
int main()
{
    int totallen;
    cin>>totallen;
    int price[100];
    for(int eachpiece=1;eachpiece<=totallen;eachpiece++)
        cin>>price[eachpiece];
    cout<<maxprofit_bottom_up(price,totallen);
}
