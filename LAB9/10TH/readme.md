---

# Q10: Greedy Shortest Superstring

---

## Q10: Greedy Shortest Superstring

**C Filename:** `10thShortestSubstring.c`

## 📌 Overview

Combine input strings into a common superstring using repeated maximum-overlap merges. Despite the filename `10thShortestSubstring.c`, the task is superstring construction. The result is a heuristic and is not guaranteed to be globally shortest.

### Input Format

`n`, followed by `n` whitespace-free string tokens. Use `1 ≤ n ≤ 100`; each original token may contain at most 10004 bytes.

## ⚙️ Algorithmic Logic & Justification

1. Examine every ordered pair of current strings.
2. If `b` already occurs anywhere inside `a`, `overlap(a,b)` returns the full length of `b`; merging preserves `a`.
3. Otherwise test suffix/prefix lengths from largest to smallest using `strncmp`, finding the largest suffix of `a` equal to a prefix of `b`.
4. Choose the pair with largest overlap. On equal overlap, prefer smaller computed merged length; exact ties retain the first pair in the current array order.
5. Construct the merged string, retain the other strings in order, append the new string, and free the replaced strings.
6. Repeat until one string remains and print it. Each merge preserves all represented inputs, ensuring a common superstring. A locally largest overlap does not establish global minimum length.

## 📊 Complexity Analysis

- Let **S** be the total number of bytes in the original input strings, excluding terminators, and **L** the maximum original string length.
- **Time Complexity:** A conservative character-comparison bound is **O(n · S²)**, hence **O(n³ · L²)** since `S ≤ nL`.
- For a pair of lengths `a,b`, naive containment and repeated suffix comparisons cost O(ab); repeated `strlen` adds O(a+b). Across all ordered pairs in one round these costs sum to O(S²), since current total length never exceeds S. There are `n - 1` rounds. Library string-search implementations may run faster.
- **Auxiliary Space Complexity:** **O(S + n)** including stored and temporary merged strings and pointer arrays. A new merged string exists briefly alongside its two originals; peak storage remains O(S + n). Excluding the final output still leaves O(S + n) working storage.

## 💻 Sample Execution & Output

### Sample Input

```text
3
abc
bcd
cde
```

### Sample Output

```text
abcde
```

### Limitations & Implementation Notes

The actual input buffer is `char buf[10005]`, read with `%10004s`: each original token is limited to **10004 bytes**. Longer tokens leave unread characters and corrupt the intended token sequence. Dynamic merged strings can exceed that limit. Allocation failures are not checked. Containment, merge direction, input order, and ties can affect the result. No approximation ratio is established by this README.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Repeated all-pairs maximum-overlap merging | Greedy heuristic; no shortest-result guarantee | **O(S + n)** | **O(nS²), or O(n³L²)** |

---
