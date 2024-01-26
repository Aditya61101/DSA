#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define vll vector<int>
using namespace std;

int main(){
    int r=3,c=3;
    vector<vll>v={{1,1,0},{1,1,1},{1,1,0}};
    vector<vll>dp(r,vll(c,0));
    for (int j=0; j<c; j++)
        dp[0][j]=v[0][j];

    for (int i=0; i<r; i++)
        dp[i][0]=v[i][0];
        
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if (v[i][j]!=0){
                int minVal=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                dp[i][j]=minVal+1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int sum=0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            sum+=dp[i][j];
        }
    }
    cout<<sum;
}