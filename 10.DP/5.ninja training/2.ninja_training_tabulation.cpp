#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n=4;
    int arr[n][3]={{2,1,3},{3,4,6},{10,1,16},{8,3,7}};
    int dp[n][4];
    dp[0][0]=max(dp[0][1],dp[0][2]);
    dp[0][1]=max(dp[0][0],dp[0][2]);
    dp[0][2]=max(dp[0][1],dp[0][0]);
    dp[0][3]=max(dp[0][1],max(dp[0][0],dp[0][2]));
    for (int day=1; day<n; day++){
        for (int last=0; last<4; last++){
            dp[day][last]=0;
            for (int task=0; task<3; task++){
                if (last!=task){
                    int points=arr[day][task]+dp[day-1][task];
                    dp[day][last]=max(points,dp[day][last]);
                }
            }
        }
    }
    cout<<dp[n-1][3];
}