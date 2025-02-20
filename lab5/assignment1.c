// 673380166-0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack{
    int top;
    unsigned capacity;
    int* array;
} Stack;

int isEmpty(Stack* stack){
    return stack->top == -1;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isNull(Stack* stack){
    return stack == NULL; 
}
// 673380166-0
Stack* createStack(){
    unsigned capacity;
    printf("กำหนดขนาดของ Stack: ");
    scanf("%d", &capacity);
    Stack* stack = (Stack *)malloc(sizeof(Stack));

    if(!stack){
        printf("Error: Allocation filed!\n");
        exit(1);
    }

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(capacity * sizeof(int));

    if(!stack->array){
        printf("Error: Allocation filed!\n");
        exit(1);
    }

    printf("สร้าง Stack ขนาด %d สำเร็จ\n", capacity);

    return stack;
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

    stack->array[++stack->top] = data;

    printf("เพิ่มข้อมูล %d เข้า Stack สำเร็จ\n", data);
    return 1;
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: stack is empty!\n");
        return 0;
    }
    printf("ลบข้อมูล %d ออกจาก Stack สำเร็จ\n", stack->array[stack->top]);
    stack->array[stack->top--] = 0;
    return 1;
}
// 673380166-0
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: stack is empty!\n");
        return INT_MIN;
    }
    printf("ข้อมูลบนสุดของ Stack คือ %d\n", stack->array[stack->top]);
    return stack->array[stack->top];
}

void stackStatus(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack ว่าง\n");
    }else{
        printf("Stack มีข้อมูลอยู่ %d/%d\n", stack->top+1, stack->capacity);
    }
}

int freeStack(Stack* stack){
    if(!stack){
        return 0;
    }

    free(stack->array);
    free(stack);
    return 1;
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
        if(!stack && (choice != 1)){
            printf("Error: You should create stack first!\n");
            break;
        }
        switch (choice)
        {
        case 1:
            stack = createStack();
            break;
        // 673380166-0
        case 2:
            push(stack);
            break;
        
        case 3:
            pop(stack);
            break;

        case 4:
            peek(stack);
            break;

        case 5:
            stackStatus(stack);
            break;

        default:
            break;
        }
    }

    freeStack(stack);
}