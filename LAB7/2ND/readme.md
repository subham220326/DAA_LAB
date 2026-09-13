# Q2: Super Egg Testing Experiment
__________________________________
Q2: Generalized Egg Dropping Problem using Dynamic Programming
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 2** of Lab-07[cite: 1].
The objective is to find the minimum number of droppings guaranteed to locate the critical threshold floor among $F$ floors given $E$ identical eggs[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `dp[i][j]` denote the minimum attempts needed in the worst case with $i$ eggs and $j$ floors.
2. **Base Cases:**
   - `dp[1][j] = j` (with 1 egg, linear sequential search is mandatory)
   - `dp[i][0] = 0`, `dp[i][1] = 1` for all $i \ge 1$
3. **Bottom-Up Tabulation:** For an egg dropped from floor $x \in [1, j]$:
   - Egg breaks: subproblem reduces to `dp[i-1][x-1]`
   - Egg survives: subproblem reduces to `dp[i][j-x]`
   $$\text{dp}[i][j] = 1 + \min_{1 \le x \le j} \max\left(\text{dp}[i-1][x-1],\, \text{dp}[i][j-x]\right)$$
4. **Justification:** Subproblem states overlap across candidate floors. Memoization across all threshold trials ensures worst-case optimality without redundant recomputation.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(E \cdot F^2)$** via classical DP (reducible to **$O(E \cdot F \log F)$** using binary search for critical split points).
- **Auxiliary Space Complexity:** **$O(E \cdot F)$** to store the dynamic programming lookup table.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($E, F$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `E = 2, F = 100` | Super Egg Drop Solver | Dynamic Programming (Tabulation) | **$O(E \cdot F)$** | **$O(E \cdot F^2)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026

---
