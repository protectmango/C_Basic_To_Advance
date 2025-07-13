// linked_list.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Definition of a generic Node for the linked list
struct Node {
    void *data;         // Pointer to the actual data (e.g., struct Student*)
    struct Node *next;  
};


struct Node *create_node(void *data);

void add_node(struct Node **head, void *data);

void display_list(const struct Node *head, void (*print_func)(const void*));

void free_list(struct Node **head, void (*free_data_func)(void *));

#endif // LINKED_LIST_H
