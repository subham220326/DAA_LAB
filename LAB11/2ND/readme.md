# Q2: Multi-Source BFS for Radius-Constrained Voronoi Cell Partitioning

**Suggested C Filename:** `Q2_RadiusConstrainedVoronoi.c`

## 📌 Overview

Given an unweighted, undirected graph, `K` designated hubs, and a radius `R`, assign each covered vertex to its nearest hub.

- Assign a vertex only if its nearest hub is at distance at most `R`.
- If multiple hubs are equally close, choose the hub with the **smallest hub index**.
- Assign `owner[v] = -1` when no hub is within radius `R`.

Hub indices are their positions in the input list, from `1` to `K`; they are distinct from the hubs' vertex numbers.

### Input Format

- First line: `V E` - number of vertices and undirected edges.
- Next `E` lines: `u v` - an undirected edge.
- Next line: `K R` - number of hubs and non-negative radius.
- Next line: `h1 h2 ... hK` - distinct hub vertices, in hub-index order.
- Vertices are numbered from `1` to `V`.

### Output Format

Print one line per vertex as `vertex owner distance`, in increasing vertex order. For an unassigned vertex, print `vertex -1 -1`.

Here, distance `-1` is an output convention meaning that no hub was assigned. It does not distinguish a disconnected vertex from one whose nearest hub lies beyond `R`.

## ⚙️ Algorithmic Logic & Justification

1. Store each undirected edge in both directions using an adjacency list.
2. Initialize `owner[v] = -1` and `dist[v] = -1` for every vertex.
3. Initialize **all hubs before starting traversal**. For hub index `i`, set `owner[hi] = i`, `dist[hi] = 0`, and enqueue `hi`.
4. Enqueue hubs in increasing **hub-index order**: `h1`, then `h2`, and so on.
5. Process the queue using FIFO order. When removing a vertex `u`:
   - If `dist[u] == R`, do not expand its neighbors.
   - Otherwise, for every unvisited neighbor `v`, assign `dist[v] = dist[u] + 1`, copy `owner[v] = owner[u]`, and enqueue `v`.
6. Keep the first assignment of each vertex. Vertices never reached within the radius retain `owner = -1` and `dist = -1`.

Multi-source BFS visits vertices in increasing distance from the nearest hub. Within each distance layer, hub-index order is preserved: each layer is processed in nondecreasing owner order, so the next layer is also discovered in that order. Thus, the first assignment resolves equal-distance ties in favor of the smallest hub index, regardless of adjacency-list order.

## 📊 Complexity Analysis

- **Time Complexity:** **O(V + E + K)**, which is **O(V + E)** because distinct hubs satisfy `K <= V`.
- **Auxiliary Space Complexity:** **O(V + K)**, or **O(V)** - ownership, distance, hub list, and queue.
- **Total Space Complexity:** **O(V + E)** - including both adjacency entries for every undirected edge.
- The radius cutoff may reduce traversal work, but reading and storing the full graph still takes `O(V + E)` time and space in the worst case.

## 💻 Sample Execution & Output

### Sample Input

```text
9 7
1 2
2 3
3 4
4 5
5 6
6 7
7 8
2 2
5 1
```

### Sample Output

```text
1 2 0
2 2 1
3 1 2
4 1 1
5 1 0
6 1 1
7 1 2
8 -1 -1
9 -1 -1
```

### Limitations & Implementation Notes

- Hub index `1` is vertex `5`; hub index `2` is vertex `1`.
- Vertex `3` is two edges from both hubs, so it belongs to hub index `1`.
- Vertex `8` is three edges from its nearest hub, which exceeds `R = 2`. Vertex `9` is disconnected. Both are unassigned.
- For `R = 0`, only hub vertices receive ownership labels.
- Preserve the input hub order. Sorting hubs by vertex number would change the required tie-breaking rule.
- Mark a vertex visited when it is enqueued so that it enters the queue at most once.
- Assume valid vertex indices and distinct hubs. If an empty hub list is permitted, every vertex remains unassigned.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `V` vertices, `E` undirected edges, `K` hubs, radius `R` | Multi-source BFS | Ordered hub initialization, FIFO traversal, radius cutoff | **O(V)** | **O(V + E)** |

---
