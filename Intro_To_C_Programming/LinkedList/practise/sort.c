#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Function to find the middle of the list and split it into two halves
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (prev) {
        prev->next = NULL; // Split the list into two halves
    }
    
    return slow;
}

// Merge sort function for linked list
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* mid = findMiddle(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    
    return merge(left, right);
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
    head1 = sortList(head1);
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
    head2 = sortList(head2);
    printf("Sorted list 2: ");
    printList(head2);
    freeList(head2);
    
    // Example 3
    struct ListNode* head3 = NULL;
    
    printf("Original list 3: ");
    printList(head3);
    head3 = sortList(head3);
    printf("Sorted list 3: ");
    printList(head3);
    freeList(head3);
    
    return 0;
}
