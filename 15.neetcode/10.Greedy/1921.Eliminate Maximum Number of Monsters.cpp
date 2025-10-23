#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>time(n);
        for(int i=0;i<n;i++){
            time[i]=ceil(dist[i]/(float)speed[i]);
        }
        sort(time.begin(),time.end());
        for(int t=0;t<n;t++){
            if(time[t]<=t) return t;
        }
        return n;
    }
};