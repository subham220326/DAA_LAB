# 📈 DAA Lab 03
__________________________________
Q2: Search the Defective Coin
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 2** of our DAA Lab-03 assignment.
The objective is to act as a quality-control engineer and find one possible defective, lighter coin out of $n$ identical coins. Using a simulated balance weighing scale, the program implements a divide-and-conquer algorithm to locate the defective coin (or report if none exists) in $O(\log_2 n + c)$ time[cite: 1].

## ⚙️ The Divide and Conquer Strategy

To achieve the strict $O(\log n)$ time complexity:

1. **Divide:** Split the pile of coins into two equal halves. (If $n$ is odd, leave one coin aside).
2. **Conquer (Weigh):** Place the two halves on the balance scale.
3. **Decision:** 
   * If they balance perfectly, the defective coin is the one left aside (or there is no defective coin).
   * If one side is lighter, recursively repeat the process on the lighter pile.

-------------------------------------------

## 💻 Given the output below showing the simulated balance scale execution

Below is the computational output tracking the weighing scale simulation for $n = 16$ coins, where the coin at index 11 is defective (lighter).

### Weighing Scale Simulation Steps

| Step | Coins on Left Pan | Coins on Right Pan | Scale Result | Action Taken |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Indices 0 to 7 | Indices 8 to 15 | Right is Lighter | Discard Left Half |
| **2** | Indices 8 to 11 | Indices 12 to 15 | Left is Lighter | Discard Right Half |
| **3** | Indices 8 to 9 | Indices 10 to 11 | Right is Lighter | Discard Left Half |
| **4** | Index 10 | Index 11 | Right is Lighter | **Defective Coin Found at 11** |

---   

Note: The divide and conquer approach guarantees finding the coin extremely fast.
For $n=16$, maximum weighings = 4.
For $n=1024$, maximum weighings = 10.

___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-03  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 14 August 2026
