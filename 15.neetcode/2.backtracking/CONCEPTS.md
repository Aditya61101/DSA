## 🔄 Recursion / Backtracking Variable Types

When writing recursive or backtracking solutions, it's crucial to understand how different variables behave in the recursion tree. They typically fall into three broad categories:

---

### 1. 🌿 Branch / Depth Variables

- **Definition**: These variables represent the current state of one path (branch) in the recursion tree.
- **Usage**: Used to carry state *through* a specific branch.
- **Pass Type**:
  - Immutable types (e.g., `int`, `bool`) — pass by value.
  - Mutable types (e.g., `vector`, `string`) — pass by reference **and reset manually** after recursive calls.
- **Reset Needed?** ✅ Yes — if mutable, to undo changes after the recursive call (backtracking).
- **Example Use Case**: Building combinations, subsets, or paths.

```cpp
void backtrack(vector<int>& nums, int start, vector<int>& path) {
    result.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);        // Modify state
        backtrack(nums, i + 1, path);   // Recurse
        path.pop_back();                // Backtrack (undo)
    }
}
```

### 2. 🎚️ Level Variables(Local scope)

- **Definition**: Variables created inside each function call, isolated to that specific recursion level.
- **Usage**: Temporary computations — don't carry state across branches.
- **Pass Type**: Created directly in the function scope.
- **Reset Needed?** ❌ No — they go out of scope after the function call ends.
- **Example Use Case**: Calculating minimums, totals in each call level.

```cpp
int solve(int i) {
    int minCost = INT_MAX; // Local to this call only
    for (int jump : {1, 2}) {
        minCost = min(minCost, solve(i + jump));
    }
    return minCost;
}
```

### 3. 🗺️ Recursion Tree-Wide / Global / Shared Variables

- **Definition**: Variables that are shared across all recursive calls, maintaining state throughout the recursion.
- **Usage**: Used to store results or states that need to be accessed by all branches.
- **Pass Type**: Passed by reference or declared globally.
- **Reset Needed?** ❌ No — unless explicitly reused for another test case.
- **Example Use Case**: Storing results, counts, visited tracking or flags that need to be accessed by all branches.

```cpp
int solve(int i, vector<int>& dp) {
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];
    
    return dp[i] = min(solve(i + 1, dp), solve(i + 2, dp)) + cost[i];
}
```
