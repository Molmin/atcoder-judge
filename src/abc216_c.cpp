/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

long long n;

int solve(InStream& stream){
    string s=stream.readToken();
    if(s.size()>120)quitf(_wa,"Wrong Answer");
    long long now=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            if(now+1>n)quitf(_wa,"Wrong Answer");
            now++;
        }
        else{
            if(now*2>n)quitf(_wa,"Wrong Answer");
            now*=2;
        }
    }
    if(now!=n)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readLong();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
