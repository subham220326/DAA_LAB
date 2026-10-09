---

# Q5: Candy Distribution Problem

---

## Q5: Candy Distribution Problem

**C Filename:** `5thCandyDist.c`

## 📌 Overview

Give every child at least one candy, and give more candies to a child whose rating exceeds an adjacent child's rating. Minimize the total.

### Input Format

`n`, followed by `n` integer ratings.

## ⚙️ Algorithmic Logic & Justification

1. Initialize every candy count to 1.
2. Scan left to right. If `a[i] > a[i - 1]`, set `c[i] = c[i - 1] + 1`.
3. Scan right to left. If `a[i] > a[i + 1]` and its current count is insufficient, set `c[i] = c[i + 1] + 1`.
4. Sum all counts using `long long`.
5. Each direction establishes the minimum requirement from that neighbor. Keeping the larger requirement satisfies both sides with the smallest feasible count per child.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n)** for initialization, two directional passes, and summation.
- **Auxiliary Space Complexity:** **O(n)** for candy counts. The stored ratings also take O(n).
- Both local arrays have 100005 entries; input size is not validated.

## 💻 Sample Execution & Output

### Sample Input

```text
5
1 0 2 3 2
```

### Sample Output

```text
9
```

### Limitations & Implementation Notes

The sample allocation is `2 1 2 3 1`, so the program prints `9`. Equal ratings impose no extra candies. Counts are stored in `int`, and only the total is stored in `long long`. The two large local arrays require sufficient stack space.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Two directional passes | Exact minimum neighbor constraints | **O(n)** | **O(n)** |
