/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-23
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
vector<int> E[100001];
set<pair<int,int> > edges;

bool solve(InStream& stream){
    int l=stream.readInt(2,n);
    vector<int> vec;
    for(int i=1;i<=l;i++)
        vec.push_back(stream.readInt(1,n));
    set<int> S;
    for(int i=0;i<l;i++){
        if(S.find(vec[i])!=S.end())
            quitf(_wa,"Wrong Answer");
        S.insert(vec[i]);
        if(i&&edges.find({vec[i-1],vec[i]})==edges.end())
            quitf(_wa,"Wrong Answer");
    }
    for(int v :E[vec[0]])if(S.find(v)==S.end())quitf(_wa,"Wrong Answer");
    for(int v :E[vec.back()])if(S.find(v)==S.end())quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++){
        int u=inf.readInt();
        int v=inf.readInt();
        E[u].push_back(v);
        E[v].push_back(u);
        edges.insert({u,v});
        edges.insert({v,u});
    }
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
