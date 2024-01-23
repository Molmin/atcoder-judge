/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-28
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a,b,d[2001];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    string ops=stream.readToken();
    if(ops.size()!=n)quitf(_wa,"Wrong Answer");
    int x=0,y=0;
    for(int i=1;i<=n;i++)
        if(ops[i-1]=='U')y+=d[i];
        else if(ops[i-1]=='D')y-=d[i];
        else if(ops[i-1]=='L')x-=d[i];
        else if(ops[i-1]=='R')x+=d[i];
        else quitf(_wa,"Wrong Answer");
    if(x!=a||y!=b)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),a=inf.readInt(),b=inf.readInt();
    for(int i=1;i<=n;i++)d[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
