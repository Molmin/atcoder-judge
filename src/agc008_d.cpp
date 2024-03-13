/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-03-13
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,x[501],tot[501];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    memset(tot,0,sizeof tot);
    for(int i=1;i<=n*n;i++){
        int v=stream.readInt(1,n);
        tot[v]++;
        if(tot[v]==v&&i!=x[v])quitf(_wa,"Wrong Answer");
    }
    for(int i=1;i<=n;i++)
        if(tot[i]!=n)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)
        x[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
