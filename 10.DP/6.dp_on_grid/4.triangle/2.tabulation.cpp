#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int arr[4][4]={{1,0,0,0},{2,3,0,0},{3,6,7,0},{8,9,6,10}};
    static int dp[4][4];
    int r=4,c=4;
    for (int j=0; j<c; j++){
        dp[r-1][j]=arr[r-1][j];
    }
    for (int i=r-2; i>=0; i--){
        for (int j=i; j>=0; j--){
            int diag=arr[i][j]+dp[i+1][j+1];
            int down=arr[i][j]+dp[i+1][j];
            dp[i][j]=min(diag,down);
        }
    }
    cout<<dp[0][0];
}
//in this case only, during tabulation we went highest to lowest.