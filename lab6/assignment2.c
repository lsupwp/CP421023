// 673380166-0
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int* data;
    unsigned size;
    int front;
    int rear;
} Q;

Q* create(unsigned size){
    Q* queue = (Q *)malloc(sizeof(Q));
    if(!queue){
        printf("Error: allocation memory failed!\n");
        exit(1);
    }
    queue->data = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void freeQ(Q* queue){
    free(queue->data);
    free(queue);
}
// 673380166-0
void enqueue(Q* queue, int data){
    if(queue->rear == queue->size - 1){
        printf("Error: queue is full!\n");
        return;
    }
    if(queue->front == -1) queue->front += 1;
    queue->data[++queue->rear] = data;
    return;
}

int main(){
    Q* queue = create(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Queue address:(queue) %p\n", &queue);
    printf("Queue address:(data) %p\n", &(queue->data));
    printf("Queue address:(front) %p\n", &(queue->front));
    printf("Queue address:(rear) %p\n", &(queue->rear));
    printf("Queue address:(size) %p\n", &(queue->size));

    for(int i=queue->front;i<=queue->rear;i++){
        printf("Queue element address:(%d) %p\n", queue->data[i], &(queue->data[i]));
    }

    freeQ(queue);
}