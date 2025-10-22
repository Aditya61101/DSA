#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mp;
        for(int i=0;i<x.size();i++){
            mp[x[i]]=max(mp[x[i]],y[i]);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it:mp){
            pq.push(it.second);
            if(pq.size()>3) pq.pop();
        }
        if(pq.size()<3) return -1;
        int sum=0;
        while(pq.size()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};