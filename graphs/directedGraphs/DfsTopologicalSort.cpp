#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
    map<int,list<int>> l;
    public:
    void addEdge(t x,t y)
    {
        l[x].push_back(y);
    }
    void dfs_helper(int node,int *visited,list<int> &Tsrt)
    {
        visited[node]=1;
        for(auto child:l[node])
        {
            if(!visited[child])
            dfs_helper(child,visited,Tsrt);
        }
        Tsrt.push_front(node);
    }

    void dfs(t N)
    {
        int visited[N]={0};
        list<int> Tsrt;

        for(auto p:l)
        {
            int node=p.first;
            if(!visited[node]){
                cout<<node<<endl;
            dfs_helper(node,visited,Tsrt);
            }
        }
        
        for(auto num:Tsrt)
        {
            cout<<num<<" ";
        }
        
    }    
};

int main()
{
    int N=6;
    Graph <int> g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(4, 2);
    g.addEdge(3, 1);

    g.dfs(N);
}