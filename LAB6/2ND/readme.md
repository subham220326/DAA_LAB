# 📈 DAA Lab 06 (DP): Q2 — 0/1 Knapsack Problem
__________________________________
Q2: 0/1 Knapsack Problem using Dynamic Programming
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 2** of the Dynamic Programming assignment.
Given $n$ items with associated weights and profits along with a knapsack capacity $W$, the goal is to determine the maximum subset profit without exceeding $W$.

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `dp[i][w]` denote the maximum profit achievable using a subset of the first $i$ items with weight capacity $w$.
2. **Base Condition:** For all $w \in [0, W]$, `dp[0][w] = 0`, and for all $i \in [0, n]$, `dp[i][0] = 0`.
3. **Transition Function:**
   - If item weight exceeds capacity ($\text{wt}[i-1] > w$): `dp[i][w] = dp[i-1][w]`.
   - Otherwise: `dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])`.
4. **Justification:** The 0/1 restriction exhibits optimal substructure and overlapping subproblems, solved via pseudo-polynomial dynamic programming.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n \cdot W)$** (Filling an $(n+1) \times (W+1)$ table).
- **Auxiliary Space Complexity:** **$O(n \cdot W)$** (2D table allocation).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Parameters | Items ($n$) | Capacity ($W$) | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `val = {60, 100, 120}`, `wt = {10, 20, 30}` | $n = 3$ | $W = 50$ | **$O(n \cdot W)$** | **$O(n \cdot W)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
