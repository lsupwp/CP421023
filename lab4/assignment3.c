#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = newData;

    newNode->next = *head;

    *head = newNode;
}

// Function to display the linked list with addresses
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list elements with addresses:\n");
    while (temp != NULL) {
        printf("Data: %d, Address: %p, Next: %p\n", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Display the linked list
    displayList(head);

    return 0;
}
