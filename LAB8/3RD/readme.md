# Q3: Longest Common Subsequence (LCS)

---

## Q3: Compute and Reconstruct the Longest Common Subsequence

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 3** of Lab-08.

Given two sequences `X` and `Y`, the objective is to compute the **length of their Longest Common Subsequence (LCS)** and reconstruct the actual subsequence.

The LCS does not require the characters to occur consecutively, but their relative order must remain unchanged.

## ⚙️ Algorithmic Logic & Justification

1. Define:

   $$dp[i][j]$$

   as the length of the LCS between the first `i` elements of `X` and the first `j` elements of `Y`.

2. **Base Case:**

   $$dp[i][0] = 0$$

   and

   $$dp[0][j] = 0$$

3. If:

   $$X[i-1] = Y[j-1]$$

   then:

   $$dp[i][j] = dp[i-1][j-1] + 1$$

4. Otherwise:

   $$dp[i][j] = \max(dp[i-1][j], dp[i][j-1])$$

5. After constructing the DP table, traceback from `dp[m][n]` to reconstruct the actual LCS.

## 📊 Complexity Analysis

- **Time Complexity:** **O(mn)**
- **Auxiliary Space Complexity:** **O(mn)**

where `m` and `n` are the lengths of the two sequences.

## 💻 Sample Execution & Output

### Sample Input

```text
First string: ABCBDAB
Second string: BDCABA
```

### Sample Output

```text
LCS length = 4
LCS = BCBA
```

Another valid LCS of length 4 may also exist depending on the traceback choice.

### Performance Summary

| Input                     | Algorithm | Approach                        | Auxiliary Space | Total Time Complexity |
| :------------------------ | :-------- | :------------------------------ | :-------------- | :-------------------- |
| `X = ABCBDAB, Y = BDCABA` | LCS       | Dynamic Programming + Traceback | **O(mn)**       | **O(mn)**             |

---
