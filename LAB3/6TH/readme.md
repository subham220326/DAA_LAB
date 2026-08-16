# 📈 DAA Lab 03
__________________________________
Q6: Use of Loop Invariants in Sorting
__________________________________ 

---

## 📌 Overview
This repository contains the pseudocode and C programming implementation for **Question 6** of our DAA Lab-03 assignment.
The objective is to implement a sorting algorithm (Selection Sort) that finds the smallest element and swaps it with the front, and to formally prove its correctness using loop invariants: initialisation, maintenance, and termination[cite: 1].

## ⚙️ The Loop Invariant Proof

The algorithm maintains a strict loop invariant for the subarray $A[1 \dots i-1]$:
* **Initialisation:** Before the loop starts ($i=1$), the subarray $A[1 \dots 0]$ is empty, making it trivially sorted[cite: 1].
* **Maintenance:** At each step $i$, the algorithm finds the absolute minimum in the remaining unsorted portion $A[i \dots n]$ and places it at position $i$[cite: 1]. The subarray $A[1 \dots i]$ remains sorted.
* **Termination:** The loop only needs to run for the first $(n-1)$ elements[cite: 1]. When $i = n$, the subarray $A[1 \dots n-1]$ contains the smallest elements sorted, meaning the single remaining element in $A[n]$ must be the largest.
* **Running Time:** $\Theta(n^2)$ for both best and worst cases, as it always scans the entire remaining array[cite: 1].

-------------------------------------------

## 💻 Given the output below showing the invariant maintenance

Below is the computational output demonstrating how the sorted boundary grows sequentially during execution.

### Array State at Each Iteration

| Step $i$ | Sorted Subarray (Invariant) | Unsorted Subarray |
| :--- | :--- | :--- |
| **0 (Init)**| `[]` | `[29, 10, 14, 37, 13]` |
| **1** | `[10]` | `[29, 14, 37, 13]` |
| **2** | `[10, 13]` | `[14, 37, 29]` |
| **3** | `[10, 13, 14]` | `[37, 29]` |
| **4** | `[10, 13, 14, 29]` | `[37]` |

---   

Note: At step 4 ($n-1$), the algorithm terminates safely because element 37 is naturally in its correct final position.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
