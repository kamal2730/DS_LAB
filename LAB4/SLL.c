#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int d;
    struct N* nxt;
} N;

N* head = NULL;

void add_at_start(int d) {
    N* nn = (N*)malloc(sizeof(N));
    nn->d = d;
    nn->nxt = head;
    head = nn;
}

void add_after(int d, int after) {
    N* tmp = head;
    while (tmp != NULL) {
        if (tmp->d == after) {
            N* nn = (N*)malloc(sizeof(N));
            nn->d = d;
            nn->nxt = tmp->nxt;
            tmp->nxt = nn;
            return;
        }
        tmp = tmp->nxt;
    }
    printf("not found.\n");
}

void add_before(int d, int before) {
    if (head && head->d == before) {
        add_at_start(d);
        return;
    }

    N* tmp = head;
    while (tmp && tmp->nxt) {
        if (tmp->nxt->d == before) {
            N* nn = (N*)malloc(sizeof(N));
            nn->d = d;
            nn->nxt = tmp->nxt;
            tmp->nxt = nn;
            return;
        }
        tmp = tmp->nxt;
    }
    printf("not found.\n");
}

void del(int d) {
    if (!head) {
        printf("Empty List!\n");
        return;
    }

    if (head->d == d) {
        N* tmp = head;
        head = head->nxt;
        free(tmp);
        printf("Deleted!\n");
        return;
    }

    N* tmp = head;
    while (tmp && tmp->nxt) {
        if (tmp->nxt->d == d) {
            N* del = tmp->nxt;
            tmp->nxt = tmp->nxt->nxt;
            free(del);
            printf("Deleted!\n");
            return;
        }
        tmp = tmp->nxt;
    }
    printf("Node with data %d not found.\n", d);
}

void display() {
    N* tmp = head;
    if (!tmp) {
        printf("List is empty!\n");
        return;
    }
    while (tmp) {
        printf("->%d", tmp->d);
        tmp = tmp->nxt;
    }
    printf("\n");
}

void reverse() {
    N *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed!\n");
}

void sort() {
    if (!head) return;
    N *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->nxt) {
        for (j = i->nxt; j != NULL; j = j->nxt) {
            if (i->d > j->d) {
                temp = i->d;
                i->d = j->d;
                j->d = temp;
            }
        }
    }
    printf("List sorted!\n");
}

void delete_alternate_nodes() {
    if (!head || !head->nxt) return;

    N* tmp = head;
    while (tmp && tmp->nxt) {
        N* to_delete = tmp->nxt;
        tmp->nxt = tmp->nxt ? tmp->nxt->nxt : NULL;
        free(to_delete);
        tmp = tmp->nxt;
    }
    printf("Deleted alternate nodes!\n");
}

void insert_sorted(int d) {
    N* nn = (N*)malloc(sizeof(N));
    nn->d = d;
    nn->nxt = NULL;

    if (!head || head->d >= d) {
        nn->nxt = head;
        head = nn;
        return;
    }

    N* tmp = head;
    while (tmp->nxt && tmp->nxt->d < d) {
        tmp = tmp->nxt;
    }
    nn->nxt = tmp->nxt;
    tmp->nxt = nn;
    printf("Node inserted in sorted order.\n");
}

int main() {
    int opt, d, after_data, before_data;
    printf("\n1. Add at start\n2. Insert after\n3. Insert before\n4. Delete element\n5. Display elements\n6. Reverse list\n7. Sort list\n8. Delete alternate nodes\n9. Insert in sorted list\n10. Exit\nChoose an option: ");
    while (1) {

        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &d);
                add_at_start(d);
                break;
            case 2:
                printf("Enter data to insert and after which element: ");
                scanf("%d %d", &d, &after_data);
                add_after(d, after_data);
                break;
            case 3:
                printf("Enter data to insert and before which element: ");
                scanf("%d %d", &d, &before_data);
                add_before(d, before_data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &d);
                del(d);
                break;
            case 5:
                display();
                break;
            case 6:
                reverse();
                break;
            case 7:
                sort();
                break;
            case 8:
                delete_alternate_nodes();
                break;
            case 9:
                printf("Enter data to insert into sorted list: ");
                scanf("%d", &d);
                insert_sorted(d);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
