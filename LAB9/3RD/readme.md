---

# Q3: Minimum Refuelling Stops

---

## Q3: Minimum Refuelling Stops

**C Filename:** `3rdMinimumRefuel.c`

## 📌 Overview

Find the fewest station visits needed to reach destination distance `D`, starting with fuel `F`, assuming one unit of fuel covers one unit of distance.

### Input Format

`n D F`, followed by `n` rows of `distance_from_start fuel_available`. Distances and fuel amounts should be nonnegative. The input need not be sorted.

## ⚙️ Algorithmic Logic & Justification

1. Sort stations by distance from the starting point.
2. Interpret `F` as the greatest distance currently reachable; add fuel from every station with `distance ≤ F` to a max-heap.
3. If the destination is still out of reach, remove the largest available fuel amount, add it to `F`, and count one stop.
4. If no reachable unused station remains, print `-1`.
5. Choosing the largest available refill maximizes reach for the next stop. Any alternative accessible refill gives no greater reach, so it cannot reduce the number of stops relative to this choice.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n log n)** with an O(n log n) library sort: sort stations once, and push/pop each station at most once.
- **Auxiliary Space Complexity:** **O(n)** for the max-heap; the station array also occupies O(n).
- The 1-based heap permits at most 100004 stations; `n` is not validated.

## 💻 Sample Execution & Output

### Sample Input

```text
4 25 10
5 5
10 10
14 10
20 5
```

### Sample Output

```text
2
```

### Limitations & Implementation Notes

Assumes unlimited tank capacity and complete station fuel uptake. Stations use distance from the start, not distance from the destination. Already having `F ≥ D` prints `0`. Large cumulative reach must fit `long long`.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Distance sorting + max-heap | Greedy minimum-stop selection | **O(n)** | **O(n log n)** |
