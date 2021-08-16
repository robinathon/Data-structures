#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    map<T,list<T>> l;
    public:

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cyclic_hai(int node,map<int,bool> &visited, int parent)
    {
        visited[node]=true;
        for(auto child:l[node])
        {
            if(!visited[child])
            {
                return cyclic_hai(child,visited,node);
            }
            else if(child!=parent)
            return true;
        }
        return false;
    }

    bool isCyclic(int start)
    {
        map<int,bool> visited;
        for(auto p:l)
        {
            visited[p.first]=false;
        }
        return cyclic_hai(start,visited,-1);
    }

};

int main()
{
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    //g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);


    if(g.isCyclic(0))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}