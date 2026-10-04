# Q6: Edit Distance with Traceback

---

## Q6: Minimum Edit Distance with Traceback Information

---

## 📌 Overview

This section contains the implementation and complexity analysis for **Question 6** of Lab-08.

Given two strings `A` and `B`, the objective is to calculate the minimum number of operations required to transform `A` into `B`.

The permitted operations are:

- Insertion
- Deletion
- Substitution

The program also produces traceback information showing the operations used to obtain the optimal transformation.

## ⚙️ Algorithmic Logic & Justification

1. Define:

   $$dp[i][j]$$

   as the minimum number of operations required to transform the first `i` characters of `A` into the first `j` characters of `B`.

2. **Base Cases:**

   $$dp[i][0] = i$$

   because `i` deletions are required.

   $$dp[0][j] = j$$

   because `j` insertions are required.

3. If the current characters are equal:

   $$A[i-1] = B[j-1]$$

   then:

   $$dp[i][j] = dp[i-1][j-1]$$

4. Otherwise:

   $$dp[i][j] = 1 + \min(\
   dp[i-1][j],\
   dp[i][j-1],\
   dp[i-1][j-1])\
   $$

5. Traceback is performed from `dp[m][n]` to determine the actual sequence of operations.

## 📊 Complexity Analysis

- **Time Complexity:** **O(mn)**
- **Auxiliary Space Complexity:** **O(mn)**

## 💻 Sample Execution & Output

### Sample Input

```text
First string: kitten
Second string: sitting
```

### Sample Output

```text
Minimum Edit Distance = 3

Traceback:
Substitute 'e' -> 'i'
Substitute 'k' -> 's'
Insert 'g'
```

The exact order of displayed traceback operations may vary depending on the direction selected when multiple optimal operations exist.

### Performance Summary

| Input                     | Algorithm     | Approach                        | Auxiliary Space | Total Time Complexity |
| :------------------------ | :------------ | :------------------------------ | :-------------- | :-------------------- |
| `A = kitten, B = sitting` | Edit Distance | Dynamic Programming + Traceback | **O(mn)**       | **O(mn)**             |

---
