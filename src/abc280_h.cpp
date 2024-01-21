/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-19
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int mod1=998244353,mod2=998244383;
const int mul1=131,mul2=13331;
int power1[100001],power2[100001];

int n,q;
string s[100001];

struct HashNode{
    int val1,val2,len;

    inline HashNode operator+(char ch)const{
        return{
            int((1ll*val1*mul1+ch)%mod1),
            int((1ll*val2*mul2+ch)%mod2),
            len+1
        };
    }

    inline HashNode operator-(HashNode x)const{
        return{
            (int(1ll*x.val1*power1[len-x.len]%mod1-val1)%mod1+mod1)%mod1,
            (int(1ll*x.val2*power2[len-x.len]%mod2-val2)%mod2+mod2)%mod2,
            len-x.len
        };
    }

    inline bool operator==(HashNode tmp)const{
        return val1==tmp.val1&&val2==tmp.val2&&len==tmp.len;
    }
};
vector<HashNode> h[100001];

HashNode solve(InStream &stream){
    int id,l,r;
    id=stream.readInt(1,n);
    l=stream.readInt(1,s[id].size());
    r=stream.readInt(l,s[id].size());
    return h[id][r]-h[id][l-1];
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt();
    for(int i=1;i<=n;i++)s[i]=inf.readToken();
    q=inf.readInt();
    for(int i=1;i<=n;i++){
        h[i].push_back({0,0});
        for(int j=0;j<s[i].size();j++)
            h[i].push_back(h[i][j]+s[i][j]);
    }
    power1[0]=power2[0]=1;
    for(int i=1;i<=100000;i++){
        power1[i]=1ll*power1[i-1]*mul1%mod1;
        power2[i]=1ll*power2[i-1]*mul2%mod2;
    }
    while(q--){
        HashNode out=solve(ouf),answer=solve(ans);
        if(out==answer)continue;
        else quitf(_wa,"Wrong Answer");
    }
    quitf(_ok,"Correct");
    return 0;
}
