/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-04
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a,b,c;
string str[100001];

bool solve(InStream& stream,bool onlyAnswer=false){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(onlyAnswer)return true;
    int val[1000];
    val['A']=a,val['B']=b,val['C']=c;
    for(int i=1;i<=n;i++){
        string s=stream.readToken();
        if(s.size()!=1)quitf(_wa,"Wrong Answer");
        if(s[0]!=str[i][0]&&s[0]!=str[i][1])quitf(_wa,"Wrong Answer");
        if(s[0]==str[i][0])val[s[0]]++,val[str[i][1]]--;
        else val[s[0]]++,val[str[i][0]]--;
    }
    if(!(val['A']>=0&&val['B']>=0&&val['C']>=0))quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    a=inf.readInt(),b=inf.readInt(),c=inf.readInt();
    for(int i=1;i<=n;i++)str[i]=inf.readToken();
    int out=solve(ouf),answer=solve(ans,true);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
