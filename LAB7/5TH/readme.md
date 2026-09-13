# Q5: Hitting a Moving Target
__________________________________
Q5: Deterministic Search for an Invisible Moving Target
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 5** of Lab-07[cite: 1].
The objective is to design a deterministic sequence of shots that guarantees hitting an unseen target moving between adjacent positions along $n$ hiding spots[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Parity Invariant:** Because the target moves to an adjacent cell between consecutive shots, its parity (odd $\leftrightarrow$ even spot) alternates strictly after each step[cite: 1].
2. **Two-Phase Sweep Strategy:**
   - **Phase 1 (Target initialized at Even spot):** Fire sequentially across positions $2, 3, \dots, n-1$. Parity synchronization ensures that if the target started at an even coordinate, it will be intercepted.
   - **Phase 2 (Target initialized at Odd spot):** If not hit in Phase 1, the target's parity is guaranteed to be inverted relative to original expectations. Sweep positions $2, 3, \dots, n-1$ (or reverse $n-1 \dots 2$) to intercept it.
3. **Sequence Length:**
   $$L = 2(n - 2) \quad \text{for } n \ge 3$$
4. **Justification:** Sweeping shifts the target toward the boundary walls, removing one degree of freedom until intersection is guaranteed.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n)$** (Generates and iterates through at most $2n-4$ moves).
- **Auxiliary Space Complexity:** **$O(1)$** auxiliary memory.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 5` | Parity Sweeping Strategy | Parity State Elimination | **$O(1)$** | **$O(n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026

---
