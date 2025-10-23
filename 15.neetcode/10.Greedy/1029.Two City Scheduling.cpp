#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        // sorting people by how much cheaper City A is for them compared to City B.
        sort(costs.begin(),costs.end(),[](auto &p1, auto &p2) {
            return (p1[0]-p1[1])<(p2[0]-p2[1]);
        });
        int cost=0;
        // Send the most A-favored n/2 people to A, and the most B-favored n/2 people to B.
        for(int i=0;i<n;i++){
            if(i<n/2) cost+=costs[i][0];
            else cost+=costs[i][1];
        }
        return cost;
    }
};