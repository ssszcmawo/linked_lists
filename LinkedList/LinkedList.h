#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push_front(Node **head, int data);

void push_back(Node **head, int data);

void deleteNode(Node **head, int key);

void freeList(Node *head);

void printList(Node *node);

#endif //LINKEDLIST_H
