class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<100>> reachable(n);

        // Direct edges
        for (auto& pre : prerequisites)
            reachable[pre[0]][pre[1]] = 1;

        // Floyd-Warshall logic
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                if (reachable[i][k])
                    reachable[i] |= reachable[k];

        // Answer queries
        vector<bool> res;
        for (auto& q : queries)
            res.push_back(reachable[q[0]][q[1]]);
        return res;
    }
};
