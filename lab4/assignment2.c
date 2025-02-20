#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Step 1: Initialize an empty linked list (head pointer set to NULL)
    struct Node* head = NULL;

    // Step 2: Create the first node
    struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node));
    firstNode->data = 10;     // Assign data to the first node
    firstNode->next = NULL;    // Set the next pointer of the first node to NULL

    // Step 3: Make the first node the head of the list
    head = firstNode;

    // Step 4: Create a second node
    struct Node* secondNode = (struct Node*)malloc(sizeof(struct Node));
    secondNode->data = 20;     // Assign data to the second node
    secondNode->next = NULL;   // Set the next pointer of the second node to NULL

    // Step 5: Link the first node to the second node
    firstNode->next = secondNode;

    // Step 6: Display the linked list with addresses
    struct Node* temp = head;
    printf("Linked list elements with addresses:\n");
    while (temp != NULL) {
        printf("Data: %d, Address: %p, Next: %p\n", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    }

    // Step 7: Free allocated memory (optional for this basic example)
    free(firstNode);
    free(secondNode);

    return 0;
}
