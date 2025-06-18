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
