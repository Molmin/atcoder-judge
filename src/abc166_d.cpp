/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int LIMIT=1<<21;

int x;

__int128 calc(int x){
    __int128 res=1;
    for(int i=1;i<=5;i++)res*=x;
    return res;
}

int solve(InStream& stream){
    int a=stream.readInt(-LIMIT,LIMIT),b=stream.readInt(-LIMIT,LIMIT);
    __int128 res=calc(a)-calc(b);
    if(res!=(__int128)x)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    x=inf.readInt();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
