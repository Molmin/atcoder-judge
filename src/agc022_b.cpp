/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-09-12
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[20001];
bool vis[30001];

bool solve(InStream& stream){
    int globalgcd,sum=0;
    for(int i=1;i<=n;i++){
        a[i]=stream.readInt(1,30000);
        if(vis[a[i]])return false;
        globalgcd=i==1?a[i]:__gcd(a[i],globalgcd);
        sum+=a[i];
    }
    if(globalgcd!=1)return false;
    for(int i=1;i<=n;i++)
        if(__gcd(sum-a[i],a[i])==1)return false;
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
