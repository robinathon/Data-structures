#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int node,vector<int> Graph[], bool *visited,vector<int> &stack,int key)
{
    visited[node]=true;
    
    for(auto child:Graph[node])
    {
        if(!visited[child])
        {
            dfsHelper(child,Graph,visited,stack,key);
        }
    }
    if(key==1)
    stack.push_back(node);
    else
    cout<<node<<" ";

}

void solve(vector<int> Graph[], vector<int> revGraph[],int N)
{
    bool visited[N];
    vector<int> stack;
    memset(visited,0,N);
    //sorting the graph based on dfs finish time.
    for(int i=0;i<N;++i)
    {
        if(!visited[i])
        dfsHelper(i,Graph,visited,stack,1);
    }

    memset(visited,0,N);
    
    for(int x=stack.size()-1;x>=0;x--)
    {
        if(!visited[stack[x]]){
            dfsHelper(stack[x],revGraph,visited,stack,2);
            cout<<endl;
        }
    }
}

int main()
{
    int N;
    cin>>N;
    vector<int> Graph[N];
    vector<int> revGraph[N];// copy of Graph in reverse order.
    int M;
    cin>>M;
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        Graph[u].push_back(v);
        revGraph[v].push_back(u);
    }

    solve(Graph,revGraph,N);
}