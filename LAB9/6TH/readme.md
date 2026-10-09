---

# Q6: Reorganise String with K-Distance Apart

---

## Q6: Reorganise String with K-Distance Apart

**C Filename:** `6thReorganise.c`

## 📌 Overview

Rearrange a whitespace-free string so repeated occurrences of each byte are separated by at least `k` positions. Print an empty line if construction fails.

### Input Format

A string token, then integer `k` (on the same line or another line). Use `0 ≤ k ≤ 100004` and at most 100004 input bytes.

## ⚙️ Algorithmic Logic & Justification

1. Count byte frequencies in `freq[256]` and initialize `last[256]` to a large negative sentinel.
2. At output position `i`, scan all 256 byte values. A byte is eligible when it remains available and `i - last[byte] ≥ k`.
3. Select an eligible byte with maximum remaining frequency, append it, decrement its frequency, and record `last[byte] = i`.
4. Equal frequencies retain the lower byte value because the scan is ascending and updates only on a strictly larger frequency.
5. Prioritizing the largest remaining demand is the cooldown scheduling greedy choice. The eligibility test directly enforces the required spacing. If no byte is eligible, the implementation prints only a newline and terminates.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n · σ)**, where `n` is string length and `σ = 256`. Thus **O(n)** for this fixed byte alphabet.
- **Auxiliary Space Complexity:** **O(σ)** excluding the output buffer; **O(n + σ)** including the separately constructed `ans[]` buffer.
- Both input and output buffers have 100005 entries.

## 💻 Sample Execution & Output

### Sample Input

```text
aabbcc
3
```

### Sample Output

```text
abcabc
```

### Limitations & Implementation Notes

This is byte processing, not Unicode character processing. Input cannot contain whitespace. A failure produces no explanatory text: stdout is exactly `\n`. The program uses full alphabet scans, not a heap/cooldown queue. The initial sentinel and subtraction are not safe for arbitrary extreme `k` values.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Maximum-frequency eligible-byte selection | Greedy cooldown scheduling | **O(σ), or O(n + σ) with output** | **O(nσ); O(n) for σ = 256** |
