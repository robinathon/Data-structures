#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{

    map<T,list<T>> l;

    public:
        void AddEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        queue<T> q;
        void bfs(T src)
        {
            map<T, bool> visited;
            q.push(src);
            visited[src]=true;
            
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                //cout<<node<<" ";
                for(int nbr:l[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
                cout<<node<<" ";
            }

        } 
};

int main()
{
    Graph <int>g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,4);
    g.AddEdge(4,3);
    g.AddEdge(4,0);

    g.bfs(0);
}