#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v={10,9,2,5,3,7,18,101};
    int n=v.size();
    vector<int>next(n+1,0),curr(n+1,0);
    for (int i=n-1; i>=0; i--){
        for (int prevI=i-1; prevI>=-1; prevI--){
            int take=0;
            if (prevI==-1||v[i]>v[prevI]){
                take=1+next[i+1];
            }
            int notTake=next[prevI+1];
            curr[prevI+1]=max(take,notTake);
        }
        next=curr;
    }
    cout<<curr[0];
}
//dp[i+1][y] replace it with next[y]
//dp[i][y] replace it with curr[y]