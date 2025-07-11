# Graphs – Key Concepts & Code Snippets

## 🔁 1. Reverse Thinking in Graph Problems
Sometimes, it's easier to **reverse the problem** to get the desired result.

**Examples:**
- `LC 417` (Pacific Atlantic Water Flow): Instead of checking if each cell can reach both oceans, reverse it—see which cells can be reached **from** each ocean.
- `LC 130` (Surrounded Regions): Instead of finding surrounded 'O's, mark the 'O's connected to the border and preserve them.

---

## 🔁 2. Treating Directed Graph as Undirected
In certain problems, treating a **directed graph** as **undirected** can simplify traversal or help reach the goal.

**Example:**
- `LC 1466` (Reorder Routes to Make All Paths Lead to the City Zero): Although the graph is directed, we perform DFS/BFS in both directions to explore all connections.

---

## 🔁 3. Bidirectional BFS
Use **Bidirectional BFS** when:
- Start and target nodes are known.
- Looking for shortest path / minimum moves.
- The search space is **huge and symmetrical**.

**Benefits:**
- It explores from both ends simultaneously, often reducing time complexity from `O(n)` to `O(n/2)`.

---

## 🔁 4. Why BFS Finds the Shortest Path (in Unweighted Graphs)
- BFS explores all nodes at distance = `0`, then `1`, then `2`, and so on.
- The **first** time a node is reached is guaranteed to be the **shortest** path to that node.
- Later discoveries of the same node will be longer or equal in distance.

👉 Use **BFS** for unweighted graphs when looking for:
- Minimum moves
- Minimum steps
- Shortest path

---

## 🔁 5. Default to BFS for Minimum Steps
If the problem says:

> "Return the minimum number of steps/moves to reach the goal"

Then:
- Use **BFS** by default.
- If the graph has **weighted edges**, use **Dijkstra’s Algorithm** instead.

---

## 📚 Topological Sort using Kahn's Algorithm (BFS)
- Only applicable for DAGs.
```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);       // adjacency list
    vector<int> inDegree(n, 0);       // in-degree array

    // Build graph and compute in-degrees
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    // Push all nodes with in-degree 0
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        topo.push_back(curr);

        for (int neighbor : adj[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If all nodes are not in topo order, there's a cycle
    if (topo.size() != n) return {}; // graph has a cycle
    return topo;
}
```

## 📚 Floyd-Warshall Algorithm

The **Floyd-Warshall Algorithm** is a classic dynamic programming technique to:

- Compute the **shortest paths** between all pairs of vertices in a **weighted graph** (can handle **negative weights**, but not negative cycles).
- Or compute **transitive closure** in a **boolean graph** (i.e., check if there's a path between every pair of nodes).

### 🔧 Time & Space Complexity

- **Time Complexity:** `O(V³)` — where `V` is the number of vertices.
- **Space Complexity:** `O(V²)` — for the distance or reachability matrix.

### ✅ Use Cases

- Finding **shortest distances** between all pairs of nodes.
- Determining **reachability (transitive closure)** in a DAG or unweighted graph.
- Detecting **negative cycles** when `dist[i][i] < 0` after execution.

---

### 🧮 C++ Implementation (Transitive Closure)
```cpp
vector<vector<bool>> floydWarshall(int n, vector<vector<int>>& edges) {
    // Initialize reachability matrix
    vector<vector<bool>> reachable(n, vector<bool>(n, false));

    // Set direct connections from input edges
    for (auto& edge : edges)
        reachable[edge[0]][edge[1]] = true;

    // Floyd-Warshall: compute transitive closure
    for (int k = 0; k < n; ++k) {         // k = intermediate
        for (int i = 0; i < n; ++i) {     // i = start
            for (int j = 0; j < n; ++j) { // j = end
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
            }
        }
    }

    return reachable;
}
```

### Union Find
The **Union-Find** (or Disjoint Set Union, DSU) is a data structure that efficiently handles dynamic connectivity queries. It supports two primary operations:
- **Union**: Connect two elements.
- **Find**: Determine which component a particular element belongs to.
### 🔧 Time Complexity
- **Find**: `O(α(n))` — where `α` is the inverse Ackermann function, which grows very slowly.
- **Union**: `O(α(n))` — same as Find.
### ✅ Use Cases
- Detecting cycles in undirected graphs.(for 2 nodes if they have same ultimate parent, then cycle exists)
- Finding connected components. (no. of unique ultimate parents)
- Kruskal's algorithm for Minimum Spanning Tree (MST).
### 🧮 C++ Implementation
```cpp
class DSU {
    vector<int>parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }
    int findParent(int node) {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]) {
            parent[pv]=pu;
            size[pu]+=size[pv];
        } else {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
```
