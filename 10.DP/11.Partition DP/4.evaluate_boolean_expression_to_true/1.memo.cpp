#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
#define lli long long int

lli solve(string &s,int i,int j,int isTrue,vector<vector<vector<lli>>>&dp){
    if (i==j){
        if (isTrue==1){
            return s[i]=='T';
        }
        return s[i]=='F';
    }
    if (dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    lli count=0;
    for (int k=i+1; k<j; k+=2){
        lli lt=solve(s,i,k-1,1,dp);
        lli lf=solve(s,i,k-1,0,dp);
        lli rt=solve(s,k+1,j,1,dp);
        lli rf=solve(s,k+1,j,0,dp);
        if (s[k]=='&'){
            if (isTrue){
              count=(count+(lt*rt)%mod)%mod;  
            }
            else{
              count=(count+(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
            }
        }
        else if (s[k]=='|'){
           if (isTrue){
              lli case1=(lt*rt)%mod;  
              lli case2=(lt*rf)%mod;  
              lli case3=(lf*rt)%mod;
              count=(count+case1+case2+case3)%mod;
           }
           else{
              count=(count+(lf*rf)%mod)%mod;
           }
        }
        else if(s[k]=='^'){
           if (isTrue){
              lli case1=(lt*rf)%mod;
              lli case2=(lf*rt)%mod;
              count=(count+case1+case2)%mod;
           }
           else{
              count=(count+(lt*rt)%mod+(lf*rf)%mod)%mod;
           }
        }
    }
    return dp[i][j][isTrue]=count%mod; 
}
int main(){
    string exp="T^F|T&F^T|F";
    int n=exp.length();
    vector<vector<vector<lli>>>dp(n,vector<vector<lli>>(n,vector<lli>(2,-1)));
    int result=solve(exp,0,n-1,1,dp);
    cout<<result;
}
//T:True,F:False,|:or,&:and,^:xor
//isTrue is looking for have expression as true.