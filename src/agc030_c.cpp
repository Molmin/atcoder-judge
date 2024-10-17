/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-10-17
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int k,n,a[500][500];
bool vis[1001];
vector<int> v[500][500];
vector<int> vec[1001];

bool solve(InStream& stream){
    n=stream.readInt(1,500);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            a[i][j]=stream.readInt(1,k);
            vis[a[i][j]]=true;
        }
    for(int i=1;i<=k;i++)
        if(!vis[i])quitf(_wa,"Wrong Answer");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            vector<int> vec;
            vec.push_back(a[(i+1)%n][j]);
            vec.push_back(a[(i-1+n)%n][j]);
            vec.push_back(a[i][(j+1)%n]);
            vec.push_back(a[i][(j-1+n)%n]);
            sort(vec.begin(),vec.end());
            v[i][j]=vec;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(vec[a[i][j]].empty())vec[a[i][j]]=v[i][j];
            else if(vec[a[i][j]]!=v[i][j])quitf(_wa,"Wrong Answer");
        }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    k=inf.readInt(1,1000);
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
