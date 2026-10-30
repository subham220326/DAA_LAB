# Q1: Shortest Path on Parity-Constrained Graphs via 0-1 BFS

**Suggested C Filename:** `Q1_ParityConstrainedShortestPath.c`

## 📌 Overview

A directed graph contains edges with weights `0` or `1`. Given a source vertex `S` and a non-negative penalty `C`, compute the minimum effective cost from `S` to every vertex.

For a path `P`:

- `W(P)` is the sum of its edge weights.
- `k1(P)` is the number of weight-1 edges traversed.
- The effective cost is `W(P)` when `k1(P)` is even, and `W(P) + C` when it is odd.

A vertex may have different best routes for even and odd parity. Therefore, the algorithm maintains **two distance states per vertex** and applies the penalty only when calculating the final answer.

### Input Format

- First line: `V E` - number of vertices and directed edges.
- Second line: `S C` - source vertex and non-negative penalty.
- Next `E` lines: `u v w` - a directed edge from `u` to `v`, with `w` equal to `0` or `1`.
- Vertices are numbered from `1` to `V`.

### Output Format

Print one line per vertex as `vertex minimum_cost`, in increasing vertex order. Print `vertex UNREACHABLE` if neither parity state can be reached.

## ⚙️ Algorithmic Logic & Justification

1. Store the directed graph using an adjacency list.
2. Represent a search state as `(v, p)`, where `p = 0` means an even number of weight-1 edges and `p = 1` means an odd number.
3. Initialize every `dist[v][p]` to infinity. Set `dist[S][0] = 0` and insert `(S, 0)` into a deque.
4. For each edge `(u, v, w)` from a state `(u, p)`, calculate:

   ```text
   next_parity = p XOR w
   candidate = dist[u][p] + w
   ```

5. If `candidate < dist[v][next_parity]`, update the distance. Push the new state to the **front** of the deque for weight `0`, or the **back** for weight `1`.
6. Use the standard 0-1 BFS deque discipline; discard stale entries or skip states already finalized when removed at their minimum distance.
7. After the search, compute:

   ```text
   answer[v] = min(dist[v][0], dist[v][1] + C)
   ```

   Only include finite terms. If both distances are infinite, report `UNREACHABLE`.

Every original edge produces one transition from each parity state. The expanded graph therefore has `2V` states and `2E` transitions, all with weights `0` or `1`. 0-1 BFS finds the minimum base cost for each parity; taking the smaller of the two final costs gives the required answer.

## 📊 Complexity Analysis

- **Time Complexity:** **O(V + E)** - 0-1 BFS processes the expanded graph in linear time, followed by `O(V)` output computation.
- **Auxiliary Space Complexity:** **O(V)** - two distances per vertex, state bookkeeping, and the active deque when using an implementation that keeps at most one active entry per state.
- **Total Space Complexity:** **O(V + E)** - including the adjacency list. A simpler deque that permits duplicate entries may use `O(V + E)` auxiliary space instead.

## 💻 Sample Execution & Output

### Sample Input

```text
6 6
1 5
1 2 1
1 3 1
3 2 1
2 4 0
3 5 0
4 5 1
```

### Sample Output

```text
1 0
2 2
3 6
4 2
5 2
6 UNREACHABLE
```

### Limitations & Implementation Notes

- For vertex `2`, the direct route has base cost `1` and odd parity, giving cost `1 + 5 = 6`. The route `1 -> 3 -> 2` has base cost `2` and even parity, so its effective cost is `2`.
- Vertex `4` inherits the even-parity route through vertex `2`. For vertex `5`, the route `1 -> 2 -> 4 -> 5` has two weight-1 edges and effective cost `2`. This shows why both parity states must be retained even when one has a worse final cost at an intermediate vertex. Vertex `6` is unreachable.
- A weight-0 edge preserves parity; a weight-1 edge flips parity.
- Do not add `C` to every weight-1 edge. It is a single penalty based on the parity of the complete route.
- Use a sufficiently wide integer type, such as `long long`, for final costs and guard infinity before adding `C`.
- The state-graph approach uses the usual shortest-route convention that vertices may be revisited. It does not enforce a separate simple-path restriction.
- If using duplicate deque entries, allocate sufficient capacity dynamically and skip outdated entries.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `V` vertices, `E` directed edges | 0-1 BFS | Two parity states per vertex; final odd-parity penalty | **O(V)** with one active entry per state; otherwise **O(V + E)** | **O(V + E)** |

---
