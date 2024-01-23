/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-23
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,val[100001];

struct Graph{
    int root;
    vector<int> E[100001];
    long long sum[100001];

    inline void read(){
        for(int i=1;i<=n;i++){
            int fa=inf.readInt();
            if(fa==-1)root=i;
            else E[fa].push_back(i);
        }
    }

    void check(int id,int father){
        sum[id]=val[id];
        for(int v :E[id]){
            if(v==father)continue;
            check(v,id);
            sum[id]+=sum[v];
        }
        if(abs(sum[id])!=1)quitf(_wa,"Wrong Answer");
    }

    void check(){
        check(root,0);
    }
}G1,G2;

bool solve(InStream& stream){
    string res=stream.readToken();
    if(res=="IMPOSSIBLE")return false;
    else if(res!="POSSIBLE")quitf(_wa,"Wrong Answer");
    for(int i=1;i<=n;i++)val[i]=stream.readInt();
    G1.check(); G2.check();
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    G1.read(),G2.read();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
