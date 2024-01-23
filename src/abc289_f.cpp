/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-08
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int sx,sy,tx,ty,a,b,c,d;

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    long long x=sx,y=sy;
    while(!stream.seekEof()){
        int posx=stream.readInt(a,b);
        int posy=stream.readInt(c,d);
        x=posx*2-x,y=posy*2-y;
    }
    if(x!=tx||y!=ty)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    sx=inf.readInt(),sy=inf.readInt();
    tx=inf.readInt(),ty=inf.readInt();
    a=inf.readInt(),b=inf.readInt();
    c=inf.readInt(),d=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
