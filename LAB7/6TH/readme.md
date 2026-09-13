# Q6: The Best Time to Be Alive
__________________________________
Q6: Maximum Overlapping Intervals (Sweep-Line Algorithm)
__________________________________

---

## 📌 Overview
This section contains the implementation and complexity analysis for **Question 6** of Lab-07[cite: 1].
The objective is to identify the calendar year during which the maximum number of prominent scientists were simultaneously alive, given their birth and death years[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Event Transformation:** Convert each person's lifespan $[B_i, D_i]$ into two discrete timestamp points[cite: 1]:
   - Birth: `(year = B_i, delta = +1)`
   - Death: `(year = D_i, delta = -1)`
2. **Boundary Ordering:** If person A dies in the same year person B is born, death must be registered before birth[cite: 1]. In sort criteria: when `year` ties occur, the `-1` event precedes the `+1` event.
3. **Sweep-Line Traversal:**
   - Sort the $2n$ events chronologically.
   - Maintain a running tally: `current_alive += event.delta`.
   - Update `max_alive` and store the optimal year whenever `current_alive` reaches a new peak.
4. **Justification:** Decoupling intervals into sorted point endpoints converts an $O(n^2)$ pairwise interval intersection problem into a linear scan.

---

## 📊 Complexity Analysis

- **Time Complexity:** **$O(n \log n)$** driven by comparison-based sorting of $2n$ timeline events.
- **Auxiliary Space Complexity:** **$O(n)$** to store event coordinate structs.

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input ($n$) | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `n = 1000` | Interval Sweep-Line | Event Point Sorting | **$O(n)$** | **$O(n \log n)$** |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-07  
> **Instructor:** Dr. Ajaya Kumar Dash
> **Date:** 08 September 2026

---
