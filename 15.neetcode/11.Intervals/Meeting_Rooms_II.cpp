#include<bits/stdc++.h>
using namespace std;
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<int>startTimes,endTimes;
        for(auto &v:intervals){
            startTimes.push_back(v.start);
            endTimes.push_back(v.end);
        }
        sort(startTimes.begin(),startTimes.end());
        sort(endTimes.begin(),endTimes.end());

        int rooms=0,endPtr=0;
        for(int i=0;i<n;i++){
            if(startTimes[i]<endTimes[endPtr]) rooms++;
            else endPtr++;
        }
        return rooms;
    }
};