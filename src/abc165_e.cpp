/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
bool vis[200001],ign[200001];

bool solve(InStream& stream){
    memset(vis,false,sizeof vis);
    memset(ign,false,sizeof ign);
    for(int i=1;i<=m;i++){
        int a=stream.readInt(1,n),b=stream.readInt(1,n);
        if(vis[a])quitf(_wa,"Wrong Answer"); vis[a]=true;
        if(vis[b])quitf(_wa,"Wrong Answer"); vis[b]=true;
        int pos=(b-a+n)%n;
        if(ign[pos]||pos*2==n)quitf(_wa,"Wrong Answer");
        ign[pos]=true,ign[n-pos]=true;
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
