## 🧠 Top-Down vs Bottom-Up in Dynamic Programming

Dynamic Programming (DP) problems can be solved using two major approaches:

---

### 🔼 Top-Down (Recursion + Memoization)

#### ✅ Characteristics:
- Starts from the **main problem** and recursively breaks it into **subproblems**.
- Uses **memoization** (`dp[i]`) to store and reuse results of subproblems.
- Solves **only the needed subproblems** (lazy evaluation).
- Uses **recursion + cache**.

#### 🧠 Think of it as:
> “Break the big problem into smaller ones and solve them only when needed.”

#### 🧩 Example:
```cpp
int solve(int i) {
    if (i == 0) return base;
    if (dp[i] != -1) return dp[i];
    return dp[i] = solve(i - 1) + solve(i - 2);
}
```

### 🔽 Bottom-Up (Tabulation)

#### ✅ Characteristics:
- Starts from **base cases**, then builds up the solution iteratively.
- Uses a loop instead of recursion.
- Solves **all subproblems**, even if not all are required.
- Enables **space optimization** easily.

#### 🧠 Think of it as:
> “Start from the smallest building blocks and work your way up.”

#### 🧩 Example:
```cpp
dp[0] = base;
for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
```