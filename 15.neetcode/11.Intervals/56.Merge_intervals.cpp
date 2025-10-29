#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int currentStart=intervals[0][0], currentEnd=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            // since current interval's starttime is not greater than current end, we need to merge
            if(intervals[i][0]<=currentEnd) currentEnd=max(currentEnd,intervals[i][1]);
            else {
                ans.push_back({currentStart,currentEnd});
                currentStart=intervals[i][0]; currentEnd=intervals[i][1];
            }
        }
        ans.push_back({currentStart,currentEnd});
        return ans;
    }
};