#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
/* --- Shared Data Structures --- */
typedef struct {
    int* data;
    int size;
} Array;

typedef struct SNode {
    int key;
    struct SNode* next;
} SNode;

typedef struct DNode {
    int key;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct {
    DNode* head;
    DNode* tail;
} DList;

/* ================= 1. UNSORTED ARRAY ================= */
int UA_Search(Array* arr, int k) {
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] == k) return i;
    return -1;
}
void UA_Insert(Array* arr, int x) {
    arr->data[arr->size++] = x;
}
void UA_Delete(Array* arr, int index) {
    arr->data[index] = arr->data[--arr->size];
}
int UA_Max(Array* arr) {
    int max = INT_MIN;
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] > max) max = arr->data[i];
    return max;
}
int UA_Min(Array* arr) {
    int min = INT_MAX;
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] < min) min = arr->data[i];
    return min;
}
int UA_Pred(Array* arr, int idx) {
    int pred = INT_MIN;
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] < arr->data[idx] && arr->data[i] > pred) pred = arr->data[i];
    return pred;
}
int UA_Succ(Array* arr, int idx) {
    int succ = INT_MAX;
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] > arr->data[idx] && arr->data[i] < succ) succ = arr->data[i];
    return succ;
}

/* ================= 2. SORTED ARRAY ================= */
int SA_Search(Array* arr, int k) {
    int low = 0, high = arr->size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr->data[mid] == k) return mid;
        if (arr->data[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
void SA_Insert(Array* arr, int x) {
    int i = arr->size - 1;
    while (i >= 0 && arr->data[i] > x) {
        arr->data[i + 1] = arr->data[i];
        i--;
    }
    arr->data[i + 1] = x;
    arr->size++;
}
void SA_Delete(Array* arr, int idx) {
    for (int i = idx; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];
    arr->size--;
}
int SA_Max(Array* arr) { return arr->size ? arr->data[arr->size - 1] : INT_MIN; }
int SA_Min(Array* arr) { return arr->size ? arr->data[0] : INT_MAX; }
int SA_Pred(Array* arr, int idx) { return idx > 0 ? arr->data[idx - 1] : INT_MIN; }
int SA_Succ(Array* arr, int idx) { return idx < arr->size - 1 ? arr->data[idx + 1] : INT_MAX; }

/* ================= 3. SINGLY LINKED UNSORTED ================= */
SNode* SLLU_Search(SNode* head, int k) {
    while (head) {
        if (head->key == k) return head;
        head = head->next;
    }
    return NULL;
}
void SLLU_Insert(SNode** head, int x) {
    SNode* newNode = malloc(sizeof(SNode));
    newNode->key = x;
    newNode->next = *head;
    *head = newNode;
}
void SLLU_Delete(SNode** head, SNode* target) {
    if (*head == target) {
        *head = (*head)->next;
        free(target);
        return;
    }
    SNode* curr = *head;
    while (curr && curr->next != target) curr = curr->next;
    if (curr) {
        curr->next = target->next;
        free(target);
    }
}
int SLLU_Max(SNode* head) {
    int max = INT_MIN;
    while (head) {
        if (head->key > max) max = head->key;
        head = head->next;
    }
    return max;
}
int SLLU_Min(SNode* head) {
    int min = INT_MAX;
    while (head) {
        if (head->key < min) min = head->key;
        head = head->next;
    }
    return min;
}
int SLLU_Pred(SNode* head, SNode* target) {
    int pred = INT_MIN;
    while (head) {
        if (head->key < target->key && head->key > pred) pred = head->key;
        head = head->next;
    }
    return pred;
}
int SLLU_Succ(SNode* head, SNode* target) {
    int succ = INT_MAX;
    while (head) {
        if (head->key > target->key && head->key < succ) succ = head->key;
        head = head->next;
    }
    return succ;
}

/* ================= 4. SINGLY LINKED SORTED ================= */
SNode* SLLS_Search(SNode* head, int k) {
    while (head && head->key <= k) {
        if (head->key == k) return head;
        head = head->next;
    }
    return NULL;
}
void SLLS_Insert(SNode** head, int x) {
    SNode* newNode = malloc(sizeof(SNode));
    newNode->key = x;
    if (!*head || (*head)->key >= x) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    SNode* curr = *head;
    while (curr->next && curr->next->key < x) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
}
void SLLS_Delete(SNode** head, SNode* target) { SLLU_Delete(head, target); }
int SLLS_Max(SNode* head) {
    if (!head) return INT_MIN;
    while (head->next) head = head->next;
    return head->key;
}
int SLLS_Min(SNode* head) { return head ? head->key : INT_MAX; }
SNode* SLLS_Pred(SNode* head, SNode* target) {
    if (head == target || !head) return NULL;
    while (head->next && head->next != target) head = head->next;
    return head;
}
SNode* SLLS_Succ(SNode* target) { return target ? target->next : NULL; }

/* ================= 5. DOUBLY LINKED UNSORTED ================= */
DNode* DLLU_Search(DNode* head, int k) {
    while (head) {
        if (head->key == k) return head;
        head = head->next;
    }
    return NULL;
}
void DLLU_Insert(DNode** head, int x) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->key = x;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}
void DLLU_Delete(DNode** head, DNode* target) {
    if (*head == target) *head = target->next;
    if (target->next) target->next->prev = target->prev;
    if (target->prev) target->prev->next = target->next;
    free(target);
}
int DLLU_Max(DNode* head) {
    int max = INT_MIN;
    while (head) {
        if (head->key > max) max = head->key;
        head = head->next;
    }
    return max;
}
int DLLU_Min(DNode* head) {
    int min = INT_MAX;
    while (head) {
        if (head->key < min) min = head->key;
        head = head->next;
    }
    return min;
}
int DLLU_Pred(DNode* head, DNode* target) {
    int pred = INT_MIN;
    while (head) {
        if (head->key < target->key && head->key > pred) pred = head->key;
        head = head->next;
    }
    return pred;
}
int DLLU_Succ(DNode* head, DNode* target) {
    int succ = INT_MAX;
    while (head) {
        if (head->key > target->key && head->key < succ) succ = head->key;
        head = head->next;
    }
    return succ;
}

/* ================= 6. DOUBLY LINKED SORTED ================= */
DNode* DLLS_Search(DList* list, int k) {
    DNode* curr = list->head;
    while (curr && curr->key <= k) {
        if (curr->key == k) return curr;
        curr = curr->next;
    }
    return NULL;
}
void DLLS_Insert(DList* list, int x) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->key = x;
    newNode->prev = newNode->next = NULL;
    
    if (!list->head) {
        list->head = list->tail = newNode;
        return;
    }
    if (list->head->key >= x) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        return;
    }
    
    DNode* curr = list->head;
    while (curr->next && curr->next->key < x) curr = curr->next;
    
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next) curr->next->prev = newNode;
    else list->tail = newNode;
    curr->next = newNode;
}
void DLLS_Delete(DList* list, DNode* target) {
    if (list->head == target) list->head = target->next;
    if (list->tail == target) list->tail = target->prev;
    if (target->next) target->next->prev = target->prev;
    if (target->prev) target->prev->next = target->next;
    free(target);
}
int DLLS_Max(DList* list) { return list->tail ? list->tail->key : INT_MIN; }
int DLLS_Min(DList* list) { return list->head ? list->head->key : INT_MAX; }
DNode* DLLS_Pred(DNode* target) { return target ? target->prev : NULL; } 
DNode* DLLS_Succ(DNode* target) { return target ? target->next : NULL; }

