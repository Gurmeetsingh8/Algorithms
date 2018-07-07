#include<bits/stdc++.h>
using namespace std;
bitset<30> col,d1,d2;///30 bits size and here bitset is class(d1 left diagonal,d2 right  diagonals and 1 for column check
   /* b[2]=1;
    b[4]=1;
    cout<<b<<" ";*/
void solvenqueen_bitset(int n,int &ans,int i)
{
    if(i==n)
    {
        ans++;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(!col[j]&&!d1[i-j+n-1]&&!d2[i+j])
        {
        col[j]=d1[i-j+n-1]=d2[i+j]=1;
        solvenqueen_bitset(n,ans,i+1);
        col[j]=d1[i-j+n-1]=d2[i+j]=0;
        }

    }
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    solvenqueen_bitset(n,ans,0);
    cout<<ans<<endl;

    return 0;

}
