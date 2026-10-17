# Q4: Reverse Time-Step DSU Application

**C Filename:** `Q4_ReverseVertexDeletion.c`

## 📌 Overview

Given a vertex-weighted, undirected graph and an order in which all vertices are deleted, report the **maximum sum of vertex weights among the remaining connected components** after each deletion. Removing a vertex also removes every edge incident to it.

### Input Format

- First line: `V E` — numbers of vertices and undirected edges.
- Second line: `w1 w2 ... wV` — signed vertex weights, read as `long long`.
- Next `E` lines: `u v` — graph edges.
- Last line: `p1 p2 ... pV` — permutation specifying the deletion order.
- Vertices are numbered from `1` to `V`.

## ⚙️ Algorithmic Logic & Justification

1. Store the original graph as an **adjacency list**; initially mark every vertex inactive.
2. Process the deletion permutation **backward**. Reverse additions are easier than forward deletions because DSU efficiently merges components but cannot directly split them.
3. Before reactivating `order[i]`, save the maximum component sum currently present: this is the answer **after the first `i + 1` forward deletions**.
4. Reactivate `order[i]` as a singleton DSU component containing its own vertex weight.
5. For every already active neighbor, merge distinct DSU components. Update a **segment tree** by removing the old component sums and inserting the merged sum.
6. After all reverse additions, print the recorded answers in the original forward order.

A segment tree is needed for the general case of **negative vertex weights**: joining components can lower the maximum, so simply retaining the largest sum seen so far is incorrect.

## 📊 Complexity Analysis

- **Time Complexity:** **O(V log V + (V + E) · α(V))** — create the adjacency list, inspect each vertex/edge in reverse, and perform `O(V)` segment-tree changes for activations and successful unions.
- **Auxiliary Space Complexity:** **O(V + E)** — adjacency list, DSU, active markers, deletion order, answers, and segment tree.

## 💻 Sample Execution & Output

### Sample Input

```text
4 3
1 2 -10 4
1 2
2 3
3 4
2 1 4 3
```

### Sample Output

```text
1
-6
-10
0
```

### Limitations & Implementation Notes

Deleting vertex `2` leaves components `{1}` (sum `1`) and `{3,4}` (sum `-6`), so the answer is `1`. After deleting every vertex, the implementation prints **`0` for the empty graph**. Negative component sums are otherwise preserved. The deletion order must be a permutation of all vertices. `LLONG_MIN` is used as an inactive marker; avoid an actual component sum equal to that sentinel, and keep all sums within `long long` range.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `V` weighted vertices, `E` edges, `V` deletions | Reverse DSU + segment tree | Activate backward, merge active neighbors, query component maximum | **O(V + E)** | **O(V log V + (V + E) · α(V))** |

---

