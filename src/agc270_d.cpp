/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
long long a[501][501];

void check(long long x,long long y,long long val){
    if(max(x,y)%min(x,y)!=val)
        quitf(_wa,"Wrong Answer");
}

bool solve(InStream& stream){
    set<long long> S;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            a[i][j]=stream.readLong(1,(long long)1e15);
            if(S.find(a[i][j])!=S.end())quitf(_wa,"Wrong Answer");
            else S.insert(a[i][j]);
        }
    long long val=max(a[1][1],a[1][2])%min(a[1][1],a[1][2]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i<n)check(a[i][j],a[i+1][j],val);
            if(j<n)check(a[i][j],a[i][j+1],val);
        }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    bool out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
