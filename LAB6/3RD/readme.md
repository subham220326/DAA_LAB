# 📈 DAA Lab 06 (DP): Q3 — Longest Common Subsequence (LCS)
__________________________________
Q3: Longest Common Subsequence using Dynamic Programming
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 3** of the Dynamic Programming assignment.
The objective is to compute the length of the Longest Common Subsequence of two strings and reconstruct the explicit subsequence via matrix backtracking.

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `dp[i][j]` represent the LCS length between prefix $X[0 \dots i-1]$ and $Y[0 \dots j-1]$.
2. **Transition Function:**
   - If $X[i-1] == Y[j-1]$: `dp[i][j] = dp[i-1][j-1] + 1`.
   - Else: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
3. **Backtracking:** Starting at `dp[m][n]`, trace backwards:
   - If characters match, record the character and decrement both pointers.
   - Else, step toward the neighboring cell with the larger value (`dp[i-1][j]` or `dp[i][j-1]`).
4. **Justification:** Solves the combinatorial string alignment problem by breaking it down into sub-prefix comparisons.

---

## 📊 Complexity Analysis

- **Table Construction Time:** **$O(m \cdot n)$** where $m$ and $n$ are string lengths.
- **Subsequence Reconstruction Time:** **$O(m + n)$**.
- **Total Time Complexity:** **$O(m \cdot n)$**.
- **Auxiliary Space Complexity:** **$O(m \cdot n)$** (2D DP table).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Strings | String Lengths | LCS Output | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `X = "AGGTAB"`, `Y = "GXTXAYB"` | $m = 6, n = 7$ | `"GTAB"` (Length 4) | **$O(m \cdot n)$** | **$O(m \cdot n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
