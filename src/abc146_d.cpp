/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
vector<pair<int,int> > E[100001];
int col[100001];

int solve(InStream& stream){
    int k=stream.readInt(1,n);
    for(int i=1;i<n;i++)
        col[i]=stream.readInt(1,k);
    for(int i=1;i<=n;i++){
        set<int> S;
        for(pair<int,int> e :E[i])
            S.insert(col[e.first]);
        if(S.size()!=E[i].size())
            quitf(_wa,"Wrong Answer");
    }
    return k;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<n;i++){
        int u,v;
        u=inf.readInt(),v=inf.readInt();
        E[u].push_back({i,v});
        E[v].push_back({i,u});
    }
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(out>answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
