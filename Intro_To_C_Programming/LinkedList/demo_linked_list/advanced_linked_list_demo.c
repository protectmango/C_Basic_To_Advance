#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

// ANSI color codes for better visualization
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
    int node_id;  // For tracking purposes
} Node;

// Global variables for demonstration
static int node_counter = 0;
static size_t total_memory_allocated = 0;
static int operation_counter = 0;

// Function prototypes
Node* create_node(int data);
void insert_at_beginning(Node** head, int data);
void insert_at_end(Node** head, int data);
void insert_at_position(Node** head, int data, int position);
void delete_node(Node** head, int data);
void display_list(Node* head);
void display_memory_layout(Node* head);
void display_node_details(Node* node);
void visualize_memory_allocation();
void demonstrate_stack_vs_heap();
void show_pointer_relationships(Node* head);
void interactive_menu();
void cleanup_list(Node** head);
int get_list_length(Node* head);
void reverse_list(Node** head);
void search_element(Node* head, int data);
void print_separator();
void print_header(const char* title);
void animate_insertion(Node** head, int data, int position);
void show_frame_by_frame_insertion(Node** head, int data);

// Create a new node and demonstrate memory allocation
Node* create_node(int data) {
    printf("\n%s🔧 CREATING NEW NODE%s\n", BOLD CYAN, RESET);
    printf("📊 Requesting memory from heap...\n");
    
    // Show memory allocation process
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (new_node == NULL) {
        printf("%s❌ Memory allocation failed!%s\n", RED, RESET);
        return NULL;
    }
    
    // Track memory usage
    total_memory_allocated += sizeof(Node);
    node_counter++;
    
    // Initialize node
    new_node->data = data;
    new_node->next = NULL;
    new_node->node_id = node_counter;
    
    printf("✅ Memory allocated successfully!\n");
    printf("📍 Node address: %s%p%s\n", GREEN, (void*)new_node, RESET);
    printf("📏 Node size: %s%zu bytes%s\n", YELLOW, sizeof(Node), RESET);
    printf("🆔 Node ID: %s%d%s\n", BLUE, new_node->node_id, RESET);
    printf("📦 Data stored: %s%d%s\n", MAGENTA, new_node->data, RESET);
    printf("🔗 Next pointer: %s%p%s (NULL initially)\n", CYAN, (void*)new_node->next, RESET);
    
    return new_node;
}

// Insert at beginning with detailed explanation
void insert_at_beginning(Node** head, int data) {
    printf("\n%s🚀 INSERTING AT BEGINNING%s\n", BOLD GREEN, RESET);
    
    Node* new_node = create_node(data);
    if (new_node == NULL) return;
    
    printf("\n📋 Step-by-step process:\n");
    printf("1️⃣ Created new node at address %p\n", (void*)new_node);
    
    if (*head == NULL) {
        printf("2️⃣ List is empty, new node becomes head\n");
        *head = new_node;
    } else {
        printf("2️⃣ Current head: %p\n", (void*)*head);
        printf("3️⃣ Setting new node's next to current head\n");
        new_node->next = *head;
        printf("4️⃣ Updating head pointer to new node\n");
        *head = new_node;
    }
    
    printf("✅ Insertion completed!\n");
    operation_counter++;
}

