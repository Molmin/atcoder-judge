/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-14
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,m;
string a[100],b[100];

bool solve(InStream& stream){
    for(int i=0;i<n;i++){
        b[i]=stream.readToken();
        if(b[i].size()!=m)quitf(_wa,"Wrong Answer");
    }
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            if(b[i][j]=='T'&&b[i][j-1]=='T')
                quitf(_wa,"Wrong Answer");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(a[i][j]==b[i][j])continue;
            if(a[i][j]=='T'&&b[i][j]=='P'){
                if(j==m-1||a[i][j+1]!='T'||b[i][j+1]!='C')
                    quitf(_wa,"Wrong Answer");
                b[i][j+1]='T';
            }
            else quitf(_wa,"Wrong Answer");
        }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    n=inf.readInt(),m=inf.readInt();
    for(int i=0;i<n;i++)a[i]=inf.readToken();
    int out=solve(ouf);
    if(out)quitf(_ok,"Correct");
    else quitf(_wa,"Wrong Answer");
    return 0;
}
