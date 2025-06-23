class Solution {
    bool bfs(int src, vector<char>&nodeColor, vector<vector<int>>& g) {
        queue<int>q;
        q.push(src);
        nodeColor[src]='R';
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto no:g[curr]) {
                if(nodeColor[no]==nodeColor[curr]) return false;
                if(nodeColor[no]=='N') {
                    q.push(no);
                    nodeColor[no] = nodeColor[curr]=='B'?'R':'B';
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        // a graph is bipartite if it's cycle length is even or if we can color all its nodes with alternate color. if at any point we encounter a node with same color as curr node means we can't color the graph alternatively. We start with all nodes color with 'N'.
        vector<char>nodeColor(n,'N');
        for(int i=0;i<n;i++){
            if(nodeColor[i]=='N'){
                if(!bfs(i, nodeColor, graph)) return false;
            }
        }
        return true;
    }
};