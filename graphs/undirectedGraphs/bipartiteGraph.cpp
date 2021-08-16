#include<bits/stdc++.h>
using namespace std;

bool dfsHelper(vector<int> G[],int node,int *visited,int par,int color)
{
    visited[node]=color;
    for(auto nbr:G[node])
    {
        if(visited[nbr]==0)
        {
            int subProb=dfsHelper(G,nbr,visited,node,3-color);
            if(subProb==false)
            return false;
        }
        else if(nbr!=par and color==visited[nbr])
        return false;
    }
    return true;
}

bool dfs(vector<int> G[],int N)
{
    int visited[N]={0}; //0 means visited , 1 means color-1, 2 means color-2
    int color =1;
    int check=dfsHelper(G,1,visited ,-1,color);

    for(int i=0;i<N;++i)
    {
        cout<<i<<"-color-"<<visited[i]<<endl;
    }
    return check;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> G[n];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(dfs(G,n))
    cout<<"yes";
    else
    cout<<"no";
}