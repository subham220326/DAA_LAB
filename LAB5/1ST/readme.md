# 📈 DAA Lab 05
__________________________________
Q1: Finding Median of N Numbers (Without Sorting)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 1** of our DAA Lab-05 assignment.
The objective is to compute the median of a list of $N$ numbers without sorting the entire array, achieving an expected linear time complexity using the Quickselect order-statistic algorithm.

## ⚙️ Algorithmic Logic & Justification

1. **Partitioning Strategy:** Choose a pivot element (e.g., Lomuto or Hoare partition scheme) and rearrange the array such that elements smaller than the pivot reside on its left and larger elements on its right.
2. **Target Index Determination:** For an array of size $N$, the median index is target index $k = \lfloor N / 2 \rfloor$.
3. **Pruned Recursion (Quickselect):**
   - If the partition index $pi == k$, the median is found at $arr[pi]$.
   - If $pi > k$, recurse only on the left subarray $(low \dots pi - 1)$.
   - If $pi < k$, recurse only on the right subarray $(pi + 1 \dots high)$.
4. **Justification:** Unlike sorting, which processes both partitions and takes $O(N \log N)$ time, Quickselect drops half the search space on average in each step, yielding a recurrence relation of $T(N) = T(N/2) + O(N) = O(N)$.

---

## 📊 Complexity Analysis

- **Average-Case Time Complexity:** **$O(N)$** (Linear expected time).
- **Worst-Case Time Complexity:** **$O(N^2)$** (Occurs when chosen pivots produce heavily unbalanced partitions).
- **Best-Case Time Complexity:** **$O(N)$**.
- **Auxiliary Space Complexity:** **$O(1)$** auxiliary space ($O(\log N)$ average call stack overhead).

-------------------------------------------

## 💻 Sample Execution & Output

Below is the computational output evaluating the median-finding algorithm on a sample unsorted list.

### Performance Summary

| Input Elements | Target Index ($N/2$) | Selection Method | Auxiliary Space | Time Complexity (Avg) |
| :--- | :--- | :--- | :--- | :--- |
| `[12, 3, 5, 7, 4, 19, 26]` ($N = 7$) | Index `3` | Quickselect Partitioning | $O(1)$ | **$O(N)$** |

---  

Note: Output yields `Median: 7`. The median is identified directly without performing a full array sort.

___________________________________________________________
> **Course:** Design and Analysis of Algorithms (DAA), Lab-05  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 28 August 2026
