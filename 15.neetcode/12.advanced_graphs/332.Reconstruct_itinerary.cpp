#include<bits/stdc++.h>
using namespace std;

// uses Eulerian path concept: Hierholzer’s algorithm
class Solution {
    unordered_map<string,vector<string>>adj;
    vector<string>path;
    unordered_map<string,int>outDegree;
    void dfs(string &start){
        while(outDegree[start]!=0){
            outDegree[start]-=1;
            dfs(adj[start][outDegree[start]]);
        }
        path.push_back(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t:tickets){
            adj[t[0]].push_back(t[1]);
            outDegree[t[0]]+=1;
        }
        // need to sort, in order to have the smallest string at the last so that we can access it at the earliest
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end(),greater<string>());
        }
        string start="JFK";
        dfs(start);
        reverse(path.begin(),path.end());
        return path;
    }
};