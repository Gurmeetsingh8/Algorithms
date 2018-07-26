#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int>&q)
{
     if(q.empty()) return;
     int val=q.front();
     q.pop();
     reverse(q);
     q.push(val);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    q.push(1);
    q.push(2);
    q.push(3);
    reverse(q);
    cout<<endl;
        while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
