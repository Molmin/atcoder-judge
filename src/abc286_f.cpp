/*
 * @type: interactor
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

void wa(){
    puts("-1");
    quitf(_wa,"Wrong Answer");
}

int m,a[111];

int main(int argc,char** argv){
    registerInteraction(argc,argv);
    // NOTE: AtCoder provides correct n in the first line of the input file
    int n=inf.readInt();
    cin>>m;
    if(m<1||m>110)wa();
    for(int i=1;i<=m;i++){
        cin>>a[i];
        if(a[i]<1||a[i]>m)wa();
    }
    for(int i=1;i<=m;i++){
        vector<int> x;
        map<int,int> mp;
        int now=i,tot=0;
        x.push_back(now),mp[now]=1;
        while(true){
            if(tot==n){
                cout<<now<<" \n"[i==m];
                break;
            }
            now=a[now];
            if(mp[now]){
                cout<<x[mp[now]-1+(n-mp[now]+1)%(tot-mp[now]+2)]<<" \n"[i==m];
                break;
            }
            x.push_back(now);
            mp[now]=(++tot)+1;
        }
    }
    int output;
    cin>>output;
    if(output==n)quitf(_ok,"Correct");
    else wa();
    return 0;
}
