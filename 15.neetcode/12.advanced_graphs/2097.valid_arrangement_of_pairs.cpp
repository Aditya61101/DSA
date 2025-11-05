#include<bits/stdc++.h>
using namespace std;

class Solution{
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>outDegree;
    unordered_map<int,int>inDegree;
    vector<int>path;
    void dfs(int start){
        while(outDegree[start]!=0){
            outDegree[start]-=1;
            dfs(adj[start][outDegree[start]]);
        }
        path.push_back(start);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto p:pairs){
            adj[p[0]].push_back(p[1]);
            outDegree[p[0]]+=1;
            inDegree[p[1]]+=1;
        }
        // find the starting point
        int start=-1;
        for(auto it:inDegree){
            // we only have Eulerian path
            if(outDegree[it.first]-it.second==1) {
                start=it.first; break;
            }
            // since there always be a valid arrangement, the difference of outd-ind will either be 0 or 1. if difference is 1, then there's no euler circuit but an euler path.
            start=it.first;
        }
        dfs(start);
        reverse(path.begin(),path.end());
        vector<vector<int>>validArrangementList;
        for(int i=0;i<path.size()-1;i++){
            validArrangementList.push_back({path[i],path[i+1]});
        }
        return validArrangementList;
    }
};