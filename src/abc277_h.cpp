/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-08
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,q;
int a[10001],b[10001],l[10001],r[10001];
int x[10001];

bool solve(InStream& stream){
    int first=stream.readInt(-1,m);
    if(first==-1)return false;
    for(int i=1;i<=n;i++)
        x[i]=i==1?first:stream.readInt(0,m);
    for(int i=1;i<=q;i++){
        int val=x[a[i]]+x[b[i]];
        if(val<l[i]||r[i]<val)
            quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt(),q=inf.readInt();
    for(int i=1;i<=q;i++){
        a[i]=inf.readInt(),b[i]=inf.readInt();
        l[i]=inf.readInt(),r[i]=inf.readInt();
    }
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
