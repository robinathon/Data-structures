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
    }
    

    bool Union(int u,int v,int parent[],int rank[])
    {
        int s1=findSet(u,parent);
        int s2=findSet(v,parent);
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])      /*Here rank[s1] means no.of nodes attached with s1. Time complexity of the program with both path compression and union by rank optimazatio becomes O(~1)*/            
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            else
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            return false;
        }
        else
        return true;
    }

    bool isCyclic()
    {
        int *parent=new int [v];
        int *rank=new int [v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }

        for(auto p:l)
        {
            int u=p.first;
            int v=p.second;
            bool cyclic=Union(u,v,parent,rank);
            if(cyclic==1)
            return true;
        }
        delete [] parent;
        delete [] rank;
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