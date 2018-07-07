#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<T,list<T>> adjlist;
public:
    void addedge(int u,int v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);
    }
    void print()
    {
        for(auto it:adjlist)
        {
            cout<<it.first<<"<-";
            for(auto i:it.second)
                cout<<i<<" ";
            cout<<endl;
        }

    }
    void bfs(T s)
    {
        queue<T> q;
        map<T,bool> visited;
        q.push(s);
        visited[s]=true;
        while(!q.empty())
        {
            T f=q.front();
            cout<<f<<" ";
            q.pop();
            for(auto x:adjlist[f])
            {
                if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
    }
    void dfs(int s,map<T,bool>&visited)
    {
        cout<<s<<" ";
        visited[s]=true;
        for(auto i: adjlist[s])
        {
            if(!visited[i])
                dfs(i,visited);
        }
    }
    void dfs(int s)
    {

        map<T,bool> visited;
        int connected=1;
        dfs(s,visited);
        for(auto x:adjlist)
        {
            int i=x.first;
            if(!visited[i])
            {
                connected++;
                dfs(i,visited);
            }
        }
        cout<<"connected"<<connected;
    }
    void dfshelper(T node,map<T,bool>&visited,list<T>& ordering)
   {
       visited[node]=true;
       for(auto neighbour:adjlist[node] )
       {
           if(!visited[neighbour])
           {
               dfshelper(neighbour,visited,ordering);
           }
       }
       ///at this stage all the children of current node have been visited
       ordering.push_front(node);
   }
    void dfstopological()
    {
        ///topological sort is ordering of vertices in a directed acyclic graph in which
        ///each node comes before the nodes which it has edges
        ///if there is edge b/w u-v then u will come before v vertex in final ordering
        ///graph can't be cyclic bcz we can't determine origin
        ///most dependent node will come at last and least dependent will come before
        map<T,bool> visited;
        list<T> ordering;
        for(auto i:adjlist)
        {
           T node=i.first;
           if(!visited[node])
           {
               dfshelper(node,visited,ordering);
           }
        }
        for(auto i: ordering)
        {
            cout<<i<<" ";
        }

    }
    void bfstoplogical()
    {
        ///enqueue all vertex with 0 indegree
        ///degree of all the neighbours of the node decrease
        ///then push the node in queue
        queue<T>q;
        map<T,bool> visited;
        map<T,int> indegree;
        for(auto i:adjlist)
        {
            T node=i.first;
            visited[node]=false;
            indegree[node]=0;
        }

        for(auto i:adjlist)
        {
            T node=i.first;
            for(auto neighbour:adjlist[node])
            {
                indegree[neighbour]++;
            }
        }
         ///find out all the nodes with 0 degree
         for(auto i:adjlist)
         {
             T node=i.first;
             if(indegree[node]==0)
                q.push(node);
         }
         while(!q.empty())
         {
             T node=q.front();
             cout<<node<<" ";
             q.pop();
             for(auto neighbour:adjlist[node])
             {
                 indegree[neighbour]--;
                 if(indegree[neighbour]==0)
                    q.push(neighbour);
             }
         }
    }
    bool detect_helper(T node,map<T,bool>&visited,map<T,bool>& instack)
    {
        visited[node]=true;
        instack[node]=true;
        for(auto i:adjlist[node])
        {
            if((!visited[i]&&detect_helper(i,visited,instack))||instack[i])
                return true;
        }
        instack[node]=false;
        return false;

    }
    bool detectcycle()
    {
        map<T,bool> visited;
        map<T,bool> instack;
        for(auto i: adjlist)
        {
            T node=i.first;
            if(!visited[node])
            {
                bool cycleis=detect_helper(node,visited,instack);
                if(cycleis)
                    return true;
            }
        }
        return false;

    }
    bool cycleinundirected_graph_bfs(T src)
    {
        ///this can be achieved just maintained a visited array
        ///if we find an element which is already been visited then a cycle is present
        ///but we have to skip the parents for that we will maintain an array
        map<T,bool> visited;
        map<T,int> parent;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto neighbour:adjlist[node])
            if(visited[neighbour]==true&&parent[node]!=neighbour)
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                visited[neighbour]=true;
                parent[neighbour]=node;
                q.push(neighbour);
            }
        }
        return false;
    }
    bool dfshelperdetector(T node,map<T,bool>&visited,T parent)
    {
        visited[node]=true;
        for(auto neighbour: adjlist[node])
        {
            if(!visited[neighbour])
            {
             bool cycledetected=dfshelperdetector(neighbour,visited,node);
             if(cycledetected)
                return true;
            }

            else if(parent!=neighbour)
                return true;

        }
        return false;
    }
    bool cycleinundirected_graph_dfs()
    {
        map<T,bool> visited;
        for(auto i:adjlist)
        {
            T node=i.first;
            for(auto neightbour: adjlist[node])
            {
                if(!visited[neightbour])
                {
                    bool iscycle=dfshelperdetector(neightbour,visited,node);
                    if(iscycle)
                        return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph<int> g;
  /*  g.addedge(1,2,false);
    g.addedge(1,3,false);
    g.addedge(2,4,false);
    g.addedge(3,4,false);
   // g.addedge(4,1,false);*/
   ///undirected graph
   g.addedge(0,1);
   g.addedge(0,4);
   //g.addedge(4,2);
   g.addedge(2,1);
   g.addedge(4,3);
  g.addedge(3,2);
   g.addedge(3,5);
    g.print();
    cout<<endl;
    g.bfs(1);
    cout<<endl;
    g.dfs(1);
    cout<<endl;
    g.dfstopological();
    cout<<endl;
    g.bfstoplogical();
    cout<<endl;
   // cout<<g.detectcycle();
    cout<<endl;
    cout<<g.cycleinundirected_graph_bfs(1);
      cout<<endl;
      cout<<g.cycleinundirected_graph_dfs();

    return 0;

}
