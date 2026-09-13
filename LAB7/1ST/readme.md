# 📈 DAA Lab 07 (Puzzles & Dynamic Programming)
__________________________________________________
Design and Analysis of Algorithms Laboratory — Assignment 07
__________________________________________________

---

## 📌 Repository Overview
This repository contains the algorithmic logic, asymptotic complexity derivations, and experimental performance profiles for **Lab 07: Algorithm Application Questions Based on Puzzles**[cite: 1].

---

# Q1: Invert the Coin-Triangle
__________________________________
Q1: Invert the Coin-Triangle in Minimum Moves
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 1** of Lab-07[cite: 1].
The objective is to determine the minimum number of coin slides required to invert an equilateral triangle of size $n$ (containing $T_n = \frac{n(n+1)}{2}$ coins) upside down[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Overlap Maximization:** Inverting the triangle corresponds to superimposing an inverted triangle of side length $n$ onto the original layout to maximize the overlapping interior coin lattice.
2. **Compact Formula:** The number of coins situated outside the maximal intersection corresponds directly to the required moves:
   $$M(n) = \left\lfloor \frac{n(n+1)}{6} \right\rfloor$$
   For $n = 4$ (10 coins)[cite: 1]:
   $$M(4) = \left\lfloor \frac{4 \times 5}{6} \right\rfloor = \lfloor 3.33 \rfloor = 3 \text{ moves}$$
3. **Justification:** Moving the 3 corner coins from the apex and base corners reposition them to invert the geometry, preserving the inner 7-coin hexagonal symmetry intact.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(1)$** via evaluation of the closed-form equation.
- **Auxiliary Space Complexity:** **$O(1)$** auxiliary space.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 4` (10 coins) | Triangle Inversion Formula | Mathematical / Closed-Form | **$O(1)$** | **$O(1)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07  
> **Instructor:** Dr. Ajaya Kumar Dash 
> **Date:** 08 September 2026

---
