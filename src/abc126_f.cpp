/**
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

int m,k;
int a[1<<18],tot[1<<17];
int posl[1<<17],posr[1<<17];

bool solve(InStream& stream){
    int first=stream.readInt(-1,(1<<m)-1);
    if(first==-1)return false;
    memset(tot,0,sizeof tot);
    memset(posl,0,sizeof posl);
    memset(posr,0,sizeof posr);
    a[0]=first,tot[a[0]]++,posl[a[0]]=0;
    for(int i=1;i<(1<<m+1);i++){
        a[i]=stream.readInt(0,(1<<m)-1),
        tot[a[i]]++;
        if(tot[a[i]]==1)posl[a[i]]=i;
        else posr[a[i]]=i;
        a[i]^=a[i-1];
    }
    for(int i=0;i<(1<<m);i++){
        if(tot[i]!=2)quitf(_wa,"Wrong Answer");
        if((a[posr[i]-1]^a[posl[i]])!=k)quitf(_wa,"Wrong Answer");
    }
    return true;
}

int main(int argc,char** argv){
    registerTestlibCmd(argc,argv);
    m=inf.readInt(),k=inf.readInt();
    int out=solve(ouf),answer=(k<pow(2,m)&&(m!=1||k==0));
    if(out==answer)quitf(_ok,"Correct");
    else if(answer)quitf(_wa,"Wrong Answer");
    else quitf(_fail,"Failed");
    return 0;
}
