#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sorting on the basis of second value so that our check remains consistent
        ranges::sort(pairs, [](auto &p1, auto &p2) {
            return p1[1]<p2[1];
        });
        int len=1,refer=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            // reference pair's second value has to be smaller than current pair's first value
            if(refer<pairs[i][0]) {
                len+=1;
                refer=pairs[i][1];
            }
        }
        return len;
    }
};