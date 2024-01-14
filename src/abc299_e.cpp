/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-14
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,k,p[2001],d[2001];
vector<int> E[2001];
int dis[2001][2001];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    string answer=stream.readToken();
    if(answer.size()!=n)quitf(_wa,"Wrong Answer");
    for(int i=1;i<=k;i++){
        int minn=0x3f3f3f3f;
        for(int j=1;j<=n;j++)
            if(answer[j-1]=='1')minn=min(minn,dis[p[i]][j]);
        if(minn!=d[i])quitf(_wa,"Wrong Answer");
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
    k=inf.readInt();
    for(int i=1;i<=k;i++)
        p[i]=inf.readInt(),d[i]=inf.readInt();
    for(int i=1;i<=n;i++){
        bool vis[2001]={};
        int d[2001]={};
        priority_queue<pair<int,int> > Q;
        memset(d,0x3f,sizeof d);
        d[i]=0,Q.push({0,i});
        int total=0;
        while(!Q.empty()){
            int u=Q.top().second; Q.pop();
            if(vis[u])continue; vis[u]=true;
            for(int v :E[u])if(d[v]>d[u]+1)
                d[v]=d[u]+1,Q.push({-d[v],v});
        }
        for(int j=1;j<=n;j++)
            dis[i][j]=d[j];
    }
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
