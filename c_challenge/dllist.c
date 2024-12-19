#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        char *str;
        struct Node *prev;
        struct Node *next;
} Node;

typedef struct DoublyLinkedList {
        Node *head;
        Node *tail;
} DoublyLinkedList;

DoublyLinkedList *createList() {
        DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
        if (list == NULL) {
                printf("Memory allocation failed for the list\n");
                return NULL;
        }

        list->head = NULL;
        list->tail = NULL;

        return list;
}

Node *createNode(const char *str) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
                printf("Memory allocation failed for the node\n");
                return NULL;
        }

        newNode->str = (char *)malloc(strlen(str) + 1);
        if (newNode->str == NULL) {
                printf("Memory allocation failed for the string\n");
                free(newNode);
                return NULL;
        }
        strcpy(newNode->str, str);

        newNode->prev = NULL;
        newNode->next = NULL;

        return newNode;
}

void appendNode(DoublyLinkedList *list, const char *str) {
        Node *newNode = createNode(str);
        if (newNode == NULL) return;

        if (list->tail == NULL) {
                list->head = newNode;
                list->tail = newNode;
        } else {
                list->tail->next = newNode;
                newNode->prev = list->tail;
                list->tail = newNode;
        }
}

int retrieveList(DoublyLinkedList *list, const char *str) {
        int idx = -1;
        int i = 0;
        Node *current = list->head;
        while (current != NULL) {
                Node *temp = current;
                current = current->next;

                if (strcmp(temp->str, str) == 0) {
                        idx = i;
                        break;
                }

                i++;
        }

        return idx;
}

void deleteNode(DoublyLinkedList *list, const char *str) {
        Node *current = list->head;
        while (current != NULL) {
                Node *temp = current;
                current = current->next;

                if (strcmp(temp->str, str) == 0) {
                        if (temp->prev == NULL) {
                                list->head = temp->next;
                        }
                        if (temp->next == NULL) {
                                list->tail = temp->prev;
                        }

                        Node *newNext = temp->next;
                        Node *newPrev = temp->prev;

                        temp->prev->next = newNext;
                        temp->next->prev = newPrev;

                        free(temp->str);
                        free(temp);
                        break;
                }
        }
}

void printList(DoublyLinkedList *list) {
        Node *current = list->head;
        while (current != NULL) {
                printf("%s\n", current->str);
                current = current->next;
        }
}

void freeList(DoublyLinkedList *list) {
        Node *current = list->head;
        while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp->str);
                free(temp);
        }
        free(list);
}

int main() {
        DoublyLinkedList *list = createList();

        appendNode(list, "Hello");
        appendNode(list, "World");
        appendNode(list, "Doubly Linked List in C");

        printf("List contents:\n");
        printList(list);

        int idx = retrieveList(list, "World");
        printf("\"Hello\" is found at index %d\n", idx);

        deleteNode(list, "World");
        int idx2 = retrieveList(list, "World");
        printf("\"Hello\" is found at index %d\n", idx2);

        freeList(list);

        return 0;
}
