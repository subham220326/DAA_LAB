# 📈 DAA Lab 06 (DP): Q1 — nth Fibonacci Number
__________________________________
Q1: nth Fibonacci Number using Dynamic Programming
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 1** of the Dynamic Programming assignment.
The objective is to compute the $n$-th Fibonacci number using a bottom-up Dynamic Programming approach, avoiding the exponential overhead of naive recursion.

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `dp[i]` represent the $i$-th Fibonacci number.
2. **Base Cases:** Initialize `dp[0] = 0` and `dp[1] = 1`.
3. **Bottom-Up Tabulation:** Compute subsequent values iteratively using the recurrence relation:
   $$\text{dp}[i] = \text{dp}[i-1] + \text{dp}[i-2] \quad \text{for } 2 \le i \le n$$
4. **Justification:** Naive recursion repeats overlapping subproblems, resulting in $O(2^n)$ runtime. Tabulation memoizes previously solved states, reducing computation to linear time.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n)$** (Single loop executing $n-1$ times).
- **Auxiliary Space Complexity:** **$O(n)$** using a DP table (can be optimized to **$O(1)$** by storing only the previous two states).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 10` | Bottom-Up Fibonacci | Tabulation (Iterative) | **$O(n)$** | **$O(n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
