# Q4: Security Switches
__________________________________
Q4: Chinese Rings / Baguenaudier Security Switches
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 4** of Lab-07[cite: 1].
The objective is to compute the minimum moves required to switch off a sequence of $n$ security switches initially all set to ON under positional dependency constraints[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **State Definition & Transition:**
   - Let $F(n)$ denote moves to turn off $n$ ON switches.
   - Turning off switch $n$ requires switch $n-1$ to remain ON while switches $1 \dots n-2$ are turned OFF[cite: 1].
2. **Recurrence Relation:**
   $$F(n) = F(n-1) + 2 F(n-2) + 1$$
   with base conditions $F(1) = 1$ and $F(2) = 2$.
3. **Closed-Form Representation:**
   $$F(n) = \left\lfloor \frac{2^{n+1}}{3} \right\rfloor$$
4. **Justification:** The operational constraints match reflected binary Gray code inversions (Baguenaudier puzzle), ensuring every state toggle is unique and minimal.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n)$** iterative computation (or **$O(2^n)$** if tracing all state toggles).
- **Auxiliary Space Complexity:** **$O(1)$** auxiliary space using iterative state updates.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 5` | Security Switches Solver | Gray Code / Recurrence | **$O(1)$** | **$O(n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026

---
