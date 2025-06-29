#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void push_front(Node **head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void push_back(Node **head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteNode(Node **head, int key) {
    Node *current = *head;
    Node *prev = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;

    prev->next = current->next;
    free(current);
}

void freeList(Node *head) {
    struct Node *current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
