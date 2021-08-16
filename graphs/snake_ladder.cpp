#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
    map<int,list<int>> l;
    public:
        void AddEdge(int x,int y)
        {
            l[x].push_back(y);
        }

        void bfs(t src,int tgt)
        {
            map<int,int> dist;
            map<int,int> parent;
            parent[src]=src;
            queue<t> q;
            for(auto pair:l)
            {
                auto node=pair.first;
                dist[node]=INT_MAX;
            }
            dist[36]=INT_MAX;            //because in the upper loop ,it is only upto 35.
            q.push(src);
            dist[1]=0;
            while(!q.empty())
            {
                t node=q.front();
                q.pop();
                
                for(int nbr: l[node])
                {
                    if(dist[nbr]==INT_MAX)
                    {
                        q.push(nbr);
                        dist[nbr]=dist[node]+1;
                        parent[nbr]=node;
                    }
                }
            }
            t temp=tgt;
            while(temp!=src)
            {
                cout<<temp<<"<-";
                temp=parent[temp];
            }
            cout<<src;
        }

};

int main()
{
    int board[50]={0};

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    Graph <int> g;
    for(int i=1;i<36;i++)
    {
        for(int j=1;j<=6;++j)
        {
            int step=i+j+board[i+j];
            if(step<=36)
            g.AddEdge(i,step);
        }
    }
    g.bfs(1,36);
}