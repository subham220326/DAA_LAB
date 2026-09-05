# 📈 DAA Lab 06: Q5 — 1D Array Operations & Complexities
__________________________________
Q5: 1D Array Operations, In-Place Partitioning & Statistical Metrics
__________________________________

---

## 📌 Overview
This repository contains the C programming implementation and complexity analysis for **Question 5** of Lab-06.
The objective is to implement and analyze 9 fundamental array operations on an unsorted input sequence of $n$ integer elements.

## ⚙️ Algorithmic Logic & Justification

1. **Linear Scans:** Max, First & Second Largest, Mean, Standard Deviation, and Reversal execute directly over the array in single passes without modification.
2. **Order Statistics:** Median and Mode employ comparison sorting/partitioning to group frequencies and access rank elements.
3. **Duplicate Elimination:** In-place unique-element compaction via sorted adjacent scanning.
4. **Pivot Partitioning:** Two-pointer modified Hoare-style partitioning placing elements $\ge \text{pivot}$ before elements $< \text{pivot}$.
---

## 📊 Complexity Analysis

| Operation | Time Complexity | Auxiliary Space | Method Applied |
| :--- | :--- | :--- | :--- |
| (i) Maximum Element | **$O(n)$** | $O(1)$ | Single linear scan |
| (ii) 1st & 2nd Largest[cite: 1] | **$O(n)$** | $O(1)$ | Dual-variable tracking in one pass |
| (iii) Mean | **$O(n)$** | $O(1)$ | Accumulative sum / $n$ |
| (iv) Median | **$O(n \log n)$** / **$O(n)$** | $O(n)$ | Sort / Quickselect |
| (v) Standard Deviation | **$O(n)$** | $O(1)$ | Two-pass variance derivation |
| (vi) Mode | **$O(n \log n)$** | $O(n)$ | Sort + consecutive run-length scan |
| (vii) Duplicate Removal | **$O(n \log n)$** | $O(1)$ | Sort + two-pointer overwrite |
| (viii) Array Reversal | **$O(n)$** | $O(1)$ | Two-pointer swap ($\lfloor n/2 \rfloor$ swaps) |
| (ix) Pivot Partition | **$O(n)$** | $O(1)$ | Two-pointer in-place swap[ |

-------------------------------------------

## 💻 Sample Execution & Output

### Performance Summary

| Input Array | Operations Tested | Total Space |
| :--- | :--- | :--- |
| `{12, 3, 5, 7, 19, 3, 5, 29, 14}` ($n = 9$) | 9 Core Primitive Operations[cite: 1] | $O(1)$ In-place for mutations |

---

> **Course:** Design and Analysis of Algorithms (DAA), Lab-06
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 August 2026
