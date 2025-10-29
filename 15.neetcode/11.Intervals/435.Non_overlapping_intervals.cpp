#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // sort by endtime
        sort(intervals.begin(),intervals.end(), [](auto &p1, auto &p2){
            return p1[1]<p2[1];
        });
        // find maximum no. of non overlapping intervals
        int endTime=-1e9, cnt=0;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=endTime){
                cnt++;
                endTime=intervals[i][1];
            }
        }
        // min_overlapping_intervals=total_intervals-max_non_overlapping_intervals
        return n-cnt;
    }
};