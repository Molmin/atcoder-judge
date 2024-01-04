/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-29
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,s[501],t[501];
unsigned long long u[501],v[501],a[501][501];

unsigned long long toUnsignedLong(string str){
    unsigned long long ret=0;
    if(str.size()==0||str[0]=='0')quitf(_wa,"Wrong Answer");
    for(int i=0;i<str.size();i++){
        if(str[i]<'0'||'9'<str[i])quitf(_wa,"Wrong Answer");
        if(ret*10+str[i]-'0'<=ret)quitf(_wa,"Wrong Answer");
        ret=ret*10+str[i]-'0';
    }
    return ret;
}

bool solve(InStream& stream){
    string first=stream.readToken();
    if(first=="-1")return false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==1&&j==1)a[1][1]=toUnsignedLong(first);
            else a[i][j]=stream.readUnsignedLong();
    for(int i=1;i<=n;i++){
        unsigned long long sum=s[i]?0:-1;
        for(int j=1;j<=n;j++)sum=s[i]?(sum|a[i][j]):(sum&a[i][j]);
        if(sum!=u[i])quitf(_wa,"Wrong Answer");
    }
    for(int i=1;i<=n;i++){
        unsigned long long sum=t[i]?0:-1;
        for(int j=1;j<=n;j++)sum=t[i]?(sum|a[j][i]):(sum&a[j][i]);
        if(sum!=v[i])quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)s[i]=inf.readInt();
    for(int i=1;i<=n;i++)t[i]=inf.readInt();
    for(int i=1;i<=n;i++)u[i]=inf.readUnsignedLong();
    for(int i=1;i<=n;i++)v[i]=inf.readUnsignedLong();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
