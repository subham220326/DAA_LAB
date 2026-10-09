---

# Q1: Fractional Knapsack with Deterioration Rate

---

## Q1: Fractional Knapsack with Deterioration Rate

**C Filename:** `1stFractionalKnapSackWithDecay.c`

## 📌 Overview

Select fractional amounts of items within capacity `W`, with value density decreasing according to an item's assigned unit time slot. This implementation exhaustively searches ordered subsets; it is not an ordinary density-sort-only fractional-knapsack solver.

### Input Format

`n W`, followed by `n` rows of `value weight deterioration_rate`. Use `1 ≤ n ≤ 9`, positive weights, nonnegative capacity and deterioration rates. Values and weights are read as doubles.

## ⚙️ Algorithmic Logic & Justification

1. `solve(k)` calls `check(k)` for every prefix of every permutation, including the empty prefix. The `used[]` array prevents repeated items.
2. For an item `id = order[p]`, its effective value per unit weight is `v[id] / w[id] - lambda[id] * p`. Slots are integer positions `p = 0, 1, ...`; they do not depend on the amount consumed.
3. For each fixed order, a nested-loop sort ranks these effective densities. Fill capacity from the highest positive density, taking at most the item's full weight. Stop when capacity is exhausted or the next density is nonpositive.
4. This fractional fill is optimal for a fixed slot assignment: replacing weight taken at a lower density with available weight at a higher density improves value.
5. Exhaustive enumeration covers every ordered subset, so the best evaluated assignment is exact for this discrete-slot model. Strict `val > best` retains the first optimum on ties. Printed amounts follow the saved slot order, not necessarily density order.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n² · n!)**. There are `Σ(k=0..n) n!/(n-k)!` prefix states, and evaluation sorts up to `k` densities in O(k²) time.
- **Auxiliary Space Complexity:** **O(n)** for bookkeeping, the active evaluation arrays, and recursion depth. `check()` returns before deeper recursive calls; its temporary arrays do not accumulate across recursion levels.
- Arrays have capacity 10; the program explicitly returns without output for `n < 1` or `n > 9`.

## 💻 Sample Execution & Output

### Sample Input

```text
2 5
20 5 1
9 3 0.5
```

### Sample Output

```text
Maximum Value: 20.00
Item 1: 5.00
```

### Limitations & Implementation Notes

The reported optimum applies only to the implemented unit-slot model. There is no continuous-time integration, duration proportional to weight, or exponential decay. Slots are assigned to the enumerated prefix even if an item's final amount is zero. Floating-point comparisons and two-decimal output may conceal small numerical differences.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Exhaustive ordered-subset search + fractional fill | Exact under the implemented unit-slot assumptions | **O(n)** | **O(n² · n!)** |
