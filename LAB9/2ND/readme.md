---

# Q2: Huffman Coding

---

## Q2: Huffman Coding

**C Filename:** `2ndHuffMan.c`

## 📌 Overview

Build optimal binary prefix-code lengths from symbol frequencies, then print canonical Huffman codes ordered by increasing code length and lexicographic symbol name.

### Input Format

`n`, followed by `n` rows of `symbol frequency`. Use `1 ≤ n ≤ 256`, distinct whitespace-free names of at most 31 bytes, and positive integer frequencies. Frequencies and their sums must fit `long long`.

## ⚙️ Algorithmic Logic & Justification

1. Store all leaves and mark every node's parent as `-1`.
2. At each merge, scan all existing parentless nodes to find the two lowest frequencies; link them to a new node whose frequency is their sum. This implementation uses repeated scans, not a priority queue.
3. Count each leaf's parent links to obtain its code length. A single symbol is assigned length 1.
4. Sort symbol indices by length, then by `strcmp(name[x], name[y])`.
5. Generate canonical codes: start with zeros, increment the previous binary code, and append zeros when the next length is larger.
6. Huffman's least-frequency merging minimizes weighted path length for nonnegative frequencies. Canonicalization preserves lengths and therefore preserves the weighted encoding cost.

## 📊 Complexity Analysis

- **Time Complexity:** **O(n²)**. Repeated minimum scans and all parent-chain traversals each have an O(n²) worst-case bound. Canonical-code generation and printing can also total O(n²) characters for a skewed tree.
- **Auxiliary Space Complexity:** **O(n)** for frequencies, parents, code lengths, ordering, and the current code buffer. Symbol names have a fixed maximum length of 31 bytes.
- Storage supports 256 leaves and 511 total tree nodes.

## 💻 Sample Execution & Output

### Sample Input

```text
3
a 5
b 2
c 1
```

### Sample Output

```text
a: 0
b: 10
c: 11
```

### Limitations & Implementation Notes

These are canonical codes, so bit patterns need not match left/right paths in another Huffman implementation. Equal frequencies are resolved by scan order, while equal code lengths are printed by symbol name. No encoded message, decoder, or compression ratio is produced. One symbol prints code `0`.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| Sample shown above | Huffman merging by linear scans + canonical codes | Exact optimal prefix-code lengths | **O(n)** | **O(n²)** |
