/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

mt19937 mt_rand(random_device{}());

int n;

struct Tree{
    int root;
    vector<int> E[100001];
    
    inline void addEdge(int u,int v){
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int dep[100001],fa[100001][18],siz[100001];

    void init(int id,int father){
        siz[id]=1;
        fa[id][0]=father;
        dep[id]=dep[father]+1;
        for(int k=1;k<=17;k++)
            fa[id][k]=fa[fa[id][k-1]][k-1];
        for(int v :E[id]){
            if(v==father)continue;
            init(v,id);
            siz[id]+=siz[v];
        }
    }

    inline int getlca(int u,int v){
        if(dep[u]<dep[v])swap(u,v);
        for(int k=17;k>=0;k--)
            if(dep[u]-dep[v]>=(1<<k))
                u=fa[u][k];
        if(u==v)return u;
        for(int k=17;k>=0;k--)
            if(fa[u][k]!=fa[v][k])
                u=fa[u][k],v=fa[v][k];
        return fa[u][0];
    }

    inline bool isOnChain(int u,int v,int x){
        return getlca(u,x)==x&&getlca(x,v)==v;
    }
}T,R;

bool solve(InStream& stream){
    for(int i=1;i<=n;i++){
        int fa=stream.readInt(-1,n);
        if(fa==-1){
            if(R.root)quitf(_wa,"Wrong Answer");
            else R.root=i;
            continue;
        }
        else if(fa==0||fa==i)quitf(_wa,"Wrong Answer");
        R.addEdge(fa,i);
    }
    if(!R.root)quitf(_wa,"Wrong Answer");
    R.init(R.root,0);
    for(int i=1;i<=n;i++){
        if(i==R.root)continue;
        if(R.siz[i]*2>R.siz[R.fa[i][0]])quitf(_wa,"Wrong Answer");
    }
    for(int i=1;i<=min(5ll*n*n,1000000ll);i++){
        int u=mt_rand()%n+1;
        int v=mt_rand()%n+1;
        if(u==v)continue;
        int lca=R.getlca(u,v);
        int lca2=T.getlca(u,v);
        if(!T.isOnChain(u,lca2,lca)&&!T.isOnChain(v,lca2,lca))
            quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),T.root=1;
    for(int i=1;i<n;i++){
        int u=inf.readInt();
        int v=inf.readInt();
        T.addEdge(u,v);
    }
    T.init(1,0);
    bool out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
