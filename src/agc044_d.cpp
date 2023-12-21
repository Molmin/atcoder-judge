/*
 * @type: interactor
 * @author: Milmon <milmon@qq.com>
 * @date: 2023-12-21
 */

#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int L=128,Q=850;

int dp[L+1][L+1];

int calc(string s,string t){
    int len1=s.size(),len2=t.size();
    for(int i=0;i<=len1;i++)dp[i][0]=i;
    for(int i=0;i<=len2;i++)dp[0][i]=i;
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
        }
    return dp[len1][len2];
}

int main(int argc,char** argv){
    registerInteraction(argc,argv);
    string answer=inf.readToken();
    int total=0;
    while(true){
        char op; string s;
        cin>>op>>s;
        if(s.size()>L)quitf(_wa,"Wrong Answer");
        if(op=='?'){
            total++;
            if(total>Q)quitf(_wa,"Wrong Answer");
            cout<<calc(s,answer)<<endl;
        }
        else{
            if(s==answer)quitf(_ok,"Correct (%d queries)",total);
            else quitf(_wa,"Wrong Answer");
            break;
        }
    }
    return 0;
}
