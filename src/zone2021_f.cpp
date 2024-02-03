/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-02-03
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
set<int> S;
int fa[1<<18];
int find(int id){
    if(fa[id]==id)return id;
    else return fa[id]=find(fa[id]);
}

bool solve(InStream& stream){
    int first=stream.readInt(-1,n-1);
    if(first==-1)return false;
    for(int i=0;i<n;i++)fa[i]=i;
    for(int i=1;i<n;i++){
        int u=i==1?first:stream.readInt(0,n-1);
        int v=stream.readInt(0,n-1);
        int fu=find(u),fv=find(v);
        if(S.find(u^v)!=S.end()||fu==fv)
            quitf(_wa,"Wrong Answer");
        fa[fu]=fv;
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++){
        int x=inf.readInt();
        S.insert(x);
    }
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
