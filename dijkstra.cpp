#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
   unordered_map<T,list<pair<T,int>>> m;
   public:
       void addedge(T u,T v,int dist,bool bidir=true)
       {
           m[u].push_back(make_pair(v,dist));
          // if(bidir)
            //m[v].push_back(make_pair(u,dist));
       }
       void print()
       {
           for(auto i:m)
           {
            cout<<i.first<<" ";
           for(auto j:m[i.first])
            cout<<j.first<<" "<<j.second;
           cout<<endl;
           }
       }
       void dijkstra(T src)
       {
           unordered_map<T,int> dist;
           for(auto j:m)
            dist[j.first]=INT_MAX;
           dist[src]=0;
           set<pair<int,T>>s;
           s.insert(make_pair(0,src));
           while(!s.empty())
           {
               auto p=*(s.begin());
               T node=p.second;
               int nodedist=p.first;
               s.erase(s.begin());
               for(auto f:m[node])
               {
                   if(nodedist+f.second<dist[f.first])
                   {
                       T dest=f.first;
                       auto t=s.find(make_pair(dist[dest],dest));
                       if(t!=s.end())
                       {
                           s.erase(t);
                       }
                       dist[dest]=nodedist+f.second;
                       s.insert(make_pair(dist[dest],dest));
                   }
               }
           }
           for(auto x:dist)
            cout<<x.first<<" "<<x.second<<endl;
       }



};
int main()
{
    graph<int> g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(1,4,7);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.dijkstra(1);

}
