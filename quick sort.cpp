#include<bits/stdc++.h>
using namespace std;
int partion(int *a,int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot=a[e];
    for(;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;

}
void quicksort(int *a,int s,int e)
{
    if(s>=e) return ;
    int pivot=partion(a,s,e);
    quicksort(a,0,pivot-1);
    quicksort(a,pivot+1,e);
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;

}
