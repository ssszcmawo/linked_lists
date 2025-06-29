#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insert_begin(Node **head, int data);

void insert_end(Node **head, int data);

void insert_before(Node **head, int target, int data);

void delete_node(Node **head, int key);

void find_node(Node **head, int key);

void print_list(Node **head);

void free_list(Node **head);


#endif //DOUBLYLINKEDLIST_H
