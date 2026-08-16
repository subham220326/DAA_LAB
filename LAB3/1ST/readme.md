# 📈 DAA Lab 03
__________________________________
Q1: Binary vs Ternary Search
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 1** of our DAA Lab-03 assignment.
The objective is to search for an element $x$ in a sorted list of size $n$ using both binary and ternary search algorithms[cite: 1]. In binary search, the list is divided into two nearly equal halves, whereas in ternary search, it is divided into three nearly equal intervals[cite: 1]. The program empirically validates why binary search performs better in the worst-case scenario[cite: 1].

## ⚙️ Algorithmic Logic & Justification

Through asymptotic analysis and empirical comparison, binary search is proven more efficient:

1. **Binary Search:** Divides the array into 2 parts. Maximum comparisons in worst case: $\approx \log_2 n$.
2. **Ternary Search:** Divides the array into 3 parts. Maximum depth is $\log_3 n$, but each step requires up to 2 comparisons.
3. **Justification:** Since $2 \log_3 n > \log_2 n$ for all $n > 1$, ternary search performs more comparisons overall despite making fewer recursive splits.

-------------------------------------------

## 💻 Given the output below showing the execution of both searches

Below is the computational output evaluating both algorithms searching for a worst-case element in an array of size $n = 100$.

### Performance Comparison (Array Size $n = 100$)

| Target Element | Search Algorithm | Search Space Splits | Total Comparisons |
| :--- | :--- | :--- | :--- |
| **99 (Last Element)** | Binary Search | 7 | **7** |
| **99 (Last Element)** | Ternary Search | 5 | **10** |

---   

Note: Ternary search reduces the array size faster but costs more comparisons per level.
For $n=100$, Binary takes max 7 comparisons.
For $n=100$, Ternary takes max 10 comparisons.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
