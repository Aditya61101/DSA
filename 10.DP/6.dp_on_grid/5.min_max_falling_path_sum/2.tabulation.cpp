#include<iostream>
#include<climits>
using namespace std;

int main(){
    int r=4,c=4;
    int arr[4][4]={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    static int dp[4][4];
    for (int j=0; j<c; j++){
        dp[0][j]=arr[0][j];
    }
    for (int i=1; i<r; i++){
        for (int j=0; j<c; j++){
            int up=dp[i-1][j]+arr[i][j];
            int diagLeft=arr[i][j];
            int diagRight=arr[i][j];
            if (j<=0){
                diagLeft=-1e8;   
            }
            else{
                diagLeft+=dp[i-1][j-1];
            }
            if (j>=c-1){
                diagRight=-1e8;
            }
            else{
                diagRight+=dp[i-1][j+1];
            }
            dp[i][j]= max(up,max(diagLeft,diagRight));
        }
    }
    int maxVal=-1e8;
    for (int j=0; j<c; j++){
        maxVal=max(maxVal,dp[r-1][j]);
    }
    cout<<maxVal;
}