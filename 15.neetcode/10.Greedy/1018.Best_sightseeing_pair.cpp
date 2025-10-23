#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=INT_MIN,best=values[0]+0;
        // same as Kadane algorithm
        for(int i=1;i<values.size();i++){
            // Update the maximum score by combining the best left score so far
            // with the current right score.
            ans=max(ans,values[i]-i+best);
            // Update the maximum left score up to the current index.
            best=max(best,values[i]+i);
        }
        return ans;
    }
};