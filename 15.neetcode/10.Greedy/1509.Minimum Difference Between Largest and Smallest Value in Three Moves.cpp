#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        priority_queue<int>small;
        priority_queue<int,vector<int>,greater<int>>lar;
        for(int e:nums) {
            small.push(e);
            lar.push(e);
            if(small.size()>4) small.pop();
            if(lar.size()>4) lar.pop();
        }
        priority_queue<int>helper;
        while(lar.size()){
            helper.push(lar.top());
            lar.pop();
        }
        int ans=INT_MAX;
        while(small.size()){
            int val=helper.top()-small.top();
            small.pop();
            helper.pop();
            ans=min(ans,val);
        }
        return ans;
    }
};