//======================================GRAPH CODE=========================================

void generate_complexity_svg(const char* filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error opening file!\n");
        return;
    }

    // SVG Header
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"900\" height=\"650\">\n");
    fprintf(f, "  <rect width=\"100%%\" height=\"100%%\" fill=\"#1e1e1e\"/>\n"); // Dark background

    // Grid lines
    for (int i = 50; i <= 800; i += 50) {
        fprintf(f, "  <line x1=\"%d\" y1=\"50\" x2=\"%d\" y2=\"550\" stroke=\"#333\" stroke-width=\"1\"/>\n", i, i);
        fprintf(f, "  <line x1=\"50\" y1=\"%d\" x2=\"800\" y2=\"%d\" stroke=\"#333\" stroke-width=\"1\"/>\n", i, i);
    }

    // Axes
    fprintf(f, "  <line x1=\"50\" y1=\"550\" x2=\"820\" y2=\"550\" stroke=\"white\" stroke-width=\"2\"/>\n"); // X-Axis (N)
    fprintf(f, "  <line x1=\"50\" y1=\"550\" x2=\"50\" y2=\"30\" stroke=\"white\" stroke-width=\"2\"/>\n");  // Y-Axis (Time)
    fprintf(f, "  <text x=\"400\" y=\"590\" fill=\"white\" font-family=\"sans-serif\" font-size=\"16\">Number of Elements (N)</text>\n");
    fprintf(f, "  <text x=\"20\" y=\"300\" fill=\"white\" font-family=\"sans-serif\" font-size=\"16\" transform=\"rotate(-90 20,300)\">Time Taken</text>\n");
    fprintf(f, "  <text x=\"50\" y=\"25\" fill=\"white\" font-family=\"sans-serif\" font-size=\"18\" font-weight=\"bold\">Asymptotic Time Complexity Comparison</text>\n");

    // Plotting the curves
    fprintf(f, "  <polyline fill=\"none\" stroke=\"#4ade80\" stroke-width=\"4\" points=\""); // Green O(1)
    for (int x = 50; x <= 800; x += 10) fprintf(f, "%d,%d ", x, 530); // Constant time
    fprintf(f, "\"/>\n");

    fprintf(f, "  <polyline fill=\"none\" stroke=\"#60a5fa\" stroke-width=\"4\" points=\""); // Blue O(log N)
    for (int x = 50; x <= 800; x += 5) {
        double n = (x - 50);
        double y = 550 - (n > 0 ? 30 * log(n + 1) : 0); // Scale log curve
        fprintf(f, "%d,%d ", x, (int)y);
    }
    fprintf(f, "\"/>\n");

    fprintf(f, "  <polyline fill=\"none\" stroke=\"#f87171\" stroke-width=\"4\" points=\""); // Red O(N)
    for (int x = 50; x <= 800; x += 10) {
        double y = 550 - 0.6 * (x - 50); // Scale linear curve
        if (y > 40) fprintf(f, "%d,%d ", x, (int)y);
    }
    fprintf(f, "\"/>\n");

    // Curve Labels
    fprintf(f, "  <text x=\"750\" y=\"515\" fill=\"#4ade80\" font-family=\"monospace\" font-size=\"18\">O(1)</text>\n");
    fprintf(f, "  <text x=\"750\" y=\"330\" fill=\"#60a5fa\" font-family=\"monospace\" font-size=\"18\">O(log N)</text>\n");
    fprintf(f, "  <text x=\"750\" y=\"110\" fill=\"#f87171\" font-family=\"monospace\" font-size=\"18\">O(N)</text>\n");

    // Legend panel
    fprintf(f, "  <rect x=\"80\" y=\"50\" width=\"400\" height=\"190\" fill=\"#2d2d2d\" stroke=\"#555\" rx=\"5\"/>\n");
    fprintf(f, "  <text x=\"95\" y=\"75\" fill=\"white\" font-family=\"sans-serif\" font-size=\"14\" font-weight=\"bold\">Performance by Data Structure:</text>\n");
    
    // Legend content
    const char* legend[] = {
        "<tspan fill=\"#f87171\">O(N)</tspan> Search, <tspan fill=\"#4ade80\">O(1)</tspan> Insert : Unsorted Array, DLL (Unsorted)",
        "<tspan fill=\"#60a5fa\">O(log N)</tspan> Search, <tspan fill=\"#f87171\">O(N)</tspan> Insert : Sorted Array",
        "<tspan fill=\"#f87171\">O(N)</tspan> Search, <tspan fill=\"#f87171\">O(N)</tspan> Insert : SLL (Sorted), DLL (Sorted)",
        "<tspan fill=\"#f87171\">O(N)</tspan> Search, <tspan fill=\"#4ade80\">O(1)</tspan> Delete : DLL (Sorted &amp; Unsorted)",
        "<tspan fill=\"#f87171\">O(N)</tspan> Search, <tspan fill=\"#4ade80\">O(1)</tspan> Insert : SLL (Unsorted)"
    };

    for (int i = 0; i < 5; i++) {
        fprintf(f, "  <text x=\"95\" y=\"%d\" fill=\"#ccc\" font-family=\"sans-serif\" font-size=\"13\">%s</text>\n", 100 + (i * 25), legend[i]);
    }

    fprintf(f, "</svg>\n");
    fclose(f);
    printf("SVG graph successfully generated as '%s'. Open it in any web browser.\n", filename);
}


/* ================= TEST / MAIN ================= */
int main() {
    DList list = {NULL, NULL};
    DLLS_Insert(&list, 10);
    DLLS_Insert(&list, 5);
    DLLS_Insert(&list, 202);
    DLLS_Insert(&list, 101);
    DLLS_Insert(&list, 52);
    DLLS_Insert(&list, 201);
    DLLS_Insert(&list, 13);
    DLLS_Insert(&list, 54);
    DLLS_Insert(&list, 1);
    
    printf("Min: %d, Max: %d\n", DLLS_Min(&list), DLLS_Max(&list)); 


    generate_complexity_svg("complexity_graph.svg");//CALLING THE SVG FUNCTION TO CREATE THE SVG FILE FOR THE GRAPH
    return 0;
}
