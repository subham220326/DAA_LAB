# Q7: Matrix Chain Multiplication (MCM)
__________________________________
Q7: Matrix Chain Multiplication using Dynamic Programming
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 7** of Lab-07[cite: 1].
The objective is to compute the optimal parenthesization of a chain of $n$ matrices that minimizes scalar multiplications[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **State Definition:** Let `m[i][j]` denote the minimum scalar multiplications needed to compute matrix chain product $A_i \dots A_j$ (where dimension of $A_k$ is $p_{k-1} \times p_k$).
2. **Base Cases:** `m[i][i] = 0` for all $1 \le i \le n$.
3. **Recurrence Relation:** For chain length $L \in [2, n]$:
   $$\text{m}[i][j] = \min_{i \le k < j} \left( \text{m}[i][k] + \text{m}[k+1][j] + p_{i-1} \cdot p_k \cdot p_j \right)$$
4. **Optimal Parenthesization:** Store the split index $k$ in auxiliary table `s[i][j] = k` to reconstruct the nested parenthesization string via divide-and-conquer.
5. **Justification:** Optimal substructure and overlapping subproblems satisfy Bellman's principle of optimality; bottom-up diagonal tabulation computes all short chains before evaluating longer products.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n^3)$** (Triply nested loop across chain length $L$, starting index $i$, and partition split $k$).
- **Auxiliary Space Complexity:** **$O(n^2)$** to store DP lookup table `m` and split tracker `s`.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input (Dimensions) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `p = [10, 20, 30, 40, 30]` | Matrix Chain Order | Dynamic Programming (Tabulation) | **$O(n^2)$** | **$O(n^3)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026
