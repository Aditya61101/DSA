class Solution {
private:
    void dfs(int curr, int d, vector<int>&dist, vector<int>& edges) {
        dist[curr]=d;
        // no outgoing edge or if visiting node distance is not INF i.e., it's already been visited so to prevent cycle we return
        if(edges[curr]==-1 || dist[edges[curr]]!=INT_MAX) return;
        dfs(edges[curr], d+1, dist, edges);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>d1(n, INT_MAX), d2(n, INT_MAX);
        d1[node1]=0; d2[node2]=0;
        dfs(node1, 0, d1, edges);
        dfs(node2, 0, d2, edges);
        int node=-1, minVal=INT_MAX;
        for(int i=0;i<n;i++) {
            if(d1[i]==INT_MAX || d2[i]==INT_MAX) continue;
            int val = max(d1[i], d2[i]);
            if(val<minVal) {
                minVal=val; node=i;
            }
        }
        return node;
    }
};