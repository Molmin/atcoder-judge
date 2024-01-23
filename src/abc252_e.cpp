/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-14
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,u[200001],v[200001],c[200001];
vector<pair<int,int> > E[200001];
bool vis[200001];
long long dis[200001];

void dfs(int id,int father){
    vis[id]=true;
    for(pair<int,int> e :E[id]){
        if(e.first==father)continue;
        if(vis[e.first])quitf(_wa,"Wrong Answer");
        dis[e.first]=dis[id]+e.second;
        dfs(e.first,id);
    }
}

__int128 solve(InStream& stream){
    for(int i=1;i<=n;i++)E[i].clear();
    set<int> added;
    for(int i=1;i<n;i++){
        int id=stream.readInt(1,m);
        if(added.find(id)!=added.end())
            quitf(_wa,"Wrong Answer");
        added.insert(id);
        E[u[id]].push_back({v[id],c[id]});
        E[v[id]].push_back({u[id],c[id]});
    }
    dfs(1,0);
    __int128 sum=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++)sum+=dis[i];
    return sum;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++){
        u[i]=inf.readInt();
        v[i]=inf.readInt();
        c[i]=inf.readInt();
    }
    __int128 out=solve(ouf),answer=0;
    // NOTE: AtCoder provides the distance from point 1 to each point in the answer file
    for(int i=1;i<=n;i++)answer+=ans.readLong();
    if(out==answer)quitf(_ok,"Correct");
    else if(out>answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
