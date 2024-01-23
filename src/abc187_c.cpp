/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n;
string str[200001];

bool solve(InStream& stream){
    string answer=stream.readToken();
    if(answer=="satisfiable")return false;
    bool flag1=false,flag2=false;
    for(int i=0;i<answer.size();i++)
        if(answer[i]<'a'||answer[i]>'z')quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++){
        if(str[i]==answer)flag1=true;
        if(str[i]=="!"+answer)flag2=true;
    }
    if(!flag1||!flag2)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)str[i]=inf.readToken();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
