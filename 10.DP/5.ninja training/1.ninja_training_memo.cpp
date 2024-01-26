#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define vll vector<int>
using namespace std;

// in this question, We need to know the activity performed on previous day, so we store it in a variable named last.
int solve(int day,int last,vector<vll>&p,vector<vll>&dp){
    //This checks if it's the first day (day == 0). If it is, it calculates the maximum points that can be earned on this day by selecting an activity different from the last one i.e, greedy can be applied in this case.
    if(day==0){
        int val = INT_MIN;
        for(int j=0;j<3;j++){
            if(j!=last)
                val=max(val,p[0][j]);
        }
        return dp[day][last]=val;
    }
    if(dp[day][last]!=-1)
        return dp[day][last];
        
    int sum = INT_MIN;
    for(int j=0;j<3;j++){
        if(j!=last){
            int points = p[day][j]+solve(day-1,j,p,dp);
            sum = max(points,sum);
        }
    }
    return dp[day][last]=sum;
}
int main(){
    int n=4;
    vector<vll>arr{{2,1,3},{3,4,6},{10,1,16},{8,3,7}};
    vector<vll>dp(n+1,vll(4,-1));
    cout<<solve(n-1,3,arr,dp);
}