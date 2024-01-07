/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int a[3][3],b[3][3];

bool solve(InStream& stream){
    string answer=stream.readToken();
    if(answer=="NO")return false;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)a[i][j]=b[i][j];
    if(answer.size()>1000)quitf(_wa,"Wrong Answer");
    int x=0,y=0;
    for(int i=0;i<answer.size();i++){
        if(a[x][y]==0)quitf(_wa,"Wrong Answer");
        a[x][y]--;
        if(answer[i]=='U')x--;
        else if(answer[i]=='D')x++;
        else if(answer[i]=='L')y--;
        else if(answer[i]=='R')y++;
        else quitf(_wa,"Wrong Answer");
        if(x<0||y<0||x>=3||y>=3)quitf(_wa,"Wrong Answer");
    }
    if(x!=0||y!=0)quitf(_wa,"Wrong Answer");
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)
        if(a[i][j])quitf(_wa,"Wrong Answer");
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[i][j]=inf.readInt();
    int out=solve(ouf),answer=solve(ans);
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
