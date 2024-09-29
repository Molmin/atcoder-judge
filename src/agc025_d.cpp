/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-09-27
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,d1,d2;
bool vis[600][600];

bool solve(InStream& stream){
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i*i+j*j!=d1&&i*i+j*j!=d2)continue;
            vec.emplace_back(i,j);
            vec.emplace_back(i,-j);
            vec.emplace_back(-i,j);
            vec.emplace_back(-i,-j);
        }
    for(int i=0;i<n*n;i++){
        int x=stream.readInt(0,2*n-1);
        int y=stream.readInt(0,2*n-1);
        if(vis[x][y])return false;
        vis[x][y]=true;
        for(pair<int,int> i :vec)
            if(x+i.first>=0&&x+i.first<2*n&&y+i.second>=0&&y+i.second<2*n&&vis[x+i.first][y+i.second])
                return false;
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(1,300);
    d1=inf.readInt(1,2e5);
    d2=inf.readInt(1,2e5);
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
