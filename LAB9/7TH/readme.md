---

# Q7: Minimise Deviation in Array

---

## Q7: Minimise Deviation in Array

**C Filename:** `7thMinimizeDev.c`

## 📌 Overview

Minimize `maximum - minimum` when an odd positive number may be doubled and an even positive number may be halved.

### Input Format

`n`, followed by `n` strictly positive integer values. Require `n ≥ 1`, and ensure doubling odd values fits `long long`.

## ⚙️ Algorithmic Logic & Justification

1. Double every odd input so every starting value is even, and record the minimum normalized value.
2. Insert normalized values individually into a max-heap.
3. Remove the current maximum and update the best deviation using `mx - mn`.
4. If the maximum is odd, stop. Otherwise halve it, update the minimum if necessary, and reinsert it.
5. Normalization puts each number at its largest useful reachable value. Only decreasing a current maximum can improve the range; decreasing another value cannot lower the maximum and may lower the minimum. An odd maximum cannot be reduced further, so the best range already seen is final.

## 📊 Complexity Analysis

- **Time Complexity:** **O((n + H) log(n + 1))**, where `H` is the number of performed halvings. Each heap insertion/removal costs O(log(n + 1)).
- Since each normalized positive value can be halved O(log M) times, a conventional bound is **O(n log M · log(n + 1))**, with `M ≥ 2` the largest normalized value.
- **Auxiliary Space Complexity:** **O(n)** for the max-heap.
- The 1-based heap permits at most 100004 values; input size is not validated.

## 💻 Sample Execution & Output

### Sample Input

```text
4
1 2 3 4
```

### Sample Output

```text
1
```

### Limitations & Implementation Notes

For `1 2 3 4`, normalization gives `2 2 6 4`, and the best deviation is `1`. Zero is outside the supported problem domain: it remains even after halving and can cause a nonterminating loop. Negative values invalidate the reasoning. Empty input prints the initialized sentinel instead of a useful answer.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Odd normalization + max-heap halving | Exact search over decreasing maxima | **O(n)** | **O((n + H) log(n + 1))** |
