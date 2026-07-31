# 🎯 DAA Lab 01


_______________________________
# Q5: Find the Partition Point
_______________________________

------------------------------

## 📌 Overview
This repository contains the C programming implementation for the **Partition Point** problem of our DAA Lab-01 assignment. The objective is to find the exact index where an array of `0`s transitions into `1`s (e.g., `0, 0, 0, 1, 1`).

To demonstrate algorithmic optimization, this program solves the problem using two different approaches—a naive Linear Search `O(n)` and an optimized Binary Search `O(log n)`—and compares the exact number of operations required by each.

## ⚙️ Algorithmic Logic

Because the array is already sorted (all 0s naturally come before all 1s), we do not need to check every single element:
1. **Binary Search `O(log n)`:** We jump to the middle of the array. If we see a `1`, we check the element immediately to its left. If the left element is a `0`, we have found the exact transition point! 
2. If the middle is a `0`, we know the transition must happen somewhere in the right half, so we discard the left half entirely.
3. If the middle is a `1` but the left element is *also* a `1*, we haven't found the start yet, so we discard the right half.


## THE OUTPUT OF THIS PROGRAM IS GIVEN BELOW

---

### 📊 Performance Comparison (Array Size n = 16)


| Search Algorithm | Asymptotic Complexity | Target Index Identified | Total Operations (Steps) |
| :--- | :--- | :--- | :--- |
| **Optimized Binary Search** | `O(log n)` | 11 | **3** |

---

------------------------------

> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** July 2026  
