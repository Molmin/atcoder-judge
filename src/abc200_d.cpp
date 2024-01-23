/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-29
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[201],x,y,b[201],c[201];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    x=stream.readInt(1,n);
    for(int i=1;i<=x;i++)b[i]=stream.readInt(1,n);
    y=stream.readInt(1,n);
    for(int i=1;i<=y;i++)c[i]=stream.readInt(1,n);
    for(int i=1;i<x;i++)
        if(b[i+1]<=b[i])quitf(_wa,"Wrong Answer");
    for(int i=1;i<y;i++)
        if(c[i+1]<=c[i])quitf(_wa,"Wrong Answer");
    bool isSame=x==y;
    for(int i=1;i<=min(x,y);i++)
        if(b[i]!=c[i])isSame=false;
    if(isSame)quitf(_wa,"Wrong Answer");
    long long sumx=0,sumy=0;
    for(int i=1;i<=x;i++)sumx+=a[b[i]];
    for(int i=1;i<=y;i++)sumy+=a[c[i]];
    if(sumx%200!=sumy%200)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)a[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
