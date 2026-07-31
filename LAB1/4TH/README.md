# 🗼 DAA Lab 01

______________________
#Q4 : Tower of Hanoi
______________________


--------------------------

## 📌 Overview
This repository contains the C programming implementation for the **Tower of Hanoi** problem for our DAA Lab-01 assignment. The objective is twofold:
1. Implement the recursive algorithm to physically trace the exact steps required to solve the puzzle for a small number of disks (`n = 3`).
2. Mathematically evaluate the time complexity by calculating the total moves required for larger inputs (up to `n = 20`) to demonstrate $O(2^n)$ exponential growth.

## ⚙️ Algorithmic Logic

The puzzle is solved using a classic divide-and-conquer recursive approach:
1. **Base Case:** If `n = 1`, simply move the disk from Source to Destination.
2. **Recursive Steps:** 
   - Move the top `n - 1` disks from the Source peg to the Auxiliary peg.
   - Move the `n`th (largest) disk from the Source peg directly to the Destination peg.
   - Move the `n - 1` disks from the Auxiliary peg to the Destination peg.

The recurrence relation for the number of moves is **M(n) = 2M(n-1) + 1**, which resolves to the mathematical formula **M(n) = 2^n - 1**.


##  THE OUTPUT OF THIS PROGRAM IS GIVEN BELOW AND I HAVE ATTACHED A SVG FILE FOR THE GRAPH TO DEMONSTRATE THE GROWTH OF FUNCTION WITH THE INPUT


### 🧩 1. Step-by-Step Execution (n = 3 Disks)

| Step Number | Disk Moved | Source Peg | Destination Peg |
| :--- | :--- | :--- | :--- |
| **Step 1** | Disk 1 | A | C |
| **Step 2** | Disk 2 | A | B |
| **Step 3** | Disk 1 | C | B |
| **Step 4** | Disk 3 | A | C |
| **Step 5** | Disk 1 | B | A |
| **Step 6** | Disk 2 | B | C |
| **Step 7** | Disk 1 | A | C |

*(Formula Check: 2^3 - 1 = 8 - 1 = 7 exact moves)*

---

### 📈 2. Exponential Growth Tracker (O(2^n))

| Total Disks (n) | Required Moves (2^n - 1) |
| :--- | :--- |
| **3** | 7 |
| **4** | 15 |
| **5** | 31 |
| **6** | 63 |
| **7** | 127 |
| **8** | 255 |
| **9** | 511 |
| **10** | 1,023 |
| **15** | 32,767 |
| **20** | 1,048,575 |

---


### 🖥️ Terminal Output Snippet (n = 3 Disks)

```text
[INITIAL STATE]
  ***           |               |       
 *****          |               |       
*******         |               |       
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 1]: Moving Disk 1 from Peg A to Peg C
   |            |               |       
 *****          |               |       
*******         |              ***      
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 2]: Moving Disk 2 from Peg A to Peg B
   |            |               |       
   |            |               |       
*******       *****            ***      
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 3]: Moving Disk 1 from Peg C to Peg B
   |            |               |       
   |             ***            |       
*******       *****             |       
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 4]: Moving Disk 3 from Peg A to Peg C
   |            |               |       
   |             ***            |       
   |          *****            *******  
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 5]: Moving Disk 1 from Peg B to Peg A
   |            |               |       
   |            |               |       
  ***         *****            *******  
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 6]: Moving Disk 2 from Peg B to Peg C
   |            |               |       
   |            |             *****     
  ***           |            *******    
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

[Step 7]: Moving Disk 1 from Peg A to Peg C
   |            |              ***      
   |            |             *****     
   |            |            *******    
-------         -------         -------
 Peg A           Peg B           Peg C 
===================================================

Puzzle solved in 7 steps!

--------------------------


> **Instructor:** Dr. Ajaya Kumar Dash  
>  **Date:** 31 July 2026  
