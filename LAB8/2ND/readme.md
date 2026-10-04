# Q2: Coin Change — Total Number of Ways

---

## Q2: Count Total Number of Distinct Coin Combinations

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 2** of Lab-08.

Given an array of distinct positive integer coin denominations and a target amount `V`, the objective is to determine the **total number of distinct combinations** that can produce the target amount.

An unlimited supply of every denomination is available. The order of coins does not matter; therefore, `1 + 2` and `2 + 1` are considered the same combination.

## ⚙️ Algorithmic Logic & Justification

1. **Dynamic Programming State:**\
   Define `dp[j]` as the number of ways to make amount `j`.

2. **Base Case:**\
   `dp[0] = 1`, because there is exactly one way to make zero — by selecting no coins.

3. Process the denominations one at a time.

4. For each coin `c`, update:

   $$dp[j] = dp[j] + dp[j-c]$$

5. Processing coins in the outer loop ensures that different orders of the same combination are not counted separately.

6. The final value `dp[V]` gives the total number of distinct combinations.

## 📊 Complexity Analysis

- **Time Complexity:** **O(nV)**
- **Auxiliary Space Complexity:** **O(V)**

## 💻 Sample Execution & Output

### Sample Input

```text
Number of coin denominations: 3
Coin denominations: 1 2 5
Target amount: 5
```

### Sample Output

```text
Total number of ways = 4
```

The combinations are:

```text
5
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1
```

### Performance Summary

| Input                    | Algorithm        | Approach            | Auxiliary Space | Total Time Complexity |
| :----------------------- | :--------------- | :------------------ | :-------------- | :-------------------- |
| `coins = {1,2,5}, V = 5` | Coin Change Ways | Dynamic Programming | **O(V)**        | **O(nV)**             |

---
