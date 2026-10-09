---

# Q4: Minimum Cost to Connect Sticks

---

## Q4: Minimum Cost to Connect Sticks

**C Filename:** `4thMinimumConnectStick.c`

## 📌 Overview

Connect all sticks into one, where merging sticks of lengths `a` and `b` costs `a + b`. Minimize the sum of all merge costs.

### Input Format

`n`, followed by `n` nonnegative integer stick lengths.

## ⚙️ Algorithmic Logic & Justification

1. Insert each stick length individually into a min-heap.
2. Repeatedly remove the two shortest sticks, add their combined length to the total cost, and insert that combined stick.
3. Stop when at most one stick remains.
4. Every original stick contributes its length once per ancestor merge. The standard optimal-merge exchange argument places the two smallest weights together at greatest depth, justifying each greedy merge.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n log n)**. This code uses repeated heap insertion, not linear-time heap construction, followed by `n - 1` merges.
- **Auxiliary Space Complexity:** **O(n)** for the heap.
- The 1-based heap permits at most 100004 sticks; input size is not validated.

## 💻 Sample Execution & Output

### Sample Input

```text
4
2 4 3 6
```

### Sample Output

```text
29
```

### Limitations & Implementation Notes

For the sample, merge costs are `5`, `9`, and `15`, totaling `29`. Zero or one stick produces cost `0`. The total cost and intermediate lengths must fit `long long`.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Min-heap optimal merging | Greedy exact minimum cost | **O(n)** | **O(n log n)** |
