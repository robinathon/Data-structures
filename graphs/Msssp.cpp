#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T ,list<T>> l;

    public:
    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    
    public:
    void bfs(T src)
    {
        map<int,int> dis;
        for(auto pair:l)
        {
            dis[pair.first]=INT_MAX;
        }
        queue<int> q;
        q.push(src);
        dis[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto child:l[node])
            {

                if(dis[child]==INT_MAX)
                {
                    dis[child]=dis[node]+1;
                    q.push(child);
                }
            }
        }

        for(auto node_pair:dis)
        {
            cout<<node_pair.first<<" "<<node_pair.second<<endl;
        }
    }

};

int main()
{
    Graph <int> g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);

    g.bfs(0);
}