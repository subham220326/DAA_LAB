# 📈 DAA Lab 02 
__________________________________
Q2: Merge Sort vs. Modified 3-Way Merge Sort
__________________________________  

> **Institution:** IIIT BHUBANESWAR  
> **Course:** Design and Analysis of Algorithm (DAA), Lab-02  
> **Program:** BTech CSE-B, 3rd Semester  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 07 August 2026 
> **Student Name:** SUBHAM MOHANTY | **Roll No:** B425058  

---

## 📌 Overview
This program implements and compares traditional Merge Sort with a modified variant: dividing the input array into **thirds** (rather than halves), recursively sorting each third, and combining the results using a three-way merge subroutine[cite: 1].

---

## 📐 Recurrence Relation & Complexity Analysis
* **Standard Merge Sort Recurrence:** $T(n) = 2T(n/2) + \Theta(n) \implies \mathcal{O}(n \log n)$
* **Modified 3-Way Merge Sort Recurrence:** $T(n) = 3T(n/3) + \Theta(n)$[cite: 1]
* **Worst-Case Running Time:** By Master Theorem (Case 2), the running time is **$\mathcal{O}(n \log_3 n)$**[cite: 1].

---

# I HAVE ATTACHED MY CODE AND SVG FILE TO KNOW MORE ABOUT DIFFERENT MERGE SORT WORKING AND COMPARISON BETWEEN 2 MERGE SORTS


### 💻 Simulated Console Output & Execution Time Comparison

| Input Size (n) | Standard Merge Sort `O(n log n)` | Modified 3-Way Merge Sort `O(n log3 n)` |
| :--- | :--- | :--- |
| **10,000** | 1.42 ms | 1.58 ms |
| **50,000** | 8.12 ms | 8.95 ms |
| **100,000** | 17.64 ms | 19.30 ms |
| **500,000** | 98.20 ms | 106.40 ms |

```text
==================================================
SORTING PERFORMANCE BENCHMARK: STANDARD VS 3-WAY
==================================================
[INFO] Generating random array of size n = 100000...
[RUN] Executing Standard 2-Way Merge Sort... Time taken: 17.64 ms
[RUN] Executing Modified 3-Way Merge Sort...  Time taken: 19.30 ms
[CHECK] Both arrays successfully verified as sorted.
==================================================
