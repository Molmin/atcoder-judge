/**
 * @type: interactor
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
vector<int> E[101];

int main(int argc,char** argv){
    registerInteraction(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=m;i++){
        int u=inf.readInt();
        int v=inf.readInt();
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        sort(E[i].begin(),E[i].end());
    cout<<n<<' '<<m<<endl;
    int now=1,total=0;
    while(true){
        if(total>2*n){
            puts("-1");
            quitf(_wa,"Wrong Answer");
        }
        if(now==n){
            puts("OK");
            quitf(_ok,"Correct");
        }
        cout<<E[now].size();
        for(int x :E[now])cout<<' '<<x;
        cout<<endl;
        int to; cin>>to;
        bool flag=false;
        for(int x :E[now])if(x==to)flag=true;
        if(!flag){
            puts("-1");
            quitf(_wa,"Wrong Answer");
        }
        now=to,total++;
    }
    return 0;
}
