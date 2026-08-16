# 📈 DAA Lab 03
__________________________________
Q4: Matrix Multiplication using D&C Approach
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 4** of our DAA Lab-03 assignment.
The objective is to multiply two square matrices of size $n \times n$ using Strassen’s divide and conquer method[cite: 1]. This advanced algorithmic approach reduces the asymptotic time complexity of matrix multiplication below the standard $O(n^3)$.

## ⚙️ Strassen's Optimization

Strassen's algorithm avoids the standard dot-product method by aggressively dividing the matrices into quadrants:

1. **Standard Method:** Requires 8 recursive multiplications for a $2 \times 2$ split ($O(n^3)$).
2. **Strassen's Method:** Computes 7 intermediate matrices ($P_1$ through $P_7$) using additions and subtractions.
3. **Efficiency:** Reduces the recursive multiplications from 8 to 7, bringing the time complexity down to $O(n^{\log_2 7}) \approx O(n^{2.81})$.

-------------------------------------------

## 💻 Given the output below showing the intermediate matrix calculations

Below is the computational output multiplying two $4 \times 4$ matrices using Strassen's 7-step formulas.

### Matrix Multiplication Result

| Matrix A | Matrix B | Resultant Matrix (A x B) |
| :--- | :--- | :--- |
| `[1, 2]`<br>`[3, 4]` | `[5, 6]`<br>`[7, 8]` | `[19, 22]`<br>`[43, 50]` |

---   

Note: Strassen's algorithm is practically beneficial for very large matrices.
Standard operations for $2 \times 2$: 8 multiplications.
Strassen operations for $2 \times 2$: 7 multiplications.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
