/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-14
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
vector<pair<int,int> > E[100001];
int dep[100001];

void dfs(int id,int father){
    for(pair<int,int> e :E[id]){
        if(e.first==father)continue;
        dep[e.first]=dep[id]+e.second;
        dfs(e.first,id);
    }
}

bool check(vector<int> vec){
    for(int i=1;i<vec.size();i++)
        if((dep[vec[i]]-dep[vec[0]])&1)return false;
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    int n=inf.readInt(1,100000);
    for(int i=1;i<n;i++){
        int u=inf.readInt(1,n),v=inf.readInt(1,n),w=inf.readInt(0,1e9)&1;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    dfs(1,0);
    vector<int> color[2];
    for(int i=1;i<=n;i++){
        int c=ouf.readInt(0,1);
        color[c].push_back(i);
    }
    if(check(color[0])&&check(color[1]))quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}