/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[101];

int solve(InStream& stream){
    int total=0,x=stream.readInt(2,1000);
    for(int i=1;i<=n;i++)
        if(a[i]%x==0)total++;
    return total;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)a[i]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(out<answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
