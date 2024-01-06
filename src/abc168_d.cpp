/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-06
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
vector<int> E[100001];
int dis[100001];
bool vis[100001];

struct Node{
    int dis,id;
    bool operator>(Node tmp)const{
        return dis>tmp.dis;
    }
};

int nxt[100001];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    for(int i=2;i<=n;i++){
        nxt[i]=stream.readInt(1,n);
        if(dis[i]!=dis[nxt[i]]+1)
            quitf(_wa,"Wrong Answer");
    }
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
    }
    priority_queue<Node,vector<Node>,greater<Node> > Q;
    memset(dis,0x3f,sizeof dis);
    dis[1]=0,Q.push({0,1});
    int total=0;
    while(!Q.empty()){
        int u=Q.top().id; Q.pop();
        if(vis[u])continue; vis[u]=true,total++;
        for(int v :E[u])if(dis[v]>dis[u]+1)
            dis[v]=dis[u]+1,Q.push({dis[v],v});
    }
    int out=solve(ouf),answer=total==n;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
