# Q3: Maximum Weight Component with Size Constraints

**C Filename:** `Q3_MaxWeightBoundedComponent.c`

## 📌 Overview

Each graph vertex has a signed weight. Edges arrive sequentially, and after each insertion the program prints the **maximum sum of vertex weights** among connected components containing at most `K` vertices. It prints `NONE` if no component satisfies this size restriction.

### Input Format

- First line: `V E K` — vertices, inserted edges, and maximum permitted component size.
- Second line: `w1 w2 ... wV` — signed integer vertex weights, read as `long long`.
- Next `E` lines: `u v edgeWeight` — the endpoints and weight of each incoming edge.
- Vertices are numbered from `1` to `V`.

## ⚙️ Algorithmic Logic & Justification

1. Create a DSU component for each vertex; initialize `sz[i] = 1` and `sum[i] = wi`.
2. Maintain a **segment tree** whose leaf for each active DSU root holds that component's weight **if `sz[root] <= K`**. All other leaves hold `LLONG_MIN` as an invalid marker.
3. For each new edge, find its endpoints' roots. If they match, no components change.
4. Otherwise, invalidate both old roots' segment-tree leaves, merge the DSU components by size, and add their sizes and vertex-weight sums.
5. Insert the merged root's sum into the tree only if its new size is at most `K`. The tree root contains the maximum eligible sum; print `NONE` when none exists.

Unlike a single running maximum, the segment tree remains correct when a merge removes a previously optimal component from eligibility or when negative vertex weights reduce a component's sum.

## 📊 Complexity Analysis

- **Time Complexity:** **O(V log V + E · α(V))** — segment-tree initialization and at most `V - 1` successful unions with `O(log V)` updates, plus DSU processing of all incoming edges.
- **Auxiliary Space Complexity:** **O(V)** — DSU metadata and the segment tree.
- Each inserted edge produces an answer after its DSU update.

## 💻 Sample Execution & Output

### Sample Input

```text
4 4 2
4 -2 7 3
1 2 5
3 4 10
2 3 9
1 4 1
```

### Sample Output

```text
7
10
NONE
NONE
```

### Limitations & Implementation Notes

The program reads `edgeWeight` but **does not use it**, since the requested objective is the sum of **vertex** weights, not edge weights. In the sample, the edge `(2, 3)` joins all four vertices, exceeding `K = 2`, so there are no eligible components thereafter. `LLONG_MIN` is reserved as the tree's invalid sentinel; avoid valid component sums equal to that exact value. Assume all component sums fit in `long long`.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `V` weighted vertices, `E` edge insertions, threshold `K` | DSU + segment tree | Track component sizes/sums and maximum eligible sum | **O(V)** | **O(V log V + E · α(V))** |

---
