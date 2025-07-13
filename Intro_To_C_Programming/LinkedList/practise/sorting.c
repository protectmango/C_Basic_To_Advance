#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to perform bubble sort on the linked list
struct ListNode* bubbleSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int swapped;
    struct ListNode *ptr1;
    struct ListNode *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                // Swap the values
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Helper function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example 1
    struct ListNode* head1 = newNode(4);
    head1->next = newNode(2);
    head1->next->next = newNode(1);
    head1->next->next->next = newNode(3);
    
    printf("Original list 1: ");
    printList(head1);
    head1 = bubbleSortList(head1);
    printf("Sorted list 1: ");
    printList(head1);
    freeList(head1);
    
    // Example 2
    struct ListNode* head2 = newNode(-1);
    head2->next = newNode(5);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = newNode(0);
    
    printf("Original list 2: ");
    printList(head2);
    head2 = bubbleSortList(head2);
    printf("Sorted list 2: ");
    printList(head2);
    freeList(head2);
    
    // Example 3
    struct ListNode* head3 = NULL;
    
    printf("Original list 3: ");
    printList(head3);
    head3 = bubbleSortList(head3);
    printf("Sorted list 3: ");
    printList(head3);
    freeList(head3);
    
    return 0;
}
