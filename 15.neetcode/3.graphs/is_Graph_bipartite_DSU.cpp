class Solution {
    vector<int> parent;

    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) parent[px] = py;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                // If i and neighbor belong to same group, it's not bipartite
                if (find(i) == find(neighbor)) return false;
                // Unite the first neighbor of i with current neighbor
                if (!graph[i].empty())
                    unite(graph[i][0], neighbor);
            }
        }
        return true;
    }
};