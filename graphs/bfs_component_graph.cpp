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
            void bfs(T src)
            {
                queue<T> q;
                map<T, bool> visited;
                int cnt=0;
                for(auto p:l)
                {
                    
                    if(!visited[p.first])
                    {
                        q.push(p.first);
                        visited[p.first]=true;
                        cout<<"component "<<cnt<<"-->";
                        while(!q.empty())
                        {
                            int node=q.front();
                            q.pop();
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
                        cout<<endl;
                        cnt++;
                    }
                }
            
            }

} ;

int main()
{
    Graph <int>g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(3,0);
    g.AddEdge(5,6);
    g.AddEdge(6,7);
    g.AddEdge(8,8);

    g.bfs(0);
}