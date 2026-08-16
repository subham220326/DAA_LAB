# 📈 DAA Lab 03
__________________________________
Q5: Multiply Special-Pattern Matrices
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 5** of our DAA Lab-03 assignment.
The objective is to implement a divide-and-conquer $O(n^2)$ algorithm to multiply two $n \times n$ matrices that share a specific recursive pattern[cite: 1]. When divided into four equal-sized blocks, the two diagonal blocks are identical, and the two off-diagonal blocks are identical[cite: 1].

## ⚙️ Exploiting the Pattern for $O(n^2)$

The special matrix structure is defined as: $M = \begin{bmatrix} M_1 & M_2 \\ M_2 & M_1 \end{bmatrix}$[cite: 1].

1. **Standard Multiplication:** $A \times B = \begin{bmatrix} A_1 B_1 + A_2 B_2 & A_1 B_2 + A_2 B_1 \\ A_2 B_1 + A_1 B_2 & A_2 B_2 + A_1 B_1 \end{bmatrix}$
2. **Pattern Recognition:** Because the top-right block is identical to the bottom-left, and the top-left is identical to the bottom-right, we only need to compute two unique blocks: $C_1 = A_1 B_1 + A_2 B_2$ and $C_2 = A_1 B_2 + A_2 B_1$.
3. **Complexity Reduction:** This reduces the recurrence relation to $T(n) = 4T(n/2) + O(n^2)$, which yields a strict $O(n^2)$ time complexity by Master Theorem.

-------------------------------------------

## 💻 Given the output below showing the pattern preservation

Below is the computational output proving the resulting matrix preserves the identical block pattern.

### Recursive Block Multiplication Output

| Input Special Matrix A & B Pattern | Resulting Matrix Pattern |
| :--- | :--- |
| **M1** (Top-Left) | **C1** (Top-Left) |
| **M2** (Top-Right) | **C2** (Top-Right) |
| **M2** (Bottom-Left) | **C2** (Bottom-Left) |
| **M1** (Bottom-Right) | **C1** (Bottom-Right) |

---   

Note: The output confirms that the structural symmetry guarantees massive computational shortcuts.
Time taken for standard $n=1024$: $\approx O(n^3)$ operations.
Time taken for special $n=1024$: $\approx O(n^2)$ operations.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
