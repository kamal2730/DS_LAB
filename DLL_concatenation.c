#include <stdio.h>
#include <stdlib.h>

struct N {
    int data;
    struct N* next;
    struct N* prev;
};

void concat(struct N* X1, struct N* X2) {
    if (X1 == NULL) {
        X1 = X2;
        return;
    }
    struct N* temp = X1;
    while (temp->next) temp = temp->next;
    temp->next = X2;
    if (X2) X2->prev = temp;
}

void printList(struct N* head) {
    struct N* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct N* createList() {
    int n, val;
    struct N *head = NULL, *tail = NULL;
    printf("n:");
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        struct N* nn = (struct N*)malloc(sizeof(struct N));
        nn->data = val;
        nn->next = NULL;
        nn->prev = tail;
        if (tail) tail->next = nn;
        else head = nn;
        tail = nn;
    }
    return head;
}

int main() {
    struct N* X1 = createList();
    struct N* X2 = createList();
    concat(X1, X2);
    printList(X1);
    return 0;
}
