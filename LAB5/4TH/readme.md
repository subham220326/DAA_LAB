# 📈 DAA Lab 05
__________________________________
Q4: Heap Sort on File-Stored Random Elements
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 4** of our DAA Lab-05 assignment.
The objective is to generate $N$ random integers, store them in a file, construct a binary Max-Heap, execute an in-place **Heap Sort**, and persist the sorted output to `sorted_heap.txt`.

## ⚙️ Algorithmic Logic & Justification

1. **Max-Heap Construction:** Build a Max-Heap from the unsorted array bottom-up by calling `heapify` on all non-leaf nodes starting from index $\lfloor N/2 \rfloor - 1$ down to $0$.
2. **Iterative Root Extraction & Sift-Down:**
   - Swap the root element (maximum value) with the last element of the current heap boundary.
   - Decrement heap size by 1.
   - Call `heapify` on the root node to restore the max-heap property.
3. **File Stream Persistence:** The final sorted array is written directly into `sorted_heap.txt`.
4. **Justification:** Heap Sort guarantees $O(N \log N)$ worst-case runtime and performs in-place sorting without requiring extra auxiliary arrays.

---

## 📊 Complexity Analysis

- **Heap Construction Time:** **$O(N)$** (Sum of node heights $\sum_{h=0}^{\lfloor\log N\rfloor} \frac{N}{2^{h+1}} O(h) = O(N)$).
- **Extraction Phase Time:** $(N - 1) \times O(\log N) = \mathbf{O(N \log N)}$.
- **Total Time Complexity:** **$O(N \log N)$** across **Best**, **Average**, and **Worst** cases.
- **Auxiliary Space Complexity:** **$O(1)$** (Strictly in-place sorting).

-------------------------------------------

## 💻 Sample Execution & Output

Below is the computational summary for sorting file-based random records using Heap Sort.

### Performance Summary

| Input Source File | Total Records ($N$) | Algorithm | In-Place Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `input.txt` | $N = 100$ (Random integers) | Binary Max-Heap Sort | **$O(1)$** | **$O(N \log N)$** (Guaranteed) |

---  

Note: Execution completes successfully with status `Heap Sort completed. Output written to sorted_heap.txt`.

___________________________________________________________
> **Course:** Design and Analysis of Algorithms (DAA), Lab-05  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 28 August 2026
