#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>indices;
        vector<int>lastOccurs(26);
        for(int i=0;i<s.length();i++) lastOccurs[s[i]-'a']=i;
        
        int curr_idx=0,prev_end=-1;
        for(int i=0;i<s.length();i++){
            int curr_last_occur=lastOccurs[s[i]-'a'];
            curr_idx=max(curr_idx,curr_last_occur);
            if(i==curr_idx) {
                indices.push_back(i-prev_end);
                prev_end=i;
            }
        }
        return indices;
    }
};