class Solution {
    bool bfs(int src, vector<bool>&v, vector<vector<int>>&a) {
        queue<int>q;
        q.push(src);
        v[src]=true;
        int nodes=1, edges=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            edges+=a[curr].size();
            for(auto no:a[curr]){
                if(!v[no]){
                    q.push(no);
                    v[no]=true;
                    nodes++;
                }
            }
        }
        edges/=2;
        int requiredEdges = nodes*(nodes-1)/2;
        return requiredEdges==edges;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        int ans=0;
        vector<vector<int>>adjL(n);
        for(auto &e:edges){
            adjL[e[0]].push_back(e[1]);
            adjL[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,vis, adjL)) ans+=1;
            }
        }
        return ans;
    }
};