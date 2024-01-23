/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-23
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[300003],s[300001];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n+2;i++)a[i]=stream.readInt(0,(int)1e9);
    for(int i=1;i<=n;i++)
        if(s[i]!=a[i]+a[i+1]+a[i+2])
            quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)s[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
