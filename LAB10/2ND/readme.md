# Q2: Dynamic Connected Components in a Grid

**C Filename:** `Q2_DynamicNumberOfIslands.c`

## 📌 Overview

Start with an `R × C` grid containing only water. Land cells are activated one by one. After every activation, print the current number of **4-directionally connected islands**. Repeatedly adding an already active cell does not change the count.

### Input Format

- First line: `R C k` — row count, column count, and number of land-addition operations.
- Next `k` lines: `r c` — coordinates of the cell to turn into land.
- Rows and columns are **1-based** and must lie within the grid.

## ⚙️ Algorithmic Logic & Justification

1. Flatten each grid cell into one DSU index: `id = (r - 1) * C + (c - 1)`.
2. Initialize every cell as inactive water with `parent[id] = -1` and set `islands = 0`.
3. On a new land addition, initialize its DSU node and increment `islands` by one. For duplicate additions, print the unchanged count.
4. Check the four neighbors using offsets `(-1,0)`, `(1,0)`, `(0,-1)`, and `(0,1)`.
5. For every active neighbor in a different DSU component, perform a union and decrement `islands`. Print the count after the operation.

Every successful union joins two previously separate islands, so subtracting one maintains the correct connected-component count.

## 📊 Complexity Analysis

- **Time Complexity:** **O(RC + k · α(RC))** — initialize the grid in `O(RC)` and check at most four neighbors per operation.
- **Auxiliary Space Complexity:** **O(RC)** — flattened DSU arrays for all grid positions.

## 💻 Sample Execution & Output

### Sample Input

```text
3 3 6
1 1
1 2
3 3
2 3
2 2
2 2
```

### Sample Output

```text
1
1
2
2
1
1
```

### Limitations & Implementation Notes

Only **up, down, left, and right** neighbors count as connected; diagonals do not. The fifth operation merges the two islands. The sixth is a duplicate, so its output remains `1`. The implementation uses storage proportional to the full grid, even when few cells are activated.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `R × C` grid, `k` additions | Grid DSU | Flatten coordinates, merge active neighbors | **O(RC)** | **O(RC + k · α(RC))** |

---
