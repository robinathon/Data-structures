#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<pair<int,int>> l;
    public:
    Graph(int v)
    {
        this->v=v;
    }
    void AddEdge(int u,int v)
    {
        l.push_back({u,v});
    }

    int findSet(int x,int parent[])
    {
        if(parent[x]==-1)
        return x;
        else
        return parent[x]=findSet(parent[x],parent); 
        //path compression optimosation; parent of allnode of a set becomes root.
        //by doing this complexity of findSet becomes logn as no longer we have to traverse from each node in the path to reach the root node.
    }
    

    bool Union(int u,int v,int parent[])
    {
        if(findSet(u,parent)!=findSet(v,parent))
        {
            parent[u]=v;
            return false;
        }
        else
        return true;
    }

    bool isCyclic()
    {
        int *parent=new int [v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
        }

        for(auto p:l)
        {
            int u=p.first;
            int v=p.second;
            bool cyclic=Union(u,v,parent);
            if(cyclic==1)
            return true;
        }
        return false;
    }

};

int main()
{
 Graph g(4);
 g.AddEdge(0,1);
 g.AddEdge(1,2);
 g.AddEdge(2,3);
 g.AddEdge(3,1);

 if(g.isCyclic())
 cout<<"cyclic";
 else
 cout<<"not cyclic";
}