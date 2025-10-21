#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currCost=0,totalCost=0, s=0;
        for(int i=0;i<gas.size();i++){
            int net=gas[i]-cost[i];
            currCost+=net;
            totalCost+=net;
            if(currCost<0) {
                s=i+1;
                currCost=0;
            }
        }
        return totalCost>=0 ? s:-1;
    }
};