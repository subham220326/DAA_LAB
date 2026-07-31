# 📈 DAA Lab 01
__________________________________
01: Order of Growth Analysis
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 1** of our DAA Lab-01 assignment.
The objective is to evaluate a given set of mathematical functions and place them in a list by increasing order of asymptotic growth for sufficiently large values of `n`.
Instead of using external graphing libraries, this program computes the raw mathematical values of each function for increasing values of `n` 
(from 10 to 50) and outputs a cleanly formatted data table directly to the console.


## 🔢 The Functions (From Slowest to Fastest Growing)

Through asymptotic analysis (Big-O notation) and empirical data generation, the functions are ordered as follows:

1. `log2(n)` *(Logarithmic - Most Efficient)*
2. `12√n` & `50n^0.5` *(Square Root / Tied)*
3. `n^0.51` *(Fractional Polynomial)*
4. `2^32 * n` *(Linear - Massive constant, but scales linearly)*
5. `n * log2(n)` *(Linearithmic)*
6. `100n^2 + 6n` & `n^2 - 324` *(Quadratic / Tied)*
7. `2n^3` *(Cubic)*
8. `n^log2(n)` *(Quasi-polynomial)*
9. `3^n` *(Exponential - Least Efficient)*

-------------------------------------------

## 💻 Given the output below and attached a SVG file showing the growth of function with respect to input


Evaluating Order of Growth for increasing 'n'...

n     | log2(n)      | 12*sqrt(n)   | 50*n^0.5     | n^0.51       | n*log2(n)   
-----------------------------------------------------------------------
10    | 3.32         | 37.95        | 158.11       | 3.24         | 33.22       
20    | 4.32         | 53.67        | 223.61       | 4.61         | 86.44       
30    | 4.91         | 65.73        | 273.86       | 5.67         | 147.21      
40    | 5.32         | 75.89        | 316.23       | 6.56         | 212.88      
50    | 5.64         | 84.85        | 353.55       | 7.35         | 282.19      

n     | 100n^2 + 6n     | n^2 - 324       | 2n^3            | n^log2(n)       | 3^n            
----------------------------------------------------------------------------------------
10    | 10060           | -224            | 2000            | 2.10e+03        | 5.90e+04       
20    | 40120           | 76              | 16000           | 4.20e+05        | 3.49e+09       
30    | 90180           | 576             | 54000           | 1.77e+07        | 2.06e+14       
40    | 160240          | 1276            | 128000          | 3.36e+08        | 1.22e+19       
50    | 250300          | 2176            | 250000          | 3.88e+09        | 7.18e+23       

Note: 2^32 * n scales linearly but starts huge.
For n=10, 2^32 * n = 42949672960
For n=20, 2^32 * n = 85899345920
For n=30, 2^32 * n = 128849018880



___________________________________________________________
> **Course:** Design and Analysis of Algorithm (DAA), Lab-01  
> **Instructor:** Dr. Ajaya Kumar Dash  
> **Date:** 31 July 2026 
