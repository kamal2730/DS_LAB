#include <stdio.h>
#include <stdlib.h>

struct N {
    int data;
    struct N* next;
    struct N* prev;
};

struct N* head = NULL;
struct N* tail = NULL;

void append(int value) {
    struct N* nn = (struct N*)malloc(sizeof(struct N));
    nn->data = value;
    nn->next = NULL;
    if (!head) {
        head = tail = nn;
        nn->prev = NULL;
    } else {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

void deleteRear() {
    if (tail) {
        struct N* temp = tail;
        if (head == tail) head = tail = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        free(temp);
    }
}

void insertAtPos(int value, int pos) {
    if (pos == 1) {
        struct N* nn = (struct N*)malloc(sizeof(struct N));
        nn->data = value;
        nn->next = head;
        nn->prev = NULL;
        if (head) head->prev = nn;
        head = nn;
        return;
    }
    struct N* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (temp) {
        struct N* nn = (struct N*)malloc(sizeof(struct N));
        nn->data = value;
        nn->next = temp->next;
        nn->prev = temp;
        if (temp->next) temp->next->prev = nn;
        temp->next = nn;
    }
}

void deleteAtPos(int pos) {
    struct N* temp = head;
    for (int i = 1; temp && i < pos; i++) temp = temp->next;
    if (temp) {
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;
        free(temp);
    }
}

void insertAfterValue(int value, int target) {
    struct N* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp) {
        struct N* nn = (struct N*)malloc(sizeof(struct N));
        nn->data = value;
        nn->next = temp->next;
        nn->prev = temp;
        if (temp->next) temp->next->prev = nn;
        temp->next = nn;
    }
}

void insertBeforeValue(int value, int target) {
    struct N* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp) {
        struct N* nn = (struct N*)malloc(sizeof(struct N));
        nn->data = value;
        nn->prev = temp->prev;
        nn->next = temp;
        if (temp->prev) temp->prev->next = nn;
        if (temp == head) head = nn;
        temp->prev = nn;
    }
}

void forwardTraverse() {
    struct N* temp = head;
    while (temp) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraverse() {
    struct N* temp = tail;
    while (temp) {
        printf("->%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value, pos, target;
    printf("\n1. Append\n2. Delete Rear\n3. Insert at Position\n4. Delete at Position\n5. Insert After Value\n6. Insert Before Value\n7. Forward Traverse\n8. Reverse Traverse\n9. Exit\n");
    while (1) {
        printf("choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                append(value);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPos(value, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 5:
                printf("value and target: ");
                scanf("%d %d", &value, &target);
                insertAfterValue(value, target);
                break;
            case 6:
                printf("Enter value to insert and target value: ");
                scanf("%d %d", &value, &target);
                insertBeforeValue(value, target);
                break;
            case 7:
                forwardTraverse();
                break;
            case 8:
                reverseTraverse();
                break;
            case 9:
                exit(0);
        }
    }
    return 0;
}
