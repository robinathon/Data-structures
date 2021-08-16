#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
    map<int,list<int>> l;
    public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
    }

        bool dfsHelper(int node ,map<int,bool>&visited, map<int,bool>&stack)
        {
            visited[node]=true;
            stack[node]=true;
            for(auto p:l[node])
            {
                if(stack[p]==true)
                return true;
                else if(!visited[p])
                {
                    bool cycleMila= dfsHelper(p,visited,stack);
                    if(cycleMila)
                    return true;
                }
            }

            stack[node]=false;
            return false;
        }

        bool dfs()
        {
            map<int,bool> visited;
            map<int,bool> stack;
            for(auto p:l)
            {
                visited[p.first]=false;
            }
            return dfsHelper(0,visited,stack);
        }
    
};

int main()
{
    Graph <int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2);
    if(g.dfs())
    cout<<"cycle present";
    else
    cout<<"cycle not present";

}