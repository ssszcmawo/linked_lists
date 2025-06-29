#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void insert_begin(Node **head, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insert_end(Node **head, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    Node *last = *head;

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void insert_before(Node **head, int target, int data) {
    Node *current = *head;

    if (current == NULL) return;

    if (current->data == target) {
        insert_begin(head, data);
        return;
    }

    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) return;

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current;
    new_node->prev = current->prev;

    current->prev->next = new_node;
    current->prev = new_node;
}

void delete_node(Node **head, int key) {
    Node *current = *head;

    while (current != NULL && current->data == key) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current == *head) {
        *head = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void find_node(Node **head, int key) {
    Node *current = *head;
    while (current != NULL && current->data != key) {
        if (current->data == key) {
            printf("%d", current->data);
        }
        current = current->next;
    }
    if (current == NULL) return;
}

void print_list(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeDoublylist(Node *head) {
    struct Node *current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}
