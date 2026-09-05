# 📈 DAA Lab 06: Q6 — 2D Square Matrix Operations
__________________________________
Q6: 2D Square Matrix Algebra, Determinants & Eigen Decomposition
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 2** of Lab-06[cite: 1].
The objective is to implement foundational linear algebraic operations on an $n \times n$ square matrix, covering basic matrix algebra, triangular reductions, and iterative spectral solvers[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Matrix Arithmetic & Predicates:** Element-wise addition, matrix multiplication, and predicate verification (zero matrix, symmetry)[cite: 1].
2. **In-Place Transposition:** Swapping symmetric entry pairs across the primary diagonal without secondary buffers[cite: 1].
3. **Gaussian Elimination (Determinant):** Row reductions using partial pivoting to convert matrix to upper-triangular form, tracking row swap parity[cite: 1].
4. **Dominant Eigen Decomposition:** Power iteration method normalizing intermediate vectors to isolate the principal eigenvalue and eigenvector[cite: 1].

---

## 📊 Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Implementation Strategy |
| :--- | :--- | :--- | :--- |
| (i) Matrix Addition[cite: 1] | **$O(n^2)$** | $O(1)$ | Direct element summation[cite: 1] |
| (ii) Matrix Multiplication[cite: 1] | **$O(n^3)$** | $O(1)$ | Standard triple-loop multiplication[cite: 1] |
| (iii) Zero Matrix Check[cite: 1] | **$O(n^2)$** | $O(1)$ | Early-exit zero scan[cite: 1] |
| (iv) Symmetric Check[cite: 1] | **$O(n^2)$** | $O(1)$ | Pairwise check ($A_{ij} == A_{ji}$)[cite: 1] |
| (v) Determinant[cite: 1] | **$O(n^3)$** | $O(n^2)$ copy | Gaussian elimination with pivoting[cite: 1] |
| (vi) In-Place Transpose[cite: 1] | **$O(n^2)$** | $O(1)$ | Upper-triangle swap[cite: 1] |
| (vii) Eigenpair[cite: 1] | **$O(k \cdot n^2)$** | $O(n)$ | Power iteration method[cite: 1] |

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Matrix Dimension | Determinant Method | Eigen Method | Space Complexity |
| :--- | :--- | :--- | :--- |
| $3 \times 3$ Floating Point Matrix | Gaussian Triangular Reduction[cite: 1] | Rayleigh Power Iteration[cite: 1] | $O(1)$ Auxiliary (In-Place Transpose)[cite: 1] |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06[cite: 1]  
> **Instructor:** Dr. Ajaya Kumar Dash[cite: 1]  
> **Date:** 31 August 2026[cite: 1]
