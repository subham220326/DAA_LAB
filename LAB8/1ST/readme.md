# Q1: Minimum Coin Change

---

## Q1: Minimum Number of Coins Required

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 1** of Lab-08.

Given an array of coin denominations and a target amount `V`, the objective is to determine the **minimum number of coins required** to obtain the target amount.

An unlimited supply of each coin denomination is available. If the target amount cannot be formed using the given denominations, the algorithm returns `-1`.

## ⚙️ Algorithmic Logic & Justification

1. **Dynamic Programming State:**\
   Define `dp[i]` as the minimum number of coins required to form amount `i`.

2. **Base Case:**\
   `dp[0] = 0`, because zero coins are required to make amount zero.

3. **Recurrence:**\
   For every amount `i` and every coin `c`:

   $$dp[i] = \min(dp[i], dp[i-c] + 1)$$

   whenever `c ≤ i`.

4. **Final Answer:**\
   `dp[V]` gives the minimum number of coins required to form the target amount.

5. If `dp[V]` remains unreachable, the result is `-1`.

## 📊 Complexity Analysis

- **Time Complexity:** **O(nV)**
- **Auxiliary Space Complexity:** **O(V)**

where `n` is the number of coin denominations and `V` is the target amount.

## 💻 Sample Execution & Output

### Sample Input

```text
Number of coin denominations: 3
Coin denominations: 1 2 5
Target amount: 11
```

### Sample Output

```text
Minimum number of coins = 3
```

The optimal combination is:

```text
5 + 5 + 1 = 11
```

### Performance Summary

| Input                     | Algorithm           | Approach            | Auxiliary Space | Total Time Complexity |
| :------------------------ | :------------------ | :------------------ | :-------------- | :-------------------- |
| `coins = {1,2,5}, V = 11` | Minimum Coin Change | Dynamic Programming | **O(V)**        | **O(nV)**             |

---
