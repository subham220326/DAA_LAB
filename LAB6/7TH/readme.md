# 📈 DAA Lab 06: Q7 — Fast Convolution via FFT
__________________________________
Q7: Vector Discrete Linear Convolution using Divide-and-Conquer FFT
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 3** of Lab-06[cite: 1].
The objective is to compute the discrete linear convolution $C[k] = \sum_{j=0}^{m-1} A[j]B[k-j]$ of vectors $A$ and $B$ (lengths $m$ and $n$, with $n \ge m$) using an $O(n \log n)$ divide-and-conquer strategy[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Polynomial Equivalence:** Convolution is mathematically equivalent to polynomial multiplication: $C(x) = A(x) \cdot B(x)$[cite: 1].
2. **Padding:** Both vectors are zero-padded to length $N$, where $N$ is the smallest power of 2 such that $N \ge n + m - 1$[cite: 1].
3. **Cooley-Tukey Divide-and-Conquer FFT:** Recursively split inputs into even and odd index subsequences, evaluating polynomials at roots of unity in $O(N \log N)$[cite: 1].
4. **Pointwise Multiplication & IFFT:** Multiply point evaluations in $O(N)$ and apply Inverse FFT to retrieve the convolution coefficients[cite: 1].

---

## 📊 Complexity Analysis

- **FFT Transformation Time:** $T(N) = 2T(N/2) + O(N) \implies \mathbf{O(n \log n)}$[cite: 1].
- **Pointwise Multiplication Time:** **$O(N) = O(n)$**[cite: 1].
- **IFFT Recovery Time:** **$O(n \log n)$**[cite: 1].
- **Total Time Complexity:** **$O(n \log n)$** (Outperforms direct $O(n \cdot m)$ convolution)[cite: 1].
- **Auxiliary Space Complexity:** **$O(n)$** (Buffers for complex FFT arrays).

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Vectors | Vector Lengths | Output Size ($n+m-1$) | Time Complexity | Compilation Flag |
| :--- | :--- | :--- | :--- | :--- |
| `A = [1, 2, 3]`, `B = [4, 5, 6, 7]`[cite: 1] | $m = 3, n = 4$[cite: 1] | $6$ Elements | **$O(n \log n)$**[cite: 1] | `-lm` (Math library) |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06[cite: 1]  
> **Instructor:** Dr. Ajaya Kumar Dash[cite: 1]  
> **Date:** 31 August 2026[cite: 1]
