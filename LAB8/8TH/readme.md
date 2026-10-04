# Q8: Optimal Binary Search Trees (OBST)

---

## Q8: Minimum Expected Search Cost of an Optimal BST

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 8** of Lab-08.

Given sorted keys `K = {k1, k2, ..., kn}`, successful-search probabilities `p1, p2, ..., pn`, and dummy keys with probabilities `q0, q1, ..., qn`, the objective is to construct an **Optimal Binary Search Tree** with minimum expected search cost.

## ⚙️ Algorithmic Logic & Justification

1. Define:

   $$e[i][j]$$

   as the minimum expected search cost for keys `ki` through `kj`.

2. Define:

   $$w[i][j]$$

   as the total probability associated with the subtree.

3. Initialize:

   $$e[i][i-1] = q\_{i-1}$$

4. For every possible root `r` between `i` and `j`, calculate:

   $$e[i][r-1] + e[r+1][j] + w[i][j]$$

5. Select the root that gives the minimum cost.

6. Store the root in a `root[][]` table so that the optimal tree can also be reconstructed if required.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n³)**
- **Auxiliary Space Complexity:** **O(n²)**

The cubic time complexity occurs because every possible root is examined for every possible key interval.

## 💻 Sample Execution & Output

### Sample Input

```text
Number of keys: 3

Successful probabilities:
0.15 0.10 0.05

Unsuccessful probabilities:
0.05 0.10 0.05 0.05
```

### Sample Output

```text
Minimum Expected Search Cost = 1.2500
Root of optimal BST = Key 2
```

> **Note:** The numerical expected cost depends on the exact probability values supplied as input.

### Performance Summary

| Input   | Algorithm   | Approach            | Auxiliary Space | Total Time Complexity |
| :------ | :---------- | :------------------ | :-------------- | :-------------------- |
| `n = 3` | Optimal BST | Dynamic Programming | **O(n²)**       | **O(n³)**             |

---
