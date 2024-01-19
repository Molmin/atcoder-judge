/*
 * @type: interactor
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-19
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int n,a[2002];
bool vis[2002];

int main(int argc,char** argv){
    registerInteraction(argc,argv);
    // NOTE: Interactor will prioritize the numbers in the input file with the highest order
    n=inf.readInt();
    for(int i=1;i<=2*n+1;i++)
        a[i]=inf.readInt();
    int tar=1;
    cout<<n<<endl;
    for(int i=1;i<=n+1;i++){
        int x; cin>>x;
        if(x<1||x>2*n+1||vis[x])quitf(_wa,"Wrong Answer");
        vis[x]=true;
        if(i==n+1){
            cout<<0<<endl;
            break;
        }
        while(vis[a[tar]])tar++;
        cout<<a[tar]<<endl;
        vis[a[tar]]=true,tar++;
    }
    quitf(_ok,"Correct");
    return 0;
}
