#include<bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> par;
    void init(int n) {
        par.resize(n);
        iota(par.begin(),par.end(),0);
    }

    int get(int x){
        return (x==par[x] ? x:(par[x]=get(par[x])));
    }

    void unite(int x,int y){
        x=get(x);
        y=get(y);
        if(x!=y)
        {
            par[x]=max(par[x],par[y]);
        }
    }
};

int main()
{
    int n,q;
    cin>>n>>q;
    int l[q],r[q],c[q];
    for(int i=0;i<q;++i)
    {
        cin>>l[i]>>r[i]>>c[i];
    }

    dsu G;
    G.init(n+2);
    int res[n+2]={};

    for(int i=q-1;i>=0;i--)
    {
        int index=G.get(l[i]); //to get the right next unfilled index;


        while(index <= r[i])
        {
            res[index]=c[i];
            G.unite(index,index+1);
            index=G.get(index); //to jump the next unfilled box.
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<res[i]<<" ";
    }
}