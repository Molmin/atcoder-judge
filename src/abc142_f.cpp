/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,u[2001],v[2001];
int deg_in[1001],deg_out[1001];
bool flag[1001];

bool check(InStream& stream){
    int k=ouf.readInt(-1,n);
    if(k==-1)return false;
    if(k==0)quitf(_wa,"Wrong Answer");
    for(int i=1;i<=k;i++){
        int v=ouf.readInt(1,n);
        if(flag[v])quitf(_wa,"Wrong Answer");
        flag[v]=true;
    }
    for(int i=1;i<=m;i++)
        if(flag[u[i]]&&flag[v[i]])
            deg_out[u[i]]++,deg_in[v[i]]++;
    for(int i=1;i<=n;i++)
        if(flag[i]&&(deg_in[i]!=1||deg_out[i]!=1))
            quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++)
        u[i]=inf.readInt(),v[i]=inf.readInt();
    int out=check(ouf),answer=ans.readInt()!=-1;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
