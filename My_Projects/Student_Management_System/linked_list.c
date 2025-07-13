//linked_list.c

#include "linked_list.h"
#include <stdlib.h> // For malloc
#include <stdio.h>  // For printf

struct Node *create_node(void *data){
	struct Node *s = (struct Node *)malloc(sizeof(struct Node));

	if(s == NULL)
	{
		perror("Memory Allocation failed for Node");
		return NULL;
	}

	s->data = data;
	s->next = NULL;

	return s;
}

void add_node ( struct Node **head, void *data)
{
	struct Node *s  = create_node(data);

	if(*head == NULL)
	{
		*head = s;
	}else{
		struct Node *current = *head;
		while(current->next != NULL)
		{
			current = current->next;
		}

		current->next = s;
	}
}

void display_list(const struct Node *head, void (*print_func)(const void*))
{
	const struct Node *current = head;

	printf("\n--- Displaying List Content ---\n");
	while (current != NULL) // Loop until current becomes NULL (after the last node)
	{
		if (print_func != NULL) { // Ensure the print function pointer is not NULL
			print_func(current->data); // Call the provided function to print the data
		} else {
			printf("Node data address: %p (No print function provided)\n", current->data);
		}
		current = current->next; // Move to the next node
	}
	printf("--- End of List Display ---\n\n");
}

void free_list(struct Node **head , void (*free_data_func)(void *))
{
	struct Node *current = *head;
	struct Node *nextNode ;

	while( current != NULL)
	{
		nextNode = current->next; // Store the next node before freeing the current one
		if(free_data_func != NULL && current->data != NULL)
		{
			free_data_func(current->data);// Free the data pointed to by the node
		}
		free(current);// Free the node itself
		current = nextNode;// Move to the next node
	}

	*head = NULL;// Set the head to NULL to indicate the list is empty
	 printf("Linked list and its data freed successfully.\n");
}

