#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>mp;
        for(auto v:roads){
            mp[v[0]]++;
            mp[v[1]]++;
        }
        vector<long long>freq; // of size n
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        long long sum=0;
        for(auto f:freq){
            sum+=f*(long long)n;
            n-=1;
        }
        return sum;
    }
};