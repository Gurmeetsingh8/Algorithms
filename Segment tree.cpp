#include<bits/stdc++.h>
using namespace std;
void Buildatree(int *arr,int *tree,int s,int e,int treenode)
{
    if(s==e)
       {
        tree[treenode]=arr[s];
        return;
       }
     int mid=(s+e)/2;
     Buildatree(arr,tree,s,mid,2*treenode);
     Buildatree(arr,tree,mid+1,e,2*treenode+1);
     tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
void updateTree(int*arr,int * tree,int s,int e,int treenode,int indx,int value)
{
    if(s==e)
    {
        arr[indx]=value;
        tree[treenode]=value;
        return ;
    }
    int mid=(s+e)/2;
    if(mid<indx)
    {
        updateTree(arr,tree,mid+1,e,2*treenode+1,indx,value);
    }
    else
    {
       updateTree(arr,tree,s,mid,2*treenode,indx,value);
    }
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
int query(int*tree,int s,int e,int treenode,int left,int right)
{
    ///completely outside the given range
    if(s>right||e<left)
        return 0;

    ///completely inside the given range
    if(s>=left&&e<=right)
    return tree[treenode];

    ///partial inside the given range
    int mid=(s+e)/2;
    int ans1=query(tree,s,mid,2*treenode,left,right);
        int ans2=query(tree,mid+1,e,2*treenode+1,left,right);
        return ans1+ans2;

}
int main()
{
    int arr[]={1,2,3,4,5};
    int *tree=new int[10];
    Buildatree(arr,tree,0,4,1);

    updateTree(arr,tree,0,4,1,2,10);
      for(int i=1;i<10;i++)
        cout<<tree[i]<<endl;
    int ans=query(tree,0,4,1,2,4);
    cout<<ans<<endl;

    return 0;
}
