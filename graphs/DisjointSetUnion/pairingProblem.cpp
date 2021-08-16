/*given N nodes i.e cities and M edges i.e undirected roads ,find the no.of ways to choose two city such that 
there is no path from city 1 to 2.*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> l;
    public:
    Graph(int N){
        this->v=N;
    }
    void addEdge(int x,int y)
    {
        l.push_back({x,y});
    }

    int findSet(int x,int parent[])
    {
        if(parent[x]==-1)
        return x;
        else
        return parent[x]=findSet(parent[x],parent);
    }

    void set_union(int x,int y,int parent[],int rank[])
    {
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])  /*Here rank[s1] means no.of nodes attached with s1. Time complexity of the program with both path compression and union by rank optimazatio becomes O(~1)*/            
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            else
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
        }
    }

    int pairing()
    {
        int *parent=new int [v];
        int *rank=new int [v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }

        for(auto edge:l)
        {
            int u=edge.first;
            int v=edge.second;

            set_union(u,v,parent,rank);
        }

        int sum=0;
        for(int i=0;i<v;i++)
        {
            sum+=v-rank[findSet(i,parent)];
        }
        return sum/2;
    }
};

int main()
{
    int N,M;
    cin>>N>>M;
    Graph g(N);
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<g.pairing()<<endl;
}