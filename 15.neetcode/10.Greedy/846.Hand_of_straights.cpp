#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if((n%groupSize)!=0) return false;
        
        map<int,int>mp;
        for(int h:hand) mp[h]++;

        while(mp.size()){
            int h=mp.begin()->first;
            for(int i=1;i<groupSize;i++){
                if(!mp.count(h+i)) return false;
                mp[h+i]--;
                if(mp[h+i]==0) mp.erase(h+i);
            }
            mp[h]--;
            if(mp[h]==0) mp.erase(h);
        }
        return true;
    }
};