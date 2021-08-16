#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{

    map<T,list<T>> l;

    public:
        void AddEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void dfs_helper(T src,map<T,bool> &visited)
        {
            cout<<src<<" ";
            visited[src]=true;

            for(auto nbr:l[src])
            {
                if(!visited[nbr])
                {
                    dfs_helper(nbr,visited);
                }
            }
        }

        void dfs(T src)
        {
            map<T,bool> visited;
            for(auto p:l)
            {
                T node=p.first;
                visited[node]=false;
            }

            dfs_helper(src,visited);
        }
};

int main()
{
    Graph<int> g;
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,6);
    g.AddEdge(5,6);
    g.AddEdge(6,7);

    g.dfs(0);
}