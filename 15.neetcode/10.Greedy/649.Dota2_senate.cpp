#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>d,r;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='D') d.push(i);
            else r.push(i);
        }
        while(r.size()&&d.size()){
            int rIdx=r.front();
            int dIdx=d.front();
            r.pop(); d.pop();
            if(rIdx<dIdx) r.push(rIdx+n);
            else d.push(dIdx+n);
        }
        return d.empty() ? "Radiant": "Dire";
    }
};