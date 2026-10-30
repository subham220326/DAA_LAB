# Q3: Bidirectional BFS for Shortest Transformation Sequence in a Word Graph

**Suggested C Filename:** `Q3_BidirectionalWordTransformation.c`

## 📌 Overview

Given a dictionary `D` of `N` unique words of equal length `L`, find the minimum number of single-character mutations needed to transform a starting word `A` into a target word `B`.

Each mutation must change exactly one character. Every word reached after a mutation must belong to `D`, and `B` must be in `D`. This documentation allows `A` to be absent from the dictionary, as permitted by the lab's stated input ambiguity.

The answer is the number of **mutations (edges)**, not the number of words in the sequence. Return `-1` if no valid transformation exists.

### Input Format

- First line: `N L` - number of dictionary words and their common length.
- Next `N` lines: one dictionary word per line.
- Final line: `A B` - starting word and target word.
- Constraints: `N <= 100000`, `1 <= L <= 10`, and all characters are lowercase English letters.

### Output Format

Print one integer: the minimum number of mutations, or `-1` if no valid sequence exists.

## ⚙️ Algorithmic Logic & Justification

1. Store dictionary words in a hash table mapping each word to an integer ID. Avoid constructing every pair of adjacent words explicitly.
2. Check dictionary membership of `B`. If it is absent, return `-1`. If `A == B` and `B` is present, return `0`.
3. Include `A` as an additional search vertex if it is absent from `D`. The search graph contains `D` plus `A`; all generated neighbors must belong to this set. Including `A` also lets the reverse search reach the starting endpoint.
4. Initialize two distance arrays to `-1`, then set `distA[A] = 0` and `distB[B] = 0`. Create one frontier from each endpoint.
5. At each iteration, choose the smaller current frontier and expand **one complete BFS layer** from that side.
6. Generate neighbors on demand: choose each of the `L` character positions and try each of the other `25` lowercase letters. Use the hash table to check whether the resulting word is a search vertex.
7. For each neighbor `v` of a current word `u`:
   - If `v` is unvisited from this side, set its distance to `distThis[u] + 1` and add it to the next frontier.
   - If `v` has been visited from the opposite side, record the candidate length `distThis[u] + 1 + distOther[v]`.
8. Complete the layer and take the smallest candidate found. If any candidate exists, return it. If a frontier becomes empty without a meeting, return `-1`.

Every graph edge represents exactly one valid mutation, so BFS distances count mutations. The graph is undirected because a one-character change can be reversed. Both searches maintain complete distance layers; when they first meet, the minimum candidate in that layer gives a shortest transformation sequence. Expanding the smaller frontier often reduces the number of words explored.

### Efficient Word Representation in C

For `L <= 10`, encode a word as a base-26 integer using digits `a = 0` through `z = 25`:

```text
key(word) = sum(digit(word[i]) * 26^i), for i = 0 ... L-1
```

Because all words have the same length and `26^10 < 2^64`, this representation fits in `uint64_t` and uniquely identifies each word. Precompute powers of `26`. Replacing one character then produces a new key in constant time:

```text
new_key = key - old_digit * power[i] + new_digit * power[i]
```

Use full-key comparisons in the hash table to handle hash collisions. Original strings may be retained for readability, but are unnecessary when only the mutation count is required.

## 📊 Complexity Analysis

Let `M <= N + 1` be the number of search vertices, including `A` when necessary.

- **Expected Time Complexity with integer encoding:** **O(NL + 26ML)**, or **O(NL)** for a fixed 26-letter alphabet. Encoding inputs takes `O(NL)`; each search visits each vertex at most once and checks up to `25L` candidate mutations per expansion.
- **Auxiliary Space Complexity with integer encoding:** **O(M + L)**, or **O(N + L)** - hash table, two distance arrays, frontiers, and powers of `26`.
- **Total Space Complexity if dictionary strings are also retained:** **O(NL)**.
- **String-based alternative:** If each candidate requires `O(L)` string hashing/comparison work, expected time is **O(NL + 26ML²)**, commonly written **O(NL²)** for a fixed alphabet, with **O(NL)** storage.
- Hash-table bounds assume expected constant-time operations for fixed-width keys and a controlled load factor. Bidirectional BFS improves practical exploration but retains the same worst-case asymptotic bound as ordinary BFS on this implicit graph.

## 💻 Sample Execution & Output

### Sample Input

```text
6 3
hot
dot
dog
lot
log
cog
hit cog
```

### Sample Output

```text
4
```

A shortest sequence is:

```text
hit -> hot -> dot -> dog -> cog
```

This sequence contains five words and **four mutations**. The starting word `hit` is absent from the dictionary, which is allowed by the convention above.

### Additional Sample: No Valid Transformation

#### Sample Input

```text
4 3
hot
dot
dog
cog
hit cat
```

#### Sample Output

```text
-1
```

The target `cat` is absent from the dictionary, so no valid transformation is allowed.

### Limitations & Implementation Notes

- Do not compare all pairs of dictionary words: that would require `O(N²L)` time and is unsuitable for `N = 100000`.
- Generate only actual character changes; replacing a letter with itself is not a mutation.
- Expand a whole BFS layer before deciding which frontier to expand next. When frontiers are swapped, swap the corresponding distance-array roles as well.
- Maintain separate visited/distance information for each direction and check for meetings with the opposite search.
- An in-dictionary target may still be unreachable if it lies in a different connected component; return `-1` in that case as well.
- If using C strings, allocate at least `L + 1` bytes for each word, including the terminating null character.
- Use dynamic allocation for large dictionaries and frontiers, and check allocation results.

### Performance Summary

| Input | Algorithm | Approach | Auxiliary Space | Total Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `N` unique words of length `L <= 10` | Bidirectional BFS | Smaller-frontier expansion, implicit neighbors, base-26 keys and hash lookup | **O(N + L)** with encoded keys | Expected **O(NL + 26(N + 1)L)** |

---
