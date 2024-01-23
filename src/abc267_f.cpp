/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-15
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,u,d;
vector<int> E[200001];

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

bool solve(InStream& stream){
    int v=stream.readInt(-1,n);
    if(v==-1)return false;
    else if(v==0)quitf(_wa,"Wrong Answer");
    int dis=dep[u]+dep[v]-dep[LCA(u,v)]*2;
    if(dis!=d)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<n;i++){
        int u=inf.readInt();
        int v=inf.readInt();
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    int q=inf.readInt();
    for(int i=1;i<=q;i++){
        u=inf.readInt(),d=inf.readInt();
        int out=solve(ouf),answer=solve(ans);
        if(out==answer)continue;
        else if(answer)quitf(_wa,"Wrong Answer");
        else quitf(_fail,"Failed");
    }
    quitf(_ok,"Correct");
    return 0;
}
