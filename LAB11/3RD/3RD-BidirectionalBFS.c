#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 262144 // 2^18 (> 2 * 10^5) for low collision rate

typedef struct HashNode {
    char word[12];
    int dist_fwd;
    int dist_bwd;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

unsigned int hash(const char* str) {
    unsigned int h = 5381;
    while (*str) {
        h = ((h << 5) + h) + (unsigned char)(*str++);
    }
    return h % HASH_SIZE;
}

HashNode* insertOrGet(const char* word) {
    unsigned int h = hash(word);
    HashNode* curr = hashTable[h];
    while (curr) {
        if (strcmp(curr->word, word) == 0) return curr;
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->word, word);
    newNode->dist_fwd = -1;
    newNode->dist_bwd = -1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
    return newNode;
}

HashNode* find(const char* word) {
    unsigned int h = hash(word);
    HashNode* curr = hashTable[h];
    while (curr) {
        if (strcmp(curr->word, word) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

int main() {
    int N, L;
    if (scanf("%d %d", &N, &L) != 2) return 0;

    char startWord[12], endWord[12];
    scanf("%s %s", startWord, endWord);

    memset(hashTable, 0, sizeof(hashTable));

    for (int i = 0; i < N; ++i) {
        char w[12];
        scanf("%s", w);
        insertOrGet(w);
    }

    // Target word B must exist in the dictionary
    HashNode* targetNode = find(endWord);
    if (!targetNode) {
        printf("-1\n");
        return 0;
    }

    if (strcmp(startWord, endWord) == 0) {
        printf("0\n");
        return 0;
    }

    // Insert start word into lookup table if not already present
    HashNode* startNode = insertOrGet(startWord);

    // Frontier queues
    HashNode** qFwd = (HashNode**)malloc((N + 5) * sizeof(HashNode*));
    HashNode** qBwd = (HashNode**)malloc((N + 5) * sizeof(HashNode*));
    int fwdHead = 0, fwdTail = 0;
    int bwdHead = 0, bwdTail = 0;

    startNode->dist_fwd = 0;
    qFwd[fwdTail++] = startNode;

    targetNode->dist_bwd = 0;
    qBwd[bwdTail++] = targetNode;

    int shortestPath = -1;

    while (fwdHead < fwdTail && bwdHead < bwdTail) {
        // Always expand the smaller frontier
        if ((fwdTail - fwdHead) <= (bwdTail - bwdHead)) {
            HashNode* u = qFwd[fwdHead++];
            char temp[12];
            strcpy(temp, u->word);

            for (int i = 0; i < L; ++i) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == orig) continue;
                    temp[i] = c;

                    HashNode* neighbor = find(temp);
                    if (neighbor) {
                        if (neighbor->dist_bwd != -1) {
                            shortestPath = u->dist_fwd + 1 + neighbor->dist_bwd;
                            goto finished;
                        }
                        if (neighbor->dist_fwd == -1) {
                            neighbor->dist_fwd = u->dist_fwd + 1;
                            qFwd[fwdTail++] = neighbor;
                        }
                    }
                }
                temp[i] = orig;
            }
        } else {
            HashNode* u = qBwd[bwdHead++];
            char temp[12];
            strcpy(temp, u->word);

            for (int i = 0; i < L; ++i) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == orig) continue;
                    temp[i] = c;

                    HashNode* neighbor = find(temp);
                    if (neighbor) {
                        if (neighbor->dist_fwd != -1) {
                            shortestPath = u->dist_bwd + 1 + neighbor->dist_fwd;
                            goto finished;
                        }
                        if (neighbor->dist_bwd == -1) {
                            neighbor->dist_bwd = u->dist_bwd + 1;
                            qBwd[bwdTail++] = neighbor;
                        }
                    }
                }
                temp[i] = orig;
            }
        }
    }

finished:
    printf("%d\n", shortestPath);

    // Free memory
    free(qFwd);
    free(qBwd);
    for (int i = 0; i < HASH_SIZE; ++i) {
        HashNode* curr = hashTable[i];
        while (curr) {
            HashNode* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }

    return 0;
}