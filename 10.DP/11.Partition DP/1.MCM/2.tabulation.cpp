//given the N matrices dimensions, find the min operations to multiply them to a single matrix.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v={10,20,30,40,50};
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i=0; i<n; i++){ 
        dp[i][i]=0;
    }
    for (int i=n-1; i>0; i--){
        for (int j=i+1; j<n; j++){
            int minVal=1e9;
            for (int k=i; k<j; k++){
                int steps=v[i-1]*v[k]*v[j]+dp[i][k]+dp[k+1][j];
                minVal=min(minVal,steps);
            }
            dp[i][j]=minVal;
        }
    }
    cout<<dp[1][n-1];
}
//vector v contains v.size()-1 matrices dimensions.
//1st matrix: v[0]xv[1]
//2nd matrix: v[1]xv[2]
//3rd matrix: v[2]xv[3]
//4th matrix: v[3]xv[4]
//ith matrix: v[i-1]xv[i]
//when i=j, we will have only one matrix to perform an operation which means no operation or return 0.
//here k is the partition variable.
//j should start from i+1 as j will always be to the right of i.