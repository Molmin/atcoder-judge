/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-03-11
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,p[20001],a[20001],b[20001];

bool solve(InStream& stream){
    for(int i=1;i<=n;i++)
        a[i]=stream.readInt(1,1e9);
    for(int i=1;i<=n;i++)
        b[i]=stream.readInt(1,1e9);
    for(int i=1;i<n;i++)
        if(a[i]>=a[i+1]||b[i]<=b[i+1])return false;
    for(int i=1;i<n;i++)
        if(a[p[i]]+b[p[i]]>=a[p[i+1]]+b[p[i+1]])return false;
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)
        p[i]=inf.readInt();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
