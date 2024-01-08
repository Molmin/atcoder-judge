/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-08
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,u[200001],v[200001];
vector<int> E[200001];
set<pair<int,int> > S,T;

int dep[200001],fa[200001][19];
void dfs(int id,int father){
    dep[id]=dep[father]+1;
    fa[id][0]=father;
    for(int k=1;k<=18;k++)
        fa[id][k]=fa[fa[id][k-1]][k-1];
    for(int v :E[id])if(v!=father)dfs(v,id);
}

int LCA(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int k=18;k>=0;k--)
        if(dep[u]-dep[v]>=(1<<k))
            u=fa[u][k];
    if(u==v)return u;
    for(int k=18;k>=0;k--)
        if(fa[u][k]!=fa[v][k])
            u=fa[u][k],v=fa[v][k];
    return fa[u][0];
}

void readTree(InStream& stream){
    for(int i=1;i<=n;i++)E[i].clear();
    T.clear();
    for(int i=1;i<n;i++){
        int u=stream.readInt(1,n);
        int v=stream.readInt(1,n);
        if(S.find({u,v})==S.end())
            quitf(_wa,"Wrong Answer");
        E[u].push_back(v);
        E[v].push_back(u);
        T.insert({u,v});
        T.insert({v,u});
    }
    dfs(1,0);
}

bool solve(InStream& stream){
    readTree(stream);
    for(int i=1;i<=m;i++){
        if(T.find({u[i],v[i]})!=T.end())continue;
        int lca=LCA(u[i],v[i]);
        if(lca!=u[i]&&lca!=v[i])
            quitf(_wa,"Wrong Answer");
    }
    readTree(stream);
    for(int i=1;i<=m;i++){
        if(T.find({u[i],v[i]})!=T.end())continue;
        int lca=LCA(u[i],v[i]);
        if(lca==u[i]||lca==v[i])
            quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++){
        u[i]=inf.readInt();
        v[i]=inf.readInt();
        S.insert({u[i],v[i]});
        S.insert({v[i],u[i]});
    }
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
