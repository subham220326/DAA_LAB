# Q3: Reve's Puzzle
__________________________________
Q3: 4-Peg Tower of Hanoi (Frame-Stewart Algorithm)
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 3** of Lab-07[cite: 1].
The objective is to transfer $n$ disks across 4 pegs adhering to standard Hanoi rules, achieving the optimal 33 moves for $n = 8$ disks[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Frame-Stewart Strategy:**
   - Partition $n$ disks using split parameter $k \in [1, n-1]$.
   - Transfer top $k$ disks from source to an auxiliary peg using all 4 pegs ($R(k)$ moves).
   - Transfer remaining $n-k$ largest disks from source to destination using the remaining 3 pegs without touching the auxiliary peg ($2^{n-k}-1$ moves).
   - Transfer the $k$ disks from auxiliary to destination using all 4 pegs ($R(k)$ moves).
2. **Recurrence Relation:**
   $$R(n) = \min_{1 \le k < n} \left( 2 R(k) + 2^{n-k} - 1 \right)$$
   For $n = 8$, optimal split occurs at $k = 4$ or $k = 5$:
   $$R(8) = 2 \cdot R(4) + 2^4 - 1 = 2(9) + 15 = 33 \text{ moves}$$
3. **Justification:** The auxiliary fourth peg permits an asymmetric divide-and-conquer strategy, dropping the operational bound from $O(2^n)$ down to sub-exponential scale.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n^2)$** to compute transition DP; action execution path length is **$O(2^{\sqrt{2n}})$**.
- **Auxiliary Space Complexity:** **$O(n)$** recursion stack depth and lookup table.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 8` | Reve's 4-Peg Puzzle | Frame-Stewart DP / Recursion | **$O(n)$** | **$O(2^{\sqrt{2n}})$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07 
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026

---
