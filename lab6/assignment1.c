// 673380166-0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue{
    int *data;
    unsigned size;
    int front;
    int rear;
}Queue;

Queue* create(unsigned size){
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    if(!queue){
        printf("Error: allocation memory failed!\n");
        exit(1);
    }
    queue->data = (int *)malloc(sizeof(int) * size);
    if(!queue->data){
        printf("Error: allocation memory failed!\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void freeQueue(Queue* queue){
    free(queue->data);
    free(queue);
}
// 673380166-0
void enqueue(Queue* queue, int data){
    if(queue->rear == queue->size - 1){
        printf("Queue is full.\n");
        return;
    }
    if(queue->front == -1){
        queue->data[++queue->rear] = data;
        queue->front+=1;
        printf("%d added to the queue.\n", data);
        return;
    }
    queue->data[++queue->rear] = data;
    printf("%d added to the queue.\n", data);
    return;
}

int dequeue(Queue* queue){
    if(queue->front == -1){
        printf("Queue is empty.\n");
        return INT_MIN;
    }
    int result = queue->data[queue->front];
    queue->front+=1;
    if(queue->front > queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    printf("%d removed from the queue.\n", result);
    return result;
}
// 673380166-0
void display(Queue* queue){
    if(queue->front == -1){
        printf("Error: queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for(int i= queue->front; i<=queue->rear;i++){
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}
// 673380166-0
int main(){
    Queue* queue = create(5);
    while(1){
        printf("Queue Operations:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 4){
            printf("Exiting program.");
            freeQueue(queue);
            break;
        }
        switch(choice){
            case 1:
                int data;
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            default:
                printf("Invalid input\n");
        }
    }
}