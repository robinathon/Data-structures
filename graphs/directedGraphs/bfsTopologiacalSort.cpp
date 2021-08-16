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

    void bfs(int N)
    {
        int inDegree[N]={0};
        for(auto p:l)
        {
            int node=p.first;
            for(auto child:l[node])
            inDegree[child]++;
        }      
        queue<int> q;
        for(int i=0;i<N;++i)
        {
            if(inDegree[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto p:l[node])
            {
                inDegree[p]--;
                if(inDegree[p]==0)
                q.push(p);
            }
        }    
    }
};

int main()
{
    int N=6;
    Graph <int> g;
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.bfs(N);
}