// Detailed frame-by-frame insertion demonstration
void show_frame_by_frame_insertion(Node** head, int data) {
    printf("\n%s🎬 FRAME-BY-FRAME INSERTION ANIMATION%s\n", BOLD YELLOW, RESET);
    printf("Inserting %d at the beginning...\n\n", data);
    
    // Frame 1: Show current state
    printf("📺 FRAME 1 - Current State:\n");
    if (*head == NULL) {
        printf("HEAD -> NULL\n");
    } else {
        printf("HEAD -> ");
        Node* temp = *head;
        while (temp != NULL) {
            printf("[%d|%p] -> ", temp->data, (void*)temp->next);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("\nPress Enter to continue...");
    getchar();
    
    // Frame 2: Create new node
    printf("\n📺 FRAME 2 - Creating New Node:\n");
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->node_id = ++node_counter;
    total_memory_allocated += sizeof(Node);
    
    printf("NEW_NODE -> [%d|NULL] (at address %p)\n", data, (void*)new_node);
    if (*head != NULL) {
        printf("HEAD -> ");
        Node* temp = *head;
        while (temp != NULL) {
            printf("[%d|%p] -> ", temp->data, (void*)temp->next);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("\nPress Enter to continue...");
    getchar();
    
    // Frame 3: Link new node
    printf("\n📺 FRAME 3 - Linking New Node:\n");
    new_node->next = *head;
    printf("NEW_NODE -> [%d|%p] (next now points to old head)\n", 
           data, (void*)new_node->next);
    if (*head != NULL) {
        printf("OLD_HEAD -> ");
        Node* temp = *head;
        while (temp != NULL) {
            printf("[%d|%p] -> ", temp->data, (void*)temp->next);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("\nPress Enter to continue...");
    getchar();
    
    // Frame 4: Update head
    printf("\n📺 FRAME 4 - Updating Head Pointer:\n");
    *head = new_node;
    printf("HEAD -> [%d|%p] -> ", new_node->data, (void*)new_node->next);
    Node* temp = new_node->next;
    while (temp != NULL) {
        printf("[%d|%p] -> ", temp->data, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("\n✅ Insertion Complete!\n");
    operation_counter++;
}

// Insert at end with memory tracking
void insert_at_end(Node** head, int data) {
    printf("\n%s🎯 INSERTING AT END%s\n", BOLD BLUE, RESET);
    
    Node* new_node = create_node(data);
    if (new_node == NULL) return;
    
    if (*head == NULL) {
        printf("📝 List is empty, new node becomes head\n");
        *head = new_node;
        return;
    }
    
    printf("\n🔍 Traversing to find the last node...\n");
    Node* current = *head;
    int position = 1;
    
    while (current->next != NULL) {
        printf("   Position %d: Node %d (address: %p) -> next: %p\n", 
               position, current->data, (void*)current, (void*)current->next);
        current = current->next;
        position++;
    }
    
    printf("🎯 Found last node at position %d: Node %d (address: %p)\n", 
           position, current->data, (void*)current);
    printf("🔗 Linking last node to new node...\n");
    current->next = new_node;
    
    printf("✅ New node attached at the end!\n");
    operation_counter++;
}

// Display list with detailed memory information
void display_list(Node* head) {
    printf("\n%s📋 LINKED LIST VISUALIZATION%s\n", BOLD WHITE, RESET);
    
    if (head == NULL) {
        printf("🔍 List is empty\n");
        printf("HEAD -> NULL\n");
        return;
    }
    
    printf("📊 List Statistics:\n");
    printf("   • Total nodes: %d\n", get_list_length(head));
    printf("   • Memory used: %zu bytes\n", total_memory_allocated);
    printf("   • Operations performed: %d\n\n", operation_counter);
    
    printf("🔗 Node-by-Node Breakdown:\n");
    Node* current = head;
    int position = 1;
    
    printf("HEAD(%p)\n", (void*)head);
    printf("   ↓\n");
    
    while (current != NULL) {
        printf("┌─────────────────────────────────┐\n");
        printf("│ %sNODE %d (ID: %d)%s                │\n", CYAN, position, current->node_id, RESET);
        printf("├─────────────────────────────────┤\n");
        printf("│ Address: %s%-18p%s │\n", GREEN, (void*)current, RESET);
        printf("│ Data:    %s%-18d%s │\n", YELLOW, current->data, RESET);
        printf("│ Next:    %s%-18p%s │\n", MAGENTA, (void*)current->next, RESET);
        printf("└─────────────────────────────────┘\n");
        
        if (current->next != NULL) {
            printf("   ↓ (points to next node)\n");
        } else {
            printf("   ↓\n");
            printf("  NULL (end of list)\n");
        }
        
        current = current->next;
        position++;
    }
}

// Show memory layout and heap visualization
void display_memory_layout(Node* head) {
    printf("\n%s🧠 MEMORY LAYOUT ANALYSIS%s\n", BOLD CYAN, RESET);
    
    if (head == NULL) {
        printf("No nodes to analyze\n");
        return;
    }
    
    printf("📊 Memory Statistics:\n");
    printf("   • Node size: %zu bytes\n", sizeof(Node));
    printf("   • Integer size: %zu bytes\n", sizeof(int));
    printf("   • Pointer size: %zu bytes\n", sizeof(void*));
    printf("   • Total allocated: %zu bytes\n", total_memory_allocated);
    
    printf("\n🗂️  Memory Layout per Node:\n");
    Node* current = head;
    int node_num = 1;
    
    while (current != NULL) {
        printf("\n📦 Node %d (ID: %d):\n", node_num, current->node_id);
        printf("   Base Address: %p\n", (void*)current);
        printf("   Data field:   %p (offset +0, value: %d)\n", 
               (void*)&(current->data), current->data);
        printf("   Next field:   %p (offset +%zu, value: %p)\n", 
               (void*)&(current->next), sizeof(int), (void*)current->next);
        printf("   Node size:    %zu bytes\n", sizeof(Node));
        
        // Show memory gap if any
        if (current->next != NULL) {
            ptrdiff_t gap = (char*)current->next - (char*)current;
            printf("   Gap to next:  %td bytes\n", gap - sizeof(Node));
        }
        
        current = current->next;
        node_num++;
    }
}

// Demonstrate stack vs heap memory
void demonstrate_stack_vs_heap() {
    printf("\n%s🏗️  STACK vs HEAP DEMONSTRATION%s\n", BOLD YELLOW, RESET);
    
    // Stack variable
    int stack_var = 42;
    printf("📚 Stack Variable:\n");
    printf("   • Variable: stack_var = %d\n", stack_var);
    printf("   • Address: %p\n", (void*)&stack_var);
    printf("   • Storage: Automatic (freed when function ends)\n");
    printf("   • Access: Very fast\n");
    
    // Heap variable
    int* heap_var = (int*)malloc(sizeof(int));
    *heap_var = 84;
    printf("\n🏗️  Heap Variable:\n");
    printf("   • Variable: *heap_var = %d\n", *heap_var);
    printf("   • Address: %p\n", (void*)heap_var);
    printf("   • Storage: Dynamic (must be manually freed)\n");
    printf("   • Access: Slower than stack\n");
    
    printf("\n🔍 Address Comparison:\n");
    if ((void*)&stack_var > (void*)heap_var) {
        printf("   Stack address (%p) > Heap address (%p)\n", 
               (void*)&stack_var, (void*)heap_var);
        printf("   This is typical - stack grows downward from high addresses\n");
    } else {
        printf("   Heap address (%p) > Stack address (%p)\n", 
               (void*)heap_var, (void*)&stack_var);
    }
    
    free(heap_var);
    printf("\n♻️  Heap memory freed\n");
}

// Show pointer relationships
void show_pointer_relationships(Node* head) {
    printf("\n%s🔗 POINTER RELATIONSHIPS%s\n", BOLD MAGENTA, RESET);
    
    if (head == NULL) {
        printf("No relationships to show (empty list)\n");
        return;
    }
    
    Node* current = head;
    int node_num = 1;
    
    printf("📋 Head Pointer Analysis:\n");
    printf("   • Head variable address: %p\n", (void*)&head);
    printf("   • Head points to: %p\n", (void*)head);
    printf("   • First node address: %p\n", (void*)current);
    
    printf("\n🔗 Node-to-Node Relationships:\n");
    while (current != NULL) {
        printf("\n📦 Node %d:\n", node_num);
        printf("   • Current node: %p\n", (void*)current);
        printf("   • Data value: %d\n", current->data);
        printf("   • Next pointer: %p\n", (void*)current->next);
        
        if (current->next != NULL) {
            printf("   • Points to node %d\n", node_num + 1);
            printf("   • Memory distance: %td bytes\n", 
                   (char*)current->next - (char*)current);
        } else {
            printf("   • Points to NULL (end of list)\n");
        }
        
        current = current->next;
        node_num++;
    }
}

// Search for an element
void search_element(Node* head, int data) {
    printf("\n%s🔍 SEARCHING FOR ELEMENT %d%s\n", BOLD GREEN, data, RESET);
    
    if (head == NULL) {
        printf("❌ Cannot search in empty list\n");
        return;
    }
    
    Node* current = head;
    int position = 1;
    int comparisons = 0;
    
    printf("🔄 Search Process:\n");
    while (current != NULL) {
        comparisons++;
        printf("   Step %d: Checking node at %p\n", comparisons, (void*)current);
        printf("           Data: %d, Target: %d\n", current->data, data);
        
        if (current->data == data) {
            printf("\n✅ Element found!\n");
            printf("   • Position: %d\n", position);
            printf("   • Address: %p\n", (void*)current);
            printf("   • Comparisons made: %d\n", comparisons);
            printf("   • Time complexity: O(n)\n");
            return;
        }
        
        printf("           No match, moving to next...\n");
        current = current->next;
        position++;
    }
    
    printf("\n❌ Element not found\n");
    printf("   • Comparisons made: %d\n", comparisons);
    printf("   • Entire list traversed\n");
}

// Get list length
int get_list_length(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Delete a node
void delete_node(Node** head, int data) {
    printf("\n%s🗑️  DELETING NODE WITH VALUE %d%s\n", BOLD RED, data, RESET);
    
    if (*head == NULL) {
        printf("❌ Cannot delete from empty list\n");
        return;
    }
    
    // If head node contains the data
    if ((*head)->data == data) {
        printf("🎯 Target found at head node\n");
        Node* temp = *head;
        printf("   • Saving reference to current head: %p\n", (void*)temp);
        *head = (*head)->next;
        printf("   • Updated head to: %p\n", (void*)*head);
        printf("   • Freeing memory at: %p\n", (void*)temp);
        free(temp);
        total_memory_allocated -= sizeof(Node);
        printf("✅ Head node deleted successfully\n");
        return;
    }
    
    // Search for the node to delete
    Node* current = *head;
    Node* previous = NULL;
    int position = 1;
    
    printf("🔍 Searching for node to delete...\n");
    while (current != NULL && current->data != data) {
        printf("   Position %d: Node %d at %p\n", position, current->data, (void*)current);
        previous = current;
        current = current->next;
        position++;
    }
    
    if (current == NULL) {
        printf("❌ Node with value %d not found\n", data);
        return;
    }
    
    printf("\n🎯 Target found at position %d\n", position);
    printf("   • Current node: %p (data: %d)\n", (void*)current, current->data);
    printf("   • Previous node: %p\n", (void*)previous);
    printf("   • Next node: %p\n", (void*)current->next);
    
    printf("\n🔗 Updating links...\n");
    previous->next = current->next;
    printf("   • Previous node now points to: %p\n", (void*)previous->next);
    
    printf("\n♻️  Freeing memory...\n");
    printf("   • Freeing node at: %p\n", (void*)current);
    free(current);
    total_memory_allocated -= sizeof(Node);
    
    printf("✅ Node deleted successfully\n");
}

// Reverse the linked list
void reverse_list(Node** head) {
    printf("\n%s🔄 REVERSING LINKED LIST%s\n", BOLD BLUE, RESET);
    
    if (*head == NULL || (*head)->next == NULL) {
        printf("❌ List has 0 or 1 nodes, nothing to reverse\n");
        return;
    }
    
    Node* previous = NULL;
    Node* current = *head;
    Node* next = NULL;
    int step = 1;
    
    printf("🔄 Reversal Process:\n");
    while (current != NULL) {
        printf("\n   Step %d:\n", step);
        printf("     • Previous: %p\n", (void*)previous);
        printf("     • Current: %p (data: %d)\n", (void*)current, current->data);
        printf("     • Next: %p\n", (void*)current->next);
        
        next = current->next;
        current->next = previous;
        
        printf("     • Reversed current->next to point to previous\n");
        
        previous = current;
        current = next;
        step++;
    }
    
    *head = previous;
    printf("\n✅ List reversed! New head: %p\n", (void*)*head);
}

// Cleanup function
void cleanup_list(Node** head) {
    printf("\n%s♻️  CLEANING UP MEMORY%s\n", BOLD RED, RESET);
    
    Node* current = *head;
    int freed_nodes = 0;
    
    while (current != NULL) {
        Node* temp = current;
        printf("🗑️  Freeing node %d at address %p\n", temp->node_id, (void*)temp);
        current = current->next;
        free(temp);
        freed_nodes++;
    }
    
    *head = NULL;
    total_memory_allocated = 0;
    node_counter = 0;
    
    printf("\n✅ Cleanup complete!\n");
    printf("   • Nodes freed: %d\n", freed_nodes);
    printf("   • Memory reclaimed: %zu bytes\n", freed_nodes * sizeof(Node));
}

// Utility functions
void print_separator() {
    printf("\n" CYAN "═══════════════════════════════════════════════════════════" RESET "\n");
}

void print_header(const char* title) {
    print_separator();
    printf("%s%s                    %s                    %s\n", BOLD, YELLOW, title, RESET);
    print_separator();
}

// Interactive menu
void interactive_menu() {
    Node* head = NULL;
    int choice, data;
    
    printf("%s\n🎓 ADVANCED LINKED LIST DEMONSTRATION PROGRAM 🎓%s\n", BOLD CYAN, RESET);
    printf("This program demonstrates in-depth working of linked lists\n");
    printf("including memory allocation, pointer relationships, and operations.\n");
    
    while (1) {
        print_header("MAIN MENU");
        printf("\n📋 Available Operations:\n");
        printf("   1️⃣  Insert at beginning\n");
        printf("   2️⃣  Insert at end\n");
        printf("   3️⃣  Delete node\n");
        printf("   4️⃣  Display list\n");
        printf("   5️⃣  Search element\n");
        printf("   6️⃣  Reverse list\n");
        printf("   7️⃣  Show memory layout\n");
        printf("   8️⃣  Show pointer relationships\n");
        printf("   9️⃣  Demonstrate stack vs heap\n");
        printf("   🔟 Frame-by-frame insertion\n");
        printf("   0️⃣  Exit and cleanup\n");
        
        printf("\n📊 Current Status:\n");
        printf("   • Nodes: %d\n", get_list_length(head));
        printf("   • Memory: %zu bytes\n", total_memory_allocated);
        printf("   • Operations: %d\n", operation_counter);
        
        printf("\n🎯 Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
                
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
                
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
                
            case 4:
                display_list(head);
                break;
                
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search_element(head, data);
                break;
                
            case 6:
                reverse_list(&head);
                break;
                
            case 7:
                display_memory_layout(head);
                break;
                
            case 8:
                show_pointer_relationships(head);
                break;
                
            case 9:
                demonstrate_stack_vs_heap();
                break;
                
            case 10:
                printf("Enter data for frame-by-frame insertion: ");
                scanf("%d", &data);
                // Clear input buffer
                while (getchar() != '\n');
                show_frame_by_frame_insertion(&head, data);
                break;
                
            case 0:
                cleanup_list(&head);
                printf("\n%s👋 Thank you for using the Advanced Linked List Demo!%s\n", BOLD GREEN, RESET);
                return;
                
            default:
                printf("%s❌ Invalid choice! Please try again.%s\n", RED, RESET);
        }
        
        printf("\n%sPress Enter to continue...%s", YELLOW, RESET);
        while (getchar() != '\n');  // Clear input buffer
        getchar();  // Wait for Enter
    }
}

int main() {
    interactive_menu();
    return 0;
}

