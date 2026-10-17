# Q1: Online Graph Bipartiteness Testing

**C Filename:** `Q1_OnlineGraphBipartiteness.c`

## 📌 Overview

An undirected graph receives edges one at a time. Accept an edge only if the resulting graph remains **bipartite**, meaning its vertices can still be divided into two groups with every edge joining opposite groups. Reject an edge if it would create an odd-length cycle; rejected edges are not inserted.

### Input Format

- First line: `V E` — number of vertices and incoming edges.
- Next `E` lines: `u v` — the endpoints of each proposed edge.
- Vertices are numbered from `1` to `V`.

## ⚙️ Algorithmic Logic & Justification

1. Initialize each vertex as its own DSU component with `parent[i] = i`, `sz[i] = 1`, and `parity[i] = 0`.
2. `find(x)` uses path compression while maintaining the XOR parity between `x` and its component representative.
3. For a proposed edge `(u, v)`, find their component roots and corresponding parities `pu` and `pv`.
4. If both vertices already belong to the same component, the edge is valid **only when `pu ^ pv == 1`**. Otherwise, both endpoints have the same color and the edge would create an odd cycle, so reject it.
5. If the roots differ, merge by size and set the attached root's parity to `pu ^ pv ^ 1`, enforcing opposite endpoint colors. Print `ADDED` for a valid edge and `REJECTED` otherwise.

A valid two-coloring can be maintained across all accepted edges, so the accepted graph always stays bipartite.

## 📊 Complexity Analysis

- **Time Complexity:** **O(V + E · α(V))** — initialization takes `O(V)`; each edge requires a constant number of amortized near-constant-time DSU operations.
- **Auxiliary Space Complexity:** **O(V)** — `parent[]`, `sz[]`, and `parity[]`.
- `α(V)` denotes the inverse Ackermann function, which is effectively constant for practical input sizes.

## 💻 Sample Execution & Output

### Sample Input

```text
4 5
1 2
2 3
3 1
3 4
1 4
```

### Sample Output

```text
ADDED
ADDED
REJECTED
ADDED
ADDED
```

### Limitations & Implementation Notes

The edge `(3, 1)` is rejected because edges `(1, 2)` and `(2, 3)` already form a path that would become a 3-cycle. Self-loops are also rejected, because they violate bipartiteness. The implementation assumes valid vertex indices and processes edges in the given order without storing an adjacency list.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `V` vertices, `E` proposed edges | Parity DSU | Online accept/reject with odd-cycle detection | **O(V)** | **O(V + E · α(V))** |

---
