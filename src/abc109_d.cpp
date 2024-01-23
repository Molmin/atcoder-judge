/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-20
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,a[501][501],b[501][501];
bool flag[501][501];

int solve(InStream& stream){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            b[i][j]=a[i][j],flag[i][j]=false;
    int t=stream.readInt(0,n*m);
    for(int i=1;i<=t;i++){
        int sx=stream.readInt(1,n);
        int sy=stream.readInt(1,m);
        int tx=stream.readInt(1,n);
        int ty=stream.readInt(1,m);
        if(abs(sx-tx)+abs(sy-ty)!=1)quitf(_wa,"Wrong Answer");
        if(!b[sx][sy]||flag[sx][sy])quitf(_wa,"Wrong Answer");
        b[sx][sy]--,b[tx][ty]++,flag[sx][sy]=true;
    }
    int total=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)total+=b[i][j]%2==0;
    return total;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(out<answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
