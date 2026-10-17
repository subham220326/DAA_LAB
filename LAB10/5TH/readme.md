# Q5: Lexicographically Smallest Connected Component Permutation

**C Filename:** `Q5_LexicographicallySmallestPermutation.c`

## 📌 Overview

Given a permutation of numbers `1 ... n` and allowed swaps between specified pairs of **positions**, find the lexicographically smallest permutation reachable after any number of permitted swaps.

### Input Format

- First line: `n m` — permutation size and number of allowed swap pairs.
- Second line: `A1 A2 ... An` — the initial permutation.
- Next `m` lines: `u v` — 1-based positions whose values may be swapped.

## ⚙️ Algorithmic Logic & Justification

1. Treat array positions as graph vertices and permitted swaps as undirected edges.
2. Use DSU to group positions into connected components.
3. Because swaps along paths can rearrange values arbitrarily within a component, all positions in that component may receive any permutation of their original values.
4. Create `(root, index)` pairs and sort them by root and then by ascending position. This groups each component's positions in increasing index order.
5. For each component, collect its current values, sort these values ascending, and assign them to the component's positions in ascending order.
6. Print the resulting permutation.

For lexicographic minimization, the smallest available value must occupy the earliest position at which a choice is possible. Sorting independently within each component achieves that for every such position.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n log n + (n + m) · α(n))** under the usual `O(n log n)` sorting bound — DSU operations plus sorting the `(root, position)` pairs and each component's values.
- **Auxiliary Space Complexity:** **O(n)** — DSU arrays, grouped indices, temporary values, and output array.
- The C implementation uses `qsort`; its precise worst-case guarantee depends on the C library's sorting implementation.

## 💻 Sample Execution & Output

### Sample Input

```text
5 2
4 3 1 5 2
1 3
3 5
```

### Sample Output

```text
1 3 2 5 4
```

### Limitations & Implementation Notes

Allowed swaps connect positions `{1, 3, 5}` into one component; their values `{4, 1, 2}` can be rearranged into `{1, 2, 4}` at those positions. Positions `2` and `4` have no allowed swaps, so their values remain unchanged. The implementation assumes the given array is a permutation of `1 ... n`; allowed swaps refer to **positions**, not vertex values.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Permutation of `n` elements and `m` allowed swaps | DSU + sorting | Sort reachable values within each connected component | **O(n)** | **O(n log n + (n + m) · α(n))** (usual sorting bound) |

---

## Overall Complexity Comparison

| Q. | Algorithm | Total Time Complexity | Auxiliary Space Complexity |
| :-- | :-- | :-- | :-- |
| 1 | DSU with parity | **O(V + E · α(V))** | **O(V)** |
| 2 | DSU with coordinate flattening | **O(RC + k · α(RC))** | **O(RC)** |
| 3 | DSU + segment tree | **O(V log V + E · α(V))** | **O(V)** |
| 4 | Reverse DSU + segment tree | **O(V log V + (V + E) · α(V))** | **O(V + E)** |
| 5 | DSU + sorting | **O(n log n + (n + m) · α(n))** | **O(n)** |

## Key Takeaways

- **Parity DSU** maintains bipartiteness when edges are inserted online.
- **Coordinate flattening** adapts DSU to dynamic 2D grids.
- **Component metadata + segment tree** makes maximum-weight queries efficient even when old maxima disappear.
- **Reversing deletion order** converts difficult connectivity deletions into ordinary DSU unions.
- **Connected-component sorting** gives the smallest permutation reachable by restricted swaps.

The five programs are independent and should be compiled and executed separately.

