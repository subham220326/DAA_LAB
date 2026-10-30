#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

// Adjacency list representation using forward star / linked list
typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    int u;
    int parity;
} State;

// Double-Ended Queue (Deque) for 0-1 BFS
typedef struct {
    State* data;
    int head;
    int tail;
} Deque;

void initDeque(Deque* dq, int capacity) {
    dq->data = (State*)malloc(sizeof(State) * (2 * capacity + 2));
    dq->head = capacity;
    dq->tail = capacity;
}

void pushFront(Deque* dq, State s) {
    dq->head--;
    dq->data[dq->head] = s;
}

void pushBack(Deque* dq, State s) {
    dq->data[dq->tail] = s;
    dq->tail++;
}

State popFront(Deque* dq) {
    return dq->data[dq->head++];
}

int isEmpty(Deque* dq) {
    return dq->head == dq->tail;
}

void freeDeque(Deque* dq) {
    free(dq->data);
}

void addEdge(Edge** adj, int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;
}

int main() {
    int V, E, S, C;
    if (scanf("%d %d %d %d", &V, &E, &S, &C) != 4) return 0;

    Edge** adj = (Edge**)calloc(V + 1, sizeof(Edge*));
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    // dist[v][parity]: 0 for even, 1 for odd
    int dist[V + 1][2];
    for (int i = 1; i <= V; ++i) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    Deque dq;
    initDeque(&dq, 4 * V + 4);

    // Source starts with weight 0 (even parity)
    dist[S][0] = 0;
    pushBack(&dq, (State){S, 0});

    while (!isEmpty(&dq)) {
        State cur = popFront(&dq);
        int u = cur.u;
        int p = cur.parity;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;
            int next_p = (p + w) % 2;

            if (dist[u][p] + w < dist[v][next_p]) {
                dist[v][next_p] = dist[u][p] + w;
                if (w == 0) {
                    pushFront(&dq, (State){v, next_p});
                } else {
                    pushBack(&dq, (State){v, next_p});
                }
            }
        }
    }

    printf("Vertex\tMin Effective Cost\n");
    for (int v = 1; v <= V; ++v) {
        int best = INF;
        if (dist[v][0] != INF) {
            int cost_even = dist[v][0];
            if (cost_even < best) best = cost_even;
        }
        if (dist[v][1] != INF) {
            int cost_odd = dist[v][1] + C;
            if (cost_odd < best) best = cost_odd;
        }

        if (best == INF) {
            printf("%d\tUnreachable\n", v);
        } else {
            printf("%d\t%d\n", v, best);
        }
    }

    // Cleanup
    for (int i = 1; i <= V; ++i) {
        Edge* curr = adj[i];
        while (curr) {
            Edge* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(adj);
    freeDeque(&dq);

    return 0;
}