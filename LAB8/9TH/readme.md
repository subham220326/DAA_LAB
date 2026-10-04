# Q9: Collatz Conjecture

---

## Q9: Analyze Collatz Trajectories over an Interval

---

## 📌 Overview

This section contains the implementation and analysis for **Question 9** of Lab-08.

The Collatz Conjecture defines the following recurrence for every strictly positive integer `n`:

$$\
T(n)=\
\begin{cases}\
n/2, & \text{if } n \text{ is even}\\\
3n+1, & \text{if } n \text{ is odd}\
\end{cases}\
$$

The process repeatedly applies the function until the value reaches `1`.

Although it is conjectured that every positive integer eventually reaches `1`, the statement remains an **open unsolved problem**.

The assignment asks for a modular C program that analyzes trajectories for starting values across an interval `[a,b]`.

## ⚙️ Algorithmic Logic & Justification

1. Accept the starting interval `[a,b]`.

2. For each starting value `n`, repeatedly apply the Collatz function.

3. If `n` is even:

   $$n = n/2$$

4. If `n` is odd:

   $$n = 3n+1$$

5. Continue until the sequence reaches `1`.

6. The program uses:

   - Iterative control structures
   - Functional decomposition
   - Dynamic memory allocation
   - Pointers
   - Integer overflow detection

7. The generated sequence is stored dynamically so that trajectories of different lengths can be handled.

8. If an arithmetic overflow is detected while computing `3n + 1`, the trajectory is terminated safely.

## 📊 Complexity Analysis

For a starting value `n`, let `T(n)` denote the number of terms generated before reaching `1`.

- **Time Complexity:** **O(T(n))**
- **Auxiliary Space Complexity:** **O(T(n))**

For an interval `[a,b]`, the total complexity depends on the trajectory lengths of all starting values.

Unlike the previous DP problems, there is no known polynomial complexity bound for the number of steps required by the Collatz process because the underlying conjecture itself remains unproved.

## 💻 Sample Execution & Output

### Sample Input

```text
Enter interval [a, b]: 5 7
```

### Sample Output

```text
Starting value: 5
Number of terms: 6
Trajectory:
5 16 8 4 2 1

Starting value: 6
Number of terms: 9
Trajectory:
6 3 10 5 16 8 4 2 1

Starting value: 7
Number of terms: 17
Trajectory:
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
```

### Performance Summary

| Input           | Algorithm                   | Approach                              | Auxiliary Space | Total Time Complexity          |
| :-------------- | :-------------------------- | :------------------------------------ | :-------------- | :----------------------------- |
| `[a,b] = [5,7]` | Collatz Trajectory Analysis | Iterative Simulation + Dynamic Memory | **O(T(n))**     | **O(T(n))** per starting value |

---
