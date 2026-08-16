# 📈 DAA Lab 03
__________________________________
Q3: Max and Min using D&C Approach
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 3** of our DAA Lab-03 assignment.
The objective is to find both the maximum and minimum elements in an array of size $n$ using a divide-and-conquer approach[cite: 1]. The program must ensure that the total number of element comparisons is strictly bounded by $\frac{3n}{2}$[cite: 1].

## ⚙️ The $\frac{3n}{2}$ Comparison Strategy

The naive approach requires $2n$ comparisons. The divide and conquer approach optimizes this:

1. **Divide:** Split the array into two halves recursively until segments contain only 1 or 2 elements.
2. **Base Case:** For 2 elements, compare them once. Assign the larger to Max and the smaller to Min. (1 comparison).
3. **Combine:** Compare the left-half Min with the right-half Min (1 comparison), and the left-half Max with the right-half Max (1 comparison).
4. **Result:** Total comparisons equal exactly $\frac{3n}{2} - 2$, safely bounding it below $\frac{3n}{2}$[cite: 1].

-------------------------------------------

## 💻 Given the output below showing the comparison tracking

Below is the computational output evaluating an array of 16 random integers to find the extremes while tracking exact comparison counts.

### Execution on Array Size $n = 16$

| Metric | Value |
| :--- | :--- |
| **Input Array** | `[34, 12, 9, 88, 54, 2, 76, 91, 15, 33, 41, 7, 60, 23, 99, 5]` |
| **Minimum Found** | 2 |
| **Maximum Found** | 99 |
| **Theoretical Limit ($3n/2$)**| 24 |
| **Actual Comparisons Made** | **22** |

---   

Note: The algorithm mathematically bounds the worst-case scenario.
For $n=16$, $3(16)/2 = 24$. The actual comparisons were 22.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
