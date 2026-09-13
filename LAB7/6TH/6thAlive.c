#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int type; // -1 for death, +1 for birth (death processed first on ties)
} Event;

int compare_events(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->year != e2->year) {
        return e1->year - e2->year;
    }
    return e1->type - e2->type; // -1 comes before +1
}

void find_best_year() {
    // Sample input: [birth, death]
    int lifespans[][2] = {
        {1643, 1727}, // Newton
        {1564, 1642}, // Galileo
        {1571, 1630}, // Kepler
        {1623, 1662}, // Pascal
        {1646, 1716}  // Leibniz
    };
    int m = sizeof(lifespans) / sizeof(lifespans[0]);
    Event events[2 * m];

    int idx = 0;
    for (int i = 0; i < m; i++) {
        events[idx++] = (Event){lifespans[i][0], +1};
        events[idx++] = (Event){lifespans[i][1], -1};
    }

    qsort(events, 2 * m, sizeof(Event), compare_events);

    int current_alive = 0, max_alive = 0, best_year = -1;
    for (int i = 0; i < 2 * m; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            best_year = events[i].year;
        }
    }

    printf("--- Q6: Best Time to Be Alive ---\n");
    printf("Peak Year: %d with %d scientists alive simultaneously.\n", best_year, max_alive);
}

int main() {
    find_best_year();
    return 0;
}