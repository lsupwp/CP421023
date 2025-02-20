// 673380166-0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    int top;
    unsigned capacity;
    Node* head;
} Stack;

Node* createNode(int data){
    Node* newNode = (Node *)malloc(sizeof(Node));

    if(!newNode){
        printf("Error: Allocation fialed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
// 673380166-0
Stack* createStack(){
    unsigned capacity;
    printf("กำหนดขนาดของ Stack: ");
    scanf("%d", &capacity);

    Stack* stack = (Stack *)malloc(sizeof(Stack));

    if(!stack){
        printf("Error: Allocation fialed!\n");
        exit(1);
    }

    stack->top = -1;
    stack->capacity = capacity;
    stack->head = NULL;

    printf("สร้าง Stack ขนาด %d สำเร็จ\n", stack->capacity);
    return stack;
}
// 673380166-0
int freeStack(Stack* stack){
    if(!stack){
        return 0;
    }
    Node* temp;
    while(stack->head){
        temp = stack->head->next;
        free(stack->head);
        stack->head = temp;
    }

    free(stack);
    return 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}
// 673380166-0
int push(Stack* stack){
    if(isFull(stack)){
        printf("Error: stack is full!\n");
        return 0;
    }

    int data;
    printf("กรอกข้อมูลที่ต้องการเพิ่ม: ");
    scanf("%d", &data);

    if(!stack->head){
        stack->head = createNode(data);
    }else{
        Node* temp = stack->head;
        stack->head = createNode(data);
        stack->head->next = temp;
    }

    ++stack->top;
    printf("เพิ่มข้อมูล %d เข้า Stack สำเร็จ\n", stack->head->data);
    return 1;
}
// 673380166-0
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: stack is empty!\n");
        return 0;
    }

    Node* temp = stack->head;
    stack->head = temp->next;
    --stack->top;

    printf("ลบข้อมูล %d ออกจาก Stack สำเร็จ\n", temp->data);
    free(temp);
    return 1;
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: Stack is empty!\n");
        return INT_MIN;
    }

    printf("ข้อมูลบนสุดของ Stack คือ %d\n", stack->head->data);
    return stack->head->data;
}

void sizeStack(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack ว่าง\n");
    }else{
        printf("Stack มีข้อมูลอยู่ %d/%d\n", stack->top + 1, stack->capacity);
    }
}
// 673380166-0
void main(){
    Stack* stack = NULL;
    printf(
        "เลข 1 เป็นการกำหนดขนาดของ stack\n"
        "เลข 2 เป็นการเพิ่มข้อมูลเข้า stack\n"
        "เลข 3 เป็นการลบข้อมูลออกจาก stack\n"
        "เลข 4 ตรวจสอบข้อมูลบนสุดของ stack\n"
        "เลข 5 ตรวจสอบสถานะของ stack\n"
        "เลข 6 ออกจากโปรแกรม\n"
    );
    while(1){
        int choice;
        printf("เลือกเมนู: ");
        scanf("%d", &choice);

        if(choice == 6) {printf("ออกจากโปรแกรม\n"); break;}
        if(!stack && choice != 1){
            printf("Error: You should create stack first!\n");
        }else{
            switch(choice){
                case 1:
                    stack = createStack();
                    break;
                
                case 2:
                    push(stack);
                    break;

                case 3:
                    pop(stack);
                    break;
                // 673380166-0
                case 4:
                    peek(stack);
                    break;
                
                case 5:
                    sizeStack(stack);
                    break;

                default :
                    break;
            }
        }
    }

    freeStack(stack);
}