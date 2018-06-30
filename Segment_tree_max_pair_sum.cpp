#include<bits/stdc++.h>
using namespace std;
struct node
{
    int maximum;
    int smaximum;
};
void Buildatree(int* arr,node* tree,int treenode,int s,int e)
{
    if(s==e)
    {
        tree[treenode].maximum=arr[s];
        tree[treenode].smaximum=INT_MIN;
        return ;
    }
    int mid=(s+e)/2;
    Buildatree(arr,tree,2*treenode,s,mid);
    Buildatree(arr,tree,2*treenode+1,mid+1,e);
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    tree[treenode].maximum=max(left.maximum,right.maximum);
    tree[treenode].smaximum=min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree=new node[3*n];
    Buildatree(arr,tree,1,0,n-1);
    for(int i=0;i<3*n;i++)
    {
        cout<<tree[i].maximum<<" "<<tree[i].smaximum<<endl;
    }
}

