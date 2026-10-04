# Q7: Rod Cutting with Reconstruction

---

## Q7: Maximum Revenue and Optimal Rod Decomposition

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 7** of Lab-08.

Given a rod of length `n` and an array of prices where `pi` represents the price of a piece of length `i`, the objective is to determine:

1. The maximum revenue obtainable by cutting the rod.
2. The exact piece lengths that produce the optimal revenue.

The rod pieces must have integral lengths and their total length must equal `n`.

## ⚙️ Algorithmic Logic & Justification

1. Define `dp[i]` as the maximum revenue obtainable from a rod of length `i`.

2. For every possible first cut `j`:

   $$dp[i] = \max(dp[i], P[j] + dp[i-j])$$

3. Store the selected cut in an additional array `cut[]`.

4. After calculating `dp[n]`, repeatedly use `cut[]` to reconstruct the exact decomposition.

5. This allows both the maximum revenue and the optimal piece lengths to be obtained.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n²)**
- **Auxiliary Space Complexity:** **O(n)**

## 💻 Sample Execution & Output

### Sample Input

```text
Rod length: 8
Prices:
1 5 8 9 10 17 17 20
```

### Sample Output

```text
Maximum Revenue = 22
Optimal pieces: 2 6
```

The optimal decomposition is:

```text
2 + 6 = 8
```

Revenue:

```text
5 + 17 = 22
```

### Performance Summary

| Input   | Algorithm   | Approach                             | Auxiliary Space | Total Time Complexity |
| :------ | :---------- | :----------------------------------- | :-------------- | :-------------------- |
| `n = 8` | Rod Cutting | Dynamic Programming + Reconstruction | **O(n)**        | **O(n²)**             |

---
