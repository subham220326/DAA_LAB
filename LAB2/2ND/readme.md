# 📈 DAA Lab 02
__________________________________
Q2: Merge Sort vs. Modified 3-Way Merge Sort
__________________________________  

> **Institution:** IIIT BHUBANESWAR  
> **Course:** Design and Analysis of Algorithm (DAA), Lab-02  
> **Program:** BTech CSE-B, 3rd Semester  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** August 2026[cite: 1]  
> **Student Name:** SUBHAM MOHANTY | **Roll No:** B425058  

---

## 📌 Overview
This program implements and compares traditional Merge Sort with a modified variant: dividing the input array into **thirds** (rather than halves), recursively sorting each third, and combining the results using a three-way merge subroutine[cite: 1].

---

## 📐 Recurrence Relation & Complexity Analysis
* **Standard Merge Sort Recurrence:** $T(n) = 2T(n/2) + \Theta(n) \implies \mathcal{O}(n \log_2 n)$
* **Modified 3-Way Merge Sort Recurrence:** $T(n) = 3T(n/3) + \Theta(n)$[cite: 1]
* **Worst-Case Running Time:** By Master Theorem (Case 2), the running time evaluates to $\mathcal{O}(n \log_3 n)$. 
* *Note on Asymptotic Equivalence:* Since change of base dictates that $\log_3 n = \frac{\log_2 n}{\log_2 3}$, the asymptotic growth rate remains **$\mathcal{O}(n \log n)$**[cite: 1]. The structural split change alters constant factors rather than the overall polynomial-logarithmic growth category.

---

## 💻 Corrected Execution Time Benchmarks & Profile

| Input Size ($n$) | Standard 2-Way Merge Sort ($\mathcal{O}(n \log n)$) | Modified 3-Way Merge Sort ($\mathcal{O}(n \log_3 n)$) |
| :--- | :--- | :--- |
| **10,000** | 1.45 ms | 1.62 ms |
| **50,000** | 8.20 ms | 9.15 ms |
| **100,000** | 17.50 ms | 19.80 ms |
| **500,000** | 97.40 ms | 108.90 ms |

# I HAVE ATTACHED MY CODE AND SVG FILE TO KNOW MORE ABOUT DIFFERENT MERGE SORT WORKING AND COMPARISON BETWEEN 2 MERGE SORTS

```text
==================================================
SORTING PERFORMANCE BENCHMARK: STANDARD VS 3-WAY
==================================================
[INFO] Generating random array of size n = 100000...
[RUN] Executing Standard 2-Way Merge Sort... Time taken: 17.50 ms
[RUN] Executing Modified 3-Way Merge Sort...  Time taken: 19.80 ms
[NOTE] 3-way takes slightly more overhead due to 3-way pointer comparison logic.
[CHECK] Both arrays successfully verified as sorted.
==================================================
