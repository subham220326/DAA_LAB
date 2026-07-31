# 🕵️‍♂️ DAA Lab 01

_________________________________
# Q6: Element Uniqueness Analysis
_________________________________


---------------------------------

## 📌 Overview
This repository contains the C programming implementation for the **Element Uniqueness** problem of our DAA Lab-01 assignment. The objective is to determine whether an array contains any duplicate values or if every element is entirely unique.

To demonstrate algorithmic analysis, this program solves the problem using two vastly different approaches—a Brute Force `O(n^2)` algorithm and an Optimized Frequency Array `O(n)` algorithm—and counts the operations to highlight the efficiency gap.

## ⚙️ Algorithmic Logic

1. **Brute Force `O(n^2)`:** The naive approach uses nested loops to compare every single element against every subsequent element in the array. It requires no extra memory (`O(1)` space), but takes an enormous amount of time for large arrays.
2. **Optimized Hash/Frequency `O(n)`:** This approach leverages the "Space-Time Tradeoff". By allocating a small amount of extra memory (a `seen` boolean array), we can iterate through the main array just once. For each element, we check if its corresponding index in the `seen` array is already flagged. If it is, we found a duplicate instantly!


## THE OUTPUT OF THIS PROGRAM IS GIVEN BELOW 


---

### 📊 Performance Comparison (Array Size n = 10)

**Target:** Identify if the array `[12, 45, 7, 89, 23, 56, 34, 91, 18, 7]` contains duplicate values.

| Search Algorithm | Asymptotic Time Complexity | Asymptotic Space Complexity | Total Operations (Steps) |
| :--- | :--- | :--- | :--- |
| **Frequency/Hash Array** | `O(n)` | `O(k)` | **10** |

---



-----------------------------------

> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 July 2026  
