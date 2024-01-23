/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-20
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

map<pair<int,int>,bool> mp;
int sx,sy,tx,ty;

bool check(string s){
    int nowx=sx,nowy=sy;
    vector<bool> vec;
    for(char ch :s){
        if(ch=='U')nowy++;
        else if(ch=='R')nowx++;
        else if(ch=='D')nowy--;
        else if(ch=='L')nowx--;
        if(nowx==sx&&nowy==sy){
            vec.push_back(true);
            continue;
        }
        if(nowx==tx&&nowy==ty){
            vec.push_back(false);
            continue;
        }
        if(mp[{nowx,nowy}])return false;
        else mp[{nowx,nowy}]=true;
    }
    if(vec.size()!=4)return false;
    if(vec[0]!=false)return false;
    if(vec[1]!=true)return false;
    if(vec[2]!=false)return false;
    if(vec[3]!=true)return false;
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    sx=inf.readInt(),sy=inf.readInt();
    tx=inf.readInt(),ty=inf.readInt();
    int bestStep=ans.readToken().size();
    string sol=ouf.readToken();
    if(sol.size()>bestStep)quitf(_wa,"Wrong Answer");
    else if(!check(sol))quitf(_wa,"Wrong Answer");
    else if(sol.size()==bestStep)quitf(_ok,"Correct");
    else quitf(_fail,"Failed");
    return 0;
}
