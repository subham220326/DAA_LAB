# 📈 DAA Lab 05
__________________________________
Q2: Finding the K'th Smallest Element (Without Sorting)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 2** of our DAA Lab-05 assignment.
The objective is to find the $K$-th smallest element from an unsorted list of $N$ numbers in expected linear time without sorting the list.

## ⚙️ Algorithmic Logic & Justification

1. **Order Statistic Formulation:** The $K$-th smallest element corresponds to the element that would occupy index $k - 1$ in a 0-indexed sorted sequence.
2. **Lomuto Partition:** Partition the subarray around a chosen pivot, returning the finalized index position $pi$ of the pivot element.
3. **Rank Comparison:**
   - Compute the relative position $pos = pi - low$.
   - If $pos == k - 1$, the element $arr[pi]$ is the exact $K$-th smallest value.
   - If $pos > k - 1$, recursively search only the left partition.
   - If $pos < k - 1$, recursively search the right partition for the $(k - pos - 1)$-th smallest element.
4. **Justification:** Discarding one partition at every step reduces the average problem size by half, ensuring optimal $O(N)$ average runtime.

---

## 📊 Complexity Analysis

- **Average-Case Time Complexity:** **$O(N)$** (Expected linear search).
- **Worst-Case Time Complexity:** **$O(N^2)$** (Degenerate pivot selection).
- **Best-Case Time Complexity:** **$O(N)$**.
- **Auxiliary Space Complexity:** **$O(1)$** auxiliary space ($O(\log N)$ average call stack overhead).

-------------------------------------------

## 💻 Sample Execution & Output

Below is the computational output evaluating the $K$-th smallest selection algorithm on a sample unsorted list.

### Performance Summary

| Input Elements | Target Rank ($K$) | Selection Method | Auxiliary Space | Time Complexity (Avg) |
| :--- | :--- | :--- | :--- | :--- |
| `[7, 10, 4, 3, 20, 15]` ($N = 6$) | $K = 3$ | Quickselect (Rank-based) | $O(1)$ | **$O(N)$** |

---  

Note: Output yields `3-rd smallest element: 7`. The result is computed without running comparison-based sort routines.

___________________________________________________________
> **Course:** Design and Analysis of Algorithms (DAA), Lab-05  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 28 August 2026
