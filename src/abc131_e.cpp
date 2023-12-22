/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-22
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,k;
bool flag[101][101];

int fa[101];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
int u[10001],v[10001];

bool solve(InStream& stream){
    memset(flag,false,sizeof flag);
    int m=stream.readInt(-1,n*(n-1)/2);
    if(m==-1)return false;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        u[i]=stream.readInt(1,n),v[i]=stream.readInt(1,n);
        if(find(u[i])!=find(v[i]))
            fa[find(u[i])]=find(v[i]);
    }
    for(int i=1;i<n;i++)
        if(find(i)!=find(n))
            quitf(_wa,"Wrong Answer");
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++){
            if(u[i]==v[j]&&u[j]==v[i])
                quitf(_wa,"Wrong Answer");
            if(u[i]==u[j]&&v[i]==v[j])
                quitf(_wa,"Wrong Answer");
            if(u[i]==u[j])flag[v[i]][v[j]]=flag[v[j]][v[i]]=true;
            if(v[i]==v[j])flag[u[i]][u[j]]=flag[u[j]][u[i]]=true;
            if(u[i]==v[j])flag[v[i]][u[j]]=flag[u[j]][v[i]]=true;
            if(v[i]==u[j])flag[u[i]][v[j]]=flag[v[j]][u[i]]=true;
        }
    for(int i=1;i<=m;i++)
        flag[u[i]][v[i]]=flag[v[i]][u[i]]=false;
    int total=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(flag[i][j])total++;
    if(total!=k)quitf(_wa,"Wrong Answer");
    else return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),k=inf.readInt();
    int out=solve(ouf),answer=(n-1)*(n-2)/2>=k;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
