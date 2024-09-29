/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-09-24
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
vector<int> E[2001];

int fa[2001],dep[2001],c[2001];
void init(int u,int father){
    fa[u]=father,dep[u]=dep[father]+1;
    for(int v :E[u])if(v!=father)init(v,u);
}

int solve(InStream& stream){
    int res=stream.readInt(0,(n-1)*2);
    for(int i=1;i<=m;i++){
        int u=stream.readInt(1,n);
        int v=stream.readInt(1,n);
        int x=inf.readInt(1,n);
        int y=inf.readInt(1,n);
        if(u+v!=x+y)quitf(_wa,"Wrong Answer");
        if(u!=x&&u!=y)quitf(_wa,"Wrong Answer");
        while(u!=v){
            if(dep[u]>dep[v])c[u]|=1,u=fa[u];
            else c[v]|=2,v=fa[v];
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)sum+=(c[i]>>1)+(c[i]&1);
    if(sum!=res)quitf(_wa,"Wrong Answer");
    return res;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(1,2000);
    m=inf.readInt(0,2000);
    for(int i=1;i<n;i++){
        int u=inf.readInt(1,n);
        int v=inf.readInt(1,n);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    init(1,0);
    int out=solve(ouf),answer=ans.readInt();
    if(out==answer)quitf(_ok,"Correct");
    else if(out<answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
