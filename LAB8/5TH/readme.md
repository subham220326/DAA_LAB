# Q5: Maximum Sum Increasing Subsequence

---

## Q5: Maximum Sum of a Strictly Increasing Subsequence

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 5** of Lab-08.

Given an array of positive integers, the objective is to determine the **maximum possible sum** of a strictly increasing subsequence.

## ⚙️ Algorithmic Logic & Justification

1. Define `dp[i]` as the maximum sum of an increasing subsequence ending at index `i`.

2. Initially:

   $$dp[i] = A[i]$$

3. For every previous index `j < i`, if:

   $$A[j] < A[i]$$

   then:

   $$dp[i] = \max(dp[i], dp[j] + A[i])$$

4. The maximum value in `dp[]` represents the maximum sum of an increasing subsequence.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n²)**
- **Auxiliary Space Complexity:** **O(n)**

## 💻 Sample Execution & Output

### Sample Input

```text
Array: 1 101 2 3 100 4 5
```

### Sample Output

```text
Maximum Sum Increasing Subsequence = 106
```

The optimal subsequence is:

```text
1 2 3 100
```

with sum:

```text
1 + 2 + 3 + 100 = 106
```

### Performance Summary

| Input                     | Algorithm | Approach            | Auxiliary Space | Total Time Complexity |
| :------------------------ | :-------- | :------------------ | :-------------- | :-------------------- |
| `A = {1,101,2,3,100,4,5}` | MSIS      | Dynamic Programming | **O(n)**        | **O(n²)**             |

---
