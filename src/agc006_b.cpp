/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-03-27
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,x,a[200002],b[200002];
bool vis[200002];

bool check(int mid){
    for(int i=1;i<=2*n-1;i++)b[i]=a[i]>=mid;
    for(int i=0;i<n-1;i++){
        if(b[n-i-1]==b[n-i])return b[n-i];
        if(b[n+i+1]==b[n+i])return b[n+i];
    }
    return b[1];
}

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="No")return false;
    else if(res!="Yes")quitf(_wa,"Wrong Answer");
    for(int i=1;i<=2*n-1;i++){
        a[i]=stream.readInt(1,2*n-1);
        if(vis[a[i]])quitf(_wa,"Wrong Answer");
        vis[a[i]]=true;
    }
    int l=1,r=2*n-1;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    if(l!=x)quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),x=inf.readInt();
    int out=solve(ouf),answer=x!=1&&x!=2*n-1;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
