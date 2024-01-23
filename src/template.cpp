/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-01
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
