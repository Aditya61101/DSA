class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outedge(n);
        vector<vector<int>>fg(n);
        for(int i=0;i<n;i++) {
            vector<int>ng=graph[i];
            outedge[i]=ng.size();
            for(int &e:ng) fg[e].push_back(i);
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(outedge[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            for(auto &e:fg[curr]) {
                outedge[e]--;
                if(outedge[e]==0) {
                    q.push(e);
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++) {
            if(outedge[i]==0) res.push_back(i);
        }
        return res;
    }
};