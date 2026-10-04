# Q4: Longest Increasing Subsequence

---

## Q4: Find the Length of the Longest Strictly Increasing Subsequence

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 4** of Lab-08.

Given an integer array `A`, the objective is to determine the length of the longest subsequence in which every element is **strictly greater than the previous element**.

## ⚙️ Algorithmic Logic & Justification

1. Define `dp[i]` as the length of the longest increasing subsequence ending at index `i`.

2. Initially:

   $$dp[i] = 1$$

   because every individual element forms an increasing subsequence of length 1.

3. For every pair `j < i`, check:

   $$A[j] < A[i]$$

4. If the condition is satisfied:

   $$dp[i] = \max(dp[i], dp[j] + 1)$$

5. The maximum value in `dp[]` is the length of the LIS.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n²)**
- **Auxiliary Space Complexity:** **O(n)**

## 💻 Sample Execution & Output

### Sample Input

```text
Array: 10 22 9 33 21 50 41 60
```

### Sample Output

```text
Length of LIS = 5
```

One LIS is:

```text
10 22 33 50 60
```

### Performance Summary

| Input                          | Algorithm | Approach            | Auxiliary Space | Total Time Complexity |
| :----------------------------- | :-------- | :------------------ | :-------------- | :-------------------- |
| `A = {10,22,9,33,21,50,41,60}` | LIS       | Dynamic Programming | **O(n)**        | **O(n²)**             |

---
