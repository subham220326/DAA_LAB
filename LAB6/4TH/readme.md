# 📈 DAA Lab 06 (DP): Q4 — Matrix Chain Multiplication (MCM)
__________________________________
Q4: Matrix Chain Multiplication using Dynamic Programming
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 4** of the Dynamic Programming assignment.
Given dimension array `arr[]` representing a chain of $N-1$ matrices, the objective is to determine the optimal parenthesization minimizing total scalar multiplications.

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `dp[i][j]` be the minimum multiplication cost for multiplying matrices $A_i$ through $A_j$.
2. **Base Case:** `dp[i][i] = 0` for all $1 \le i < N$.
3. **Chain Length Traversal:**
   - Iterate chain length $L$ from $2$ to $N-1$.
   - For split point $k$ from $i$ to $j-1$:
     $$\text{dp}[i][j] = \min_{i \le k < j} \{\text{dp}[i][k] + \text{dp}[k+1][j] + \text{arr}[i-1] \cdot \text{arr}[k] \cdot \text{arr}[j]\}$$
4. **Justification:** Matrix multiplication is associative. Minimizing operation costs requires evaluating parenthesization split points without recalculating identical sub-chains.

---

## 📊 Complexity Analysis

- **Total Time Complexity:** **$O(N^3)$** (Three nested loops: chain length, start index, split index).
- **Auxiliary Space Complexity:** **$O(N^2)$** ($N \times N$ DP memoization table).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Matrix Chain Array | Matrix Count | Min Scalar Operations | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `arr = {10, 30, 5, 60}` | $3$ matrices | `4500` | **$O(N^2)$** | **$O(N^3)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
