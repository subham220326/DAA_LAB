# 🔄 DAA Lab 01


___________________________________
Q3:Bubble Sort Performance Analysis
___________________________________


-------------------------------------

## 📌 Overview
This repository contains the C programming implementation for the **Bubble Sort Analysis** of our DAA Lab-01 assignment. The objective is to evaluate and compare the time complexity of the standard (Unoptimized) Bubble Sort against the Optimized Bubble Sort by tracking the exact number of array comparisons made during execution.

The program feeds an array of `n = 50` elements into both algorithms under three distinct scenarios: Best Case (already sorted), Worst Case (reverse sorted), and Average Case (randomly generated).

## ⚙️ Algorithmic Logic

Both algorithms rely on repeatedly swapping adjacent elements if they are in the wrong order. However, their termination conditions differ:

1. **Unoptimized Bubble Sort:** Runs completely through its `O(n^2)` nested loops no matter what. It lacks the ability to recognize if the array is already sorted.
2. **Optimized Bubble Sort:** Introduces a `swapped` boolean flag. If the inner loop finishes a full pass without making a single swap, the algorithm knows the array is fully sorted and breaks out early, saving unnecessary comparisons.

## I HAVE GIVEN BELOW THE OUTPUT AND ATTACHED A SVG FILE TO SHOW THE COMPARISION

### 📊 Experimental Data Output

| Array State (n = 50) | Scenario Type | Unoptimized Comparisons | Optimized Comparisons |
| :--- | :--- | :--- | :--- |
| **Already Sorted** | Best Case | 1,225 | **49** |
| **Reverse Sorted** | Worst Case | 1,225 | **1,225** |
| **Randomly Generated** | Average Case | 1,225 | **1,162** |
--------------------------------------

> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 July 2026  
