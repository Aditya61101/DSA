#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using t=tuple<int,int,int>;
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        priority_queue<t,vector<t>,greater<t>>pq;
        // price[u][s]: price to reach u with 's' stops
        vector<vector<int>>price(n,vector<int>(k+2,1e9));
        price[src][0]=0;
        pq.push({0,src,0});
        while(pq.size()){
            auto [p,u,stops]=pq.top();
            pq.pop();
            if(u==dst) return price[u][stops];
            // we use all stops but still didn't reach our destination, means not a right path
            if(stops==k+1) continue;
            for(auto [v,wt]:adj[u]){
                if(price[v][stops+1]>p+wt){
                    price[v][stops+1]=p+wt;
                    pq.push({price[v][stops+1],v,stops+1});
                }
            }
        }
        return -1;
    }
};