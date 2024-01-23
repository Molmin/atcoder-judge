/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,deg[200001],u[200001],v[200001];
vector<int> E[200001];
int fa[200001];
int find(int id){
    if(fa[id]==id)return id;
    else return fa[id]=find(fa[id]);
}

bool solve(InStream& stream){
    int first=stream.readInt(-1,n);
    if(first==-1)return false;
    if(first==0)quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++)
        E[i].clear(),fa[i]=i;
    for(int i=1;i<=m;i++){
        fa[find(u[i])]=find(v[i]);
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }
    for(int i=1;i<n-m;i++){
        int u,v;
        u=i==1?first:stream.readInt(1,n);
        v=stream.readInt(1,n);
        if(find(u)==find(v))quitf(_wa,"Wrong Answer");
        fa[find(u)]=find(v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1;i<n;i++)
        if(find(i)!=find(n))quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++)
        if(E[i].size()!=deg[i])quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=n;i++)deg[i]=inf.readInt();
    for(int i=1;i<=m;i++)u[i]=inf.readInt(),v[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
