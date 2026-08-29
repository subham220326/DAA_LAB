# 📈 DAA Lab 05
__________________________________
Q3: Quick Sort on File-Stored Random Elements
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 3** of our DAA Lab-05 assignment.
The objective is to generate $N$ random integers, store them in a file (`input.txt`), load and sort them using the divide-and-conquer **Quick Sort** algorithm, and save the sorted output to `sorted_quick.txt`.

## ⚙️ Algorithmic Logic & Justification

1. **Data Generation & I/O Stream:** Uniformly distributed random integers are generated using `rand()` and written to `input.txt`. The program reads the integers into a dynamic array.
2. **Divide-and-Conquer Partitioning:**
   - Select a pivot element from the subarray.
   - Rearrange elements such that all values smaller than the pivot are placed to its left and greater values to its right.
3. **Recursive Subproblem Solving:** Recursively apply Quick Sort to the left subarray $(low \dots pi - 1)$ and right subarray $(pi + 1 \dots high)$.
4. **File Persistence:** The completely sorted array is written out sequentially to `sorted_quick.txt`.

---

## 📊 Complexity Analysis

- **Best-Case Time Complexity:** **$O(N \log N)$** (Occurs when the pivot divides the array into two equal halves).
- **Average-Case Time Complexity:** **$O(N \log N)$**.
- **Worst-Case Time Complexity:** **$O(N^2)$** (Occurs when the pivot is consistently the smallest or largest element).
- **Auxiliary Space Complexity:** **$O(\log N)$** stack space in average case ($O(N)$ in worst case).

-------------------------------------------

## 💻 Sample Execution & Output

Below is the computational summary for sorting file-based random records using Quick Sort.

### Performance Summary

| Input Source File | Total Records ($N$) | Algorithm | Output Target File | Time Complexity (Avg) |
| :--- | :--- | :--- | :--- | :--- |
| `input.txt` | $N = 100$ (Random integers) | Divide-and-Conquer Quick Sort | `sorted_quick.txt` | **$O(N \log N)$** |

---  

Note: Execution completes successfully with status `Quick Sort completed. Output written to sorted_quick.txt`.

___________________________________________________________
> **Course:** Design and Analysis of Algorithms (DAA), Lab-05  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 28 August 2026
