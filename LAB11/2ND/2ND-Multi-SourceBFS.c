#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

void addUndirectedEdge(Node** adj, int u, int v) {
    Node* e1 = (Node*)malloc(sizeof(Node));
    e1->to = v;
    e1->next = adj[u];
    adj[u] = e1;

    Node* e2 = (Node*)malloc(sizeof(Node));
    e2->to = u;
    e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int V, E, K, R;
    if (scanf("%d %d %d %d", &V, &E, &K, &R) != 4) return 0;

    int* hubs = (int*)malloc((K + 1) * sizeof(int));
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &hubs[i]);
    }

    Node** adj = (Node**)calloc(V + 1, sizeof(Node*));
    for (int i = 0; i < E; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addUndirectedEdge(adj, u, v);
    }

    int* owner = (int*)malloc((V + 1) * sizeof(int));
    int* dist = (int*)malloc((V + 1) * sizeof(int));
    for (int i = 1; i <= V; ++i) {
        owner[i] = -1;
        dist[i] = -1;
    }

    // Queue for BFS
    int* queue = (int*)malloc((V + 1) * sizeof(int));
    int head = 0, tail = 0;

    // Seed hubs in strictly increasing index order 1..K
    for (int i = 1; i <= K; ++i) {
        int h = hubs[i];
        if (owner[h] == -1) { // In case two hub indices refer to the same vertex
            owner[h] = i;
            dist[h] = 0;
            queue[tail++] = h;
        }
    }

    // Multi-source BFS
    while (head < tail) {
        int u = queue[head++];

        // We do not expand beyond distance R
        if (dist[u] >= R) continue;

        for (Node* curr = adj[u]; curr != NULL; curr = curr->next) {
            int v = curr->to;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                queue[tail++] = v;
            } else if (dist[v] == dist[u] + 1) {
                // Check tie-breaking: smaller hub index wins
                if (owner[u] < owner[v]) {
                    owner[v] = owner[u];
                }
            }
        }
    }

    printf("Vertex\tOwner Hub\tDistance\n");
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == -1 || dist[i] > R) {
            printf("%d\t-1\t\t-1\n", i);
        } else {
            printf("%d\t%d\t\t%d\n", i, owner[i], dist[i]);
        }
    }

    // Cleanup
    for (int i = 1; i <= V; ++i) {
        Node* curr = adj[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(adj);
    free(hubs);
    free(owner);
    free(dist);
    free(queue);

    return 0;
}