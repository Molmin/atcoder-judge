/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-29
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const long long LIMIT=1e18;

int k,x,y;

int solve(InStream& stream,bool onlyAnswer=false){
    int n=stream.readInt(-1,10000000);
    if(n==-1)return 1e8;
    else if(onlyAnswer)return n;
    long long nowx=0,nowy=0;
    for(int i=1;i<=n;i++){
        long long newx=stream.readLong(-LIMIT,LIMIT);
        long long newy=stream.readLong(-LIMIT,LIMIT);
        if(abs(newx-nowx)+abs(newy-nowy)!=k)quitf(_wa,"Wrong Answer");
        nowx=newx,nowy=newy;
    }
    if(nowx!=x||nowy!=y)quitf(_wa,"Wrong Answer");
    return n;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    k=inf.readInt(),x=inf.readInt(),y=inf.readInt();
    int out=solve(ouf),answer=solve(ans,true);
    if(out==answer)quitf(_ok,"Correct");
    else if(out>answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
