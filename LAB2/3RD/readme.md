# 📈 DAA Lab 02
__________________________________
Q3: Merging $k$ Sorted Arrays ($k$ arrays, $n$ elements each)
__________________________________  

> **Institution:** IIIT BHUBANESWAR  
> **Course:** Design and Analysis of Algorithm (DAA), Lab-02  
> **Program:** BTech CSE-B, 3rd Semester  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 07 August 2026
> **Student Name:** SUBHAM MOHANTY | **Roll No:** B425058  

---

## 📌 Overview
Given $k$ sorted arrays, each containing $n$ elements, this program validates and benchmarks two distinct algorithmic approaches to combine them into a single sorted array of $kn$ elements[cite: 1].

---

## ⚙️ Method Comparison & Complexities

### [Method 1] Sequential Iterative Merging
* **Description:** Repeatedly merge the first two arrays, merge the result with the third array, and continue sequentially until the $k^{\text{th}}$ final array is integrated[cite: 1].
* **Worst-Case Running Time:** **$\mathcal{O}(k^2 n)$**

### [Method 2] Pairwise Divide-and-Conquer Merging
* **Description:** Divide the $k$ arrays into $k/2$ pairs, use the merge subroutine to combine each pair (yielding $k/2$ sorted length-$2n$ arrays), and repeat hierarchically until a single length-$kn$ sorted array remains[cite: 1].
* **Worst-Case Running Time:** **$\mathcal{O}(kn \log k)$**

---

### 💻 Simulated Console Output & Execution Comparison

| Parameters (`k` arrays, `n` elements) | Method 1: Sequential `O(k^2 n)` | Method 2: Divide & Conquer `O(kn log k)` |
| :--- | :--- | :--- |
| **`k = 10`, `n = 1000`** | 2.15 ms | 0.85 ms |
| **`k = 50`, `n = 1000`** | 48.60 ms | 5.20 ms |
| **`k = 100`, `n = 1000`** | 194.30 ms | 11.40 ms |

```text
==================================================
MERGING K SORTED ARRAYS BENCHMARK (k = 50, n = 1000)
==================================================
[RUN] Method 1 (Sequential Merging)... 
      -> Time Elapsed: 48.60 ms [Complexity: O(k^2 * n)]
[RUN] Method 2 (Pairwise D&C Merging)... 
      -> Time Elapsed: 5.20 ms  [Complexity: O(k * n * log k)]
[VERIFY] Both methods yielded identical sorted sequences of length 50000.
==================================================
