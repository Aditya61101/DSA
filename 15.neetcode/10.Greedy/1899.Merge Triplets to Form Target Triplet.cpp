#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool p0=false,p1=false,p2=false;
        for(auto v:triplets){
            if(v==target) return true;
            if(v[0]>target[0]||v[1]>target[1]||v[2]>target[2]) continue;

            if(v[0]==target[0]) p0=true;
            if(v[1]==target[1]) p1=true;
            if(v[2]==target[2]) p2=true;
            if(p0&&p1&&p2) return true;
        }
        return false;
    }
};