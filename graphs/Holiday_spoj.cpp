#include<bits/stdc++.h>
using namespace std;
int V;

template<typename T>
class Graph{
    map<int,list<pair<int,int>>> l;
    public:
    void AddEdge(int x,int y,int w)
    {
        l[x].push_back(make_pair(y,w));
        l[y].push_back(make_pair(x,w));
    }

    int dfs_helper(int node,int visited[],int &ans,int count[])
    {
        visited[node]=1;
        count[node]=1;
        for(auto pair:l[node])
        {
            int nbr=pair.first;
            int wgt=pair.second;
            if(!visited[nbr])
            {
                count[node]+=dfs_helper(nbr,visited,ans,count);
                int lft=count[nbr];
                int rgt=V-lft;
                ans+=min(lft,rgt)*2*wgt;
            }
        }
        return count[node];
    }

    int bfs(int src,int v)
    {
        int visited[V]={0};
        int count[V]={0};
        int ans=0;
        dfs_helper(src,visited,ans,count);
        return ans;
    }
};

int main()
{
    Graph<int> g;
    cin>>V;
    int t=V;
    while((t--)-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.AddEdge(u,v,w);
    }
    cout<<g.bfs(0,V)<<endl;
}