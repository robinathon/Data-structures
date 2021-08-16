#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll child=0,q;

template<typename T>
class Graph{
    map<ll,list<T>> l;
    public:
    void AddEdge(ll x,ll y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<ll,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<" ";
        child++;
        for(auto node:l[src])
        {
            if(!visited[node])
            {
                dfs_helper(node,visited);
            }
        }
    }

    ll per(ll m,ll n)
    {
        ll c=m-n,num=1;
        for(;m>c;m--)
        {
            num=num*m;
        }
        return num/n;
    }

    void dfs()
    {
        map<ll,bool> visited;
        map<ll,ll> c_men;
        for(auto p:l)
        {
            visited[p.first]=false;
        }
        ll cnt=0;

        for(auto p:l)
        {
            child=0;
            ll node=p.first;
            if(!visited[node])
            {
                dfs_helper(node,visited);
                cout<<endl;
                cout<<cnt<<" "<<child<<endl;
                c_men[cnt]=child;
                cnt++;
            }
            
        }

        ll total=per(q,2);
        ll comm=0;
        for(auto p:c_men)
        {
            comm=comm+per(c_men[p.first],2);
        }

        cout<<total-comm<<endl;

    }
};

int main()
{
    ll p;
    cin>>q>>p;
    Graph<ll> g;
    while(p--)
    {
        ll u,v;
        cin>>u>>v;
        g.AddEdge(u,v);
    }

    g.dfs();

}