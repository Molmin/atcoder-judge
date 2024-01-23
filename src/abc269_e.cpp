/**
 * @type: interactor
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-19
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

bool vis[1001];
int n,sum[1001][1001];

int main(int argc,char** argv){
    registerInteraction(argc,argv);
    // NOTE: AtCoder provides the position of chess pieces
    //       in every line in the input file
    n=inf.readInt();
    int ansx,ansy,total=0;
    for(int i=1;i<=n;i++){
        int pos=inf.readInt();
        if(pos==-1){
            ansx=i;
            continue;
        }
        vis[pos]=true;
        sum[i][pos]=true;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])ansy=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]+=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1];
    cout<<n<<endl;
    while(true){
        char op;
        cin>>op;
        if(op=='?'){
            if(total>=20)quitf(_wa,"Wrong Answer");
            total++;
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a<1||a>n||b<1||b>n||a>b)
                quitf(_wa,"Wrong Answer");
            if(c<1||c>n||d<1||d>n||c>d)
                quitf(_wa,"Wrong Answer");
            int ret=sum[b][d]-sum[b][c-1]+sum[a-1][c-1]-sum[a-1][d];
            cout<<ret<<endl;
        }
        else if(op=='!'){
            int x,y;
            cin>>x>>y;
            if(x!=ansx||y!=ansy)quitf(_wa,"Wrong Answer");
            else quitf(_ok,"Correct");
        }
        else quitf(_wa,"Wrong Answer");
    }
    return 0;
}
