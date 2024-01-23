/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-28
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[200001],b[200001];
int newb[200001];

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++)
        newb[i]=stream.readInt(1,200000);
    for(int i=1;i<=n;i++)
        if(newb[i]==a[i])quitf(_wa,"Wrong Answer");
    sort(newb+1,newb+1+n);
    for(int i=1;i<=n;i++)
        if(newb[i]!=b[i])quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)a[i]=inf.readInt();
    for(int i=1;i<=n;i++)b[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
