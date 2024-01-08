/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-08
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int w,n,a[301];
bool vis[1000001];

bool solve(InStream& stream){
    n=stream.readInt(1,300);
    for(int i=1;i<=n;i++)
        a[i]=stream.readInt(1,1000000),
        vis[a[i]]=true;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]+a[j]<=1000000)
                vis[a[i]+a[j]]=true;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(a[i]+a[j]+a[k]<=1000000)
                    vis[a[i]+a[j]+a[k]]=true;
    for(int i=1;i<=w;i++)
        if(!vis[i])quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    w=inf.readInt();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
