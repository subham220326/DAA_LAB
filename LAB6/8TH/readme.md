# 📈 DAA Lab 06: Q8 — Sorting Permutations via Reversal
__________________________________
Q8: Subsequence Reversal Sorting with $O(n \log^2 n)$ Cost
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation, mathematical proof, and complexity analysis for **Question 8** of Lab-06.
Given a permutation $p$ of integers $\{1, \dots, n\}$, the only valid mutation is `reverse(p, i, j)` with cost $|j - i| + 1$. The objective is to prove $O(n)$ bounds on the number of reversals and implement an $O(n \log^2 n)$ total cost sorting algorithm.

## ⚙️ Algorithmic Logic & Justification

1. **Reversal Count Proof:** Locating element $i$ and calling `reverse(p, i, k)` places $i$ into its correct index in at most 1 reversal. Over $n$ elements, sorting requires at most $n-1 = \mathbf{O(n)}$ reversals.
2. **Block Swap Routine:** Swapping two contiguous subarrays $A$ and $B$ is accomplished via 3 reversals: $\text{reverse}(A)$, $\text{reverse}(B)$, $\text{reverse}(AB)$, incurring a cost of $2(|A| + |B|)$.
3. **Divide-and-Conquer In-Place Merge:** Recursively sort left and right halves. Merge in-place using binary search to split subarrays and exchange segments via block swaps.
4. **Recurrence Relation:**
   $$T(n) = 2T(n/2) + O(n \log n) \implies \mathbf{O(n \log^2 n)}$$

---

## 📊 Complexity Analysis

- **Reversal Operation Count:** **$O(n)$** operations.
- **Total Reversal Cost:** **$O(n \log^2 n)$** (Derived via Master Theorem Case 2).
- **Auxiliary Space Complexity:** **$O(\log n)$** (Recursion stack frames).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Permutation | Number of Elements ($n$) | Reversal Primitive Cost | Reversal Bound | Total Cost Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `p = [1, 4, 3, 2, 5]` | $n = 5$ | $|j - i| + 1$ | $O(n)$ reversals | **$O(n \log^2 n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
