/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-29
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m,a[100001],b[100001],l[200001],r[200001];
struct Node{
    int pos,id;
    bool operator<(Node tmp)const{
        if(pos==tmp.pos)return id<tmp.id;
        else return pos<tmp.pos;
    }
};

bool solve(InStream& stream){
    int k=stream.readInt(-1,m);
    if(k==-1)return false;
    int lastId=0;
    vector<Node> nodes;
    for(int i=1;i<=k;i++){
        int id=stream.readInt(lastId+1,m); lastId=id;
        nodes.push_back({l[id],0});
        nodes.push_back({r[id]+1,0});
    }
    for(int i=1;i<=n;i++)
        nodes.push_back({a[i],i});
    sort(nodes.begin(),nodes.end());
    int now=0;
    for(Node node :nodes){
        if(node.id==0)now=now^1;
        else if(b[node.id]^now!=0)quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=1;i<=n;i++)
        a[i]=inf.readInt(),b[i]=inf.readInt();
    for(int i=1;i<=m;i++)
        l[i]=inf.readInt(),r[i]=inf.readInt();
    int out=solve(ouf),answer=ans.readInt()!=-1;
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
