#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v={1,3,5,4};
    int lenI=v.size();
    int stickL=7;
    v.push_back(stickL);
    v.insert(v.begin(),0);
    sort(v.begin(),v.end());
    vector<vector<int>>dp(lenI+2,vector<int>(lenI+2,0));
    for (int i=lenI; i>=1; i--){
        for (int j=1; j<=lenI; j++){
            if (i>j){
                continue;
            }
            int minVal=1e9;
            for (int k=i; k<=j; k++){
                int cost=v[j+1]-v[i-1]+dp[i][k-1]+dp[k+1][j];
                minVal=min(minVal,cost);
            }
            dp[i][j]=minVal;
        }
    }
    cout<<dp[1][lenI];
}
//the cut array is sorted in order to segregate the sticks and solve them independently.
//to insert at any position we use insert function.