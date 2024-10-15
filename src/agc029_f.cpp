/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-10-15
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
set<int> S[100001];
int fa[100001];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}

bool solve(InStream& stream){
    int first=stream.readInt(-1,n);
    if(first==0)quitf(_wa,"Wrong Answer");
    if(first==-1)return false;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<n;i++){
        int u=first?first:stream.readInt(1,n),v=stream.readInt(1,n);
        if(first)first=0;
        if(find(u)==find(v))quitf(_wa,"Wrong Answer");
        fa[find(u)]=find(v);
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(2,1e5);
    for(int i=1;i<n;i++){
        int k=inf.readInt(2,n);
        while(k--)S[i].insert(inf.readInt(1,n));
    }
    int out=solve(ouf),answer=ans.readInt(-1,1)==1;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
