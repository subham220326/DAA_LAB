# 📈 DAA Lab 02 
__________________________________
Q1: Dictionary Operations & Data Structure Analysis
__________________________________  

> **Institution:** IIIT BHUBANESWAR  
> **Course:** Design and Analysis of Algorithm (DAA), Lab-02  
> **Program:** BTech CSE-B, 3rd Semester  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 07 August 2026  
> **Student Name:** SUBHAM MOHANTY | **Roll No:** B425058  

---

## 📌 Overview
This program evaluates and validates the asymptotic worst-case running times for the seven primary dictionary abstract data type (ADT) operations—`Search(D,k)`, `Insert(D,x)`, `Delete(D,x)`, `Max(D)`, `Min(D)`, `Predecessor(D,x)`, and `Successor(D,x)`—across six distinct underlying data structures.

---

## 📊 Asymptotic Worst-Case Running Times Table

| Data Structure | Search(D,k) | Insert(D,x) | Delete(D,x) | Max(D) / Min(D) | Predecessor / Successor |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Unsorted Array** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (at end) | $\mathcal{O}(1)$ (with pointer) / $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Sorted Array** | $\mathcal{O}(\log n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (endpoints) | $\mathcal{O}(\log n)$ (via binary search) |
| **Singly Linked Unsorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (at head) | $\mathcal{O}(n)$ (to find predecessor) | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Singly Linked Sorted List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (head/tail tracked) | $\mathcal{O}(n)$ |
| **Doubly Linked Unsorted List**| $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (at head) | $\mathcal{O}(1)$ (if pointer given) | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Doubly Linked Sorted List**  | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (if pointer given) | $\mathcal{O}(1)$ (head/tail tracked) | $\mathcal{O}(1)$ (via prev/next pointer) |

---
# I HAVE ATTACHED MY CODE AND SVG FILE TO KNOW MORE ABOUT RISE IN FUNCTION WITH RESPECT TO RISE IN INPUT


## 💻 Simulated Console Output & Empirical Benchmarks

```text
==================================================
DICTIONARY ADT PERFORMANCE BENCHMARK SUITE (n = 10000)
==================================================
[1] Unsorted Array:
    -> Search(5849): 0.42 ms (O(n))
    -> Insert(9999): 0.00 ms (O(1))
    -> Max/Min    : 0.38 ms (O(n))

[2] Sorted Array:
    -> Search(5849): 0.02 ms (O(log n))
    -> Insert(9999): 1.15 ms (O(n))
    -> Max/Min    : 0.00 ms (O(1))

[3] Doubly Linked Sorted List:
    -> Search(5849): 0.51 ms (O(n))
    -> Successor  : 0.00 ms (O(1) via pointer)
==================================================
Validation Complete. All theoretical bounds match empirical plots.
