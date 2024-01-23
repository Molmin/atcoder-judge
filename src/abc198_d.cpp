/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-29
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

string s1,s2,s3;
int val[300];

bool solve(InStream& stream){
    string n1=stream.readToken(),n2,n3;
    if(n1=="UNSOLVABLE")return false;
    n2=stream.readToken(),n3=stream.readToken();
    if(n1.size()!=s1.size()||n2.size()!=s2.size()||n3.size()!=s3.size())
        quitf(_wa,"Wrong Answer");
    long long val1=0,val2=0,val3=0;
    if(n1[0]=='0')quitf(_wa,"Wrong Answer");
    for(int i=0;i<n1.size();i++){
        if(!('0'<=n1[i]&&n1[i]<='9'))quitf(_wa,"Wrong Answer");
        val[s1[i]]=n1[i],val1=val1*10+n1[i]-'0';
    }
    if(n2[0]=='0')quitf(_wa,"Wrong Answer");
    for(int i=0;i<n2.size();i++){
        if(!('0'<=n2[i]&&n2[i]<='9'))quitf(_wa,"Wrong Answer");
        val[s2[i]]=n2[i],val2=val2*10+n2[i]-'0';
    }
    if(n3[0]=='0')quitf(_wa,"Wrong Answer");
    for(int i=0;i<n3.size();i++){
        if(!('0'<=n3[i]&&n3[i]<='9'))quitf(_wa,"Wrong Answer");
        val[s3[i]]=n3[i],val3=val3*10+n3[i]-'0';
    }
    if(val1+val2!=val3)quitf(_wa,"Wrong Answer");
    for(int i=0;i<n1.size();i++)
        if(n1[i]!=val[s1[i]])quitf(_wa,"Wrong Answer");
    for(int i=0;i<n2.size();i++)
        if(n2[i]!=val[s2[i]])quitf(_wa,"Wrong Answer");
    for(int i=0;i<n3.size();i++)
        if(n3[i]!=val[s3[i]])quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    s1=inf.readToken(),s2=inf.readToken(),s3=inf.readToken();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
