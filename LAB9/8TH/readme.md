---

# Q8: Minimum Number of Meeting Rooms

---

## Q8: Minimum Number of Meeting Rooms

**C Filename:** `8thMinNoOfMeeting.c`

## 📌 Overview

Compute the maximum number of simultaneously active meetings, which equals the minimum number of rooms required.

### Input Format

`n`, followed by `n` rows of `start end`, with `start < end` for every meeting.

## ⚙️ Algorithmic Logic & Justification

1. Store start times and end times in separate arrays and sort both arrays.
2. Use two pointers. When the next start is strictly less than the next end, open a room and update the peak count.
3. Otherwise process an ending meeting first and free a room.
4. Continue until all starts have been processed.
5. Every simultaneous meeting needs a distinct room, and the sweep reuses rooms once meetings end. Therefore the peak active count is both a lower bound and an achievable room count.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n log n)** with O(n log n) library sorting; the sweep is O(n).
- **Auxiliary Space Complexity:** **O(n)** for the endpoint arrays; the scan itself uses O(1) additional variables.
- Each local array has 100005 entries; input size is not validated.

## 💻 Sample Execution & Output

### Sample Input

```text
4
0 30
5 10
15 20
20 25
```

### Sample Output

```text
2
```

### Limitations & Implementation Notes

Intervals behave as half-open `[start, end)`: a meeting ending at time `t` frees its room before a meeting starting at `t`. Zero-duration or reversed intervals are unsupported; they may cause the end pointer to read beyond the initialized entries. Large local endpoint arrays require sufficient stack space.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Sorted endpoints + two-pointer sweep | Exact peak concurrency | **O(n)** | **O(n log n)** |
