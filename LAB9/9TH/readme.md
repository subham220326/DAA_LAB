---

# Q9: Optimal Alphabetic Tree (Knuth-Optimized DP)

---

## Q9: Optimal Alphabetic Tree (Knuth-Optimized DP)

**C Filename:** `9thHuTucker.c`

## 📌 Overview

Construct a minimum-cost full binary tree whose leaves retain their input order. Its cost is the sum of each weight multiplied by its leaf depth. Despite the filename `9thHuTucker.c`, the code implements interval dynamic programming, not the Hu–Tucker algorithm.

### Input Format

`n`, followed by `n` nonnegative integer leaf weights. Use `1 ≤ n ≤ 500` and keep prefix sums and all DP costs within `long long`.

## ⚙️ Algorithmic Logic & Justification

1. Build prefix sums `sum[]` for constant-time interval weight sums. Global zero initialization supplies `dp[i][i] = 0`, and the code sets `opt[i][i] = i`.
2. For interval `[i,j]`, try a split `k` into `[i,k]` and `[k+1,j]`:
   `dp[i][j] = min_k(dp[i][k] + dp[k+1][j]) + sum[j+1] - sum[i]`.
3. The added interval weight reflects increasing every leaf's depth by one when joining the two child trees.
4. Fill intervals in increasing length. Restrict split search to `opt[i][j-1] ... opt[i+1][j]`, with `k < j`.
5. For nonnegative weights, the interval-cost conditions give monotone optimal split points. This is Knuth optimization and reduces the total split-search work to O(n²).
6. Store the first minimizing split and recursively print the tree. Leaf labels are 1-based input indices, not weight values. Contiguous interval splits preserve the alphabetic order.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n²)** under the nonnegative-weight assumptions that justify Knuth optimization. There are O(n²) states, with O(n²) total split trials; tree printing adds O(n) node visits plus the cost of writing leaf labels.
- **Auxiliary Space Complexity:** **O(n²)** for `dp[][]` and `opt[][]`, plus O(n) prefix sums and up to O(n) recursion stack.
- Without the optimized split bounds, the ordinary interval recurrence would take O(n³), but that is not the implementation here.

## 💻 Sample Execution & Output

### Sample Input

```text
3
1 2 3
```

### Sample Output

```text
Minimum Cost: 9
Optimal Tree: ((1 2) 3)
```

### Limitations & Implementation Notes

This is exact for the stated nonnegative-weight domain. Negative weights are not checked and invalidate the optimized-search guarantee. `n` outside `1..500` produces no output. A single leaf has cost `0` and prints tree `1`. The sample labels happen to match the weights; in general they do not.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Interval DP + Knuth optimization | Exact optimal alphabetic tree; not Hu–Tucker | **O(n²)** | **O(n²)** |
