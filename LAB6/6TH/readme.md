# 📈 DAA Lab 06: Q6 — 2D Square Matrix Operations
__________________________________
Q6: 2D Square Matrix Algebra, Determinants & Eigen Decomposition
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 6** of Lab-06.
The objective is to implement foundational linear algebraic operations on an $n \times n$ square matrix, covering basic matrix algebra, triangular reductions, and iterative spectral solvers.

## ⚙️ Algorithmic Logic & Justification

1. **Matrix Arithmetic & Predicates:** Element-wise addition, matrix multiplication, and predicate verification (zero matrix, symmetry).
2. **In-Place Transposition:** Swapping symmetric entry pairs across the primary diagonal without secondary buffers.
3. **Gaussian Elimination (Determinant):** Row reductions using partial pivoting to convert matrix to upper-triangular form, tracking row swap parity.
4. **Dominant Eigen Decomposition:** Power iteration method normalizing intermediate vectors to isolate the principal eigenvalue and eigenvector.

---

## 📊 Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Implementation Strategy |
| :--- | :--- | :--- | :--- |
| (i) Matrix Addition | **$O(n^2)$** | $O(1)$ | Direct element summation |
| (ii) Matrix Multiplication | **$O(n^3)$** | $O(1)$ | Standard triple-loop multiplication |
| (iii) Zero Matrix Check | **$O(n^2)$** | $O(1)$ | Early-exit zero scan |
| (iv) Symmetric Check | **$O(n^2)$** | $O(1)$ | Pairwise check ($A_{ij} == A_{ji}$) |
| (v) Determinant | **$O(n^3)$** | $O(n^2)$ copy | Gaussian elimination with pivoting |
| (vi) In-Place Transpose | **$O(n^2)$** | $O(1)$ | Upper-triangle swap |
| (vii) Eigenpair | **$O(k \cdot n^2)$** | $O(n)$ | Power iteration method |

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Matrix Dimension | Determinant Method | Eigen Method | Space Complexity |
| :--- | :--- | :--- | :--- |
| $3 \times 3$ Floating Point Matrix | Gaussian Triangular Reduction | Rayleigh Power Iteration | $O(1)$ Auxiliary (In-Place Transpose) |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06 
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
