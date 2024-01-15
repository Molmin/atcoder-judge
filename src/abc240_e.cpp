/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-15
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,l[200001],r[200001];
vector<int> E[200001];

void dfs(int id,int father){
    vector<pair<int,int> > vec;
    for(int v :E[id])if(v!=father){
        dfs(v,id);
        if(l[id]>l[v]||r[id]<r[v])quitf(_wa,"Wrong Answer");
        vec.push_back({l[v],r[v]});
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<vec.size();i++)
        if(vec[i].first<=vec[i-1].second)
            quitf(_wa,"Wrong Answer");
}

int solve(InStream& stream){
    int maxn=0;
    for(int i=1;i<=n;i++){
        l[i]=stream.readInt(1,n);
        r[i]=stream.readInt(l[i],n);
        maxn=max(maxn,r[i]);
    }
    dfs(1,0);
    return maxn;
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
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(out>answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
