/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
int a[1001],b[1001];
int u[200001],v[200001];

bool solve(InStream& stream){
    int k=stream.readInt(-1,500000);
    if(k==-1)return false;
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=k;i++){
        int id=stream.readInt(1,m);
        swap(b[u[id]],b[v[id]]);
    }
    for(int i=1;i<=n;i++)
        if(b[i]!=i)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)a[i]=inf.readInt();
    m=inf.readInt();
    for(int i=1;i<=m;i++)
        u[i]=inf.readInt(),v[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
