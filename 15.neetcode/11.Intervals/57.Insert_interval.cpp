
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0,n=intervals.size();
        // inserting intervals occurring before newInterval i.e., intervals whose end time is less than new interval's start time
        while(i<n&&intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i++]);
        }
        // merging overlapping intevals new_interval, intervals[i...]
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // inserting remaining intervals
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};