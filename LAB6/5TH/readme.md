# 📈 DAA Lab 06: Q5 — 1D Array Operations & Complexities
__________________________________
Q5: 1D Array Operations, In-Place Partitioning & Statistical Metrics
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 1** of Lab-06[cite: 1].
The objective is to implement and analyze 9 fundamental array operations on an unsorted input sequence of $n$ integer elements[cite: 1].

## ⚙️ Algorithmic Logic & Justification

1. **Linear Scans:** Max, First & Second Largest, Mean, Standard Deviation, and Reversal execute directly over the array in single passes without modification[cite: 1].
2. **Order Statistics:** Median and Mode employ comparison sorting/partitioning to group frequencies and access rank elements[cite: 1].
3. **Duplicate Elimination:** In-place unique-element compaction via sorted adjacent scanning[cite: 1].
4. **Pivot Partitioning:** Two-pointer modified Hoare-style partitioning placing elements $\ge \text{pivot}$ before elements $< \text{pivot}$[cite: 1].

---

## 📊 Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Method Applied |
| :--- | :--- | :--- | :--- |
| (i) Maximum Element[cite: 1] | **$O(n)$** | $O(1)$ | Single linear scan[cite: 1] |
| (ii) 1st & 2nd Largest[cite: 1] | **$O(n)$** | $O(1)$ | Dual-variable tracking in one pass[cite: 1] |
| (iii) Mean[cite: 1] | **$O(n)$** | $O(1)$ | Accumulative sum / $n$[cite: 1] |
| (iv) Median[cite: 1] | **$O(n \log n)$** / **$O(n)$** | $O(n)$ | Sort / Quickselect[cite: 1] |
| (v) Standard Deviation[cite: 1] | **$O(n)$** | $O(1)$ | Two-pass variance derivation[cite: 1] |
| (vi) Mode[cite: 1] | **$O(n \log n)$** | $O(n)$ | Sort + consecutive run-length scan[cite: 1] |
| (vii) Duplicate Removal[cite: 1] | **$O(n \log n)$** | $O(1)$ | Sort + two-pointer overwrite[cite: 1] |
| (viii) Array Reversal[cite: 1] | **$O(n)$** | $O(1)$ | Two-pointer swap ($\lfloor n/2 \rfloor$ swaps)[cite: 1] |
| (ix) Pivot Partition[cite: 1] | **$O(n)$** | $O(1)$ | Two-pointer in-place swap[cite: 1] |

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Array | Operations Tested | Total Space |
| :--- | :--- | :--- |
| `{12, 3, 5, 7, 19, 3, 5, 29, 14}` ($n = 9$) | 9 Core Primitive Operations[cite: 1] | $O(1)$ In-place for mutations[cite: 1] |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06[cite: 1]  
> **Instructor:** Dr. Ajaya Kumar Dash[cite: 1]  
> **Date:** 31 August 2026[cite: 1]
