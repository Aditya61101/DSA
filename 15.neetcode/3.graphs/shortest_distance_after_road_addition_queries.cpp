// dijkstra using normal queue
class Solution {
    void bfs(vector<vector<int>>&a, int src, vector<int>&dist) {
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto ne:a[curr]){
                if(dist[curr]+1<dist[ne]){
                    dist[ne]=dist[curr]+1;
                    q.push(ne);
                }
            }
        }
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        vector<int>dist(n,0);// stores distance of every node from 0.
        for(int i=1;i<n;i++){
            dist[i]=i;
            adj[i-1].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0], v=queries[i][1];
            adj[u].push_back(v);
            if(dist[u]+1<dist[v]){
                dist[v]=dist[u]+1;
                bfs(adj,v,dist);
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};