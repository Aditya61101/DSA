class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> reachable(n);
        // Direct edges
        for (auto& pre : prerequisites) reachable[pre[0]][pre[1]] = 1;

        // Floyd-Warshall logic
        for (int k = 0; k < n; ++k){ // k is intermediate node
            for (int i = 0; i < n; ++i){ // i is start node
                for(int j=0;j<n;j++){ // j is end node
                    // i -> j -> k
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }
        // Answer queries
        vector<bool> res;
        for (auto& q : queries) res.push_back(reachable[q[0]][q[1]]);
        return res;
    }
};
