// 673380166-0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("Memory allocation fialed!");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 673380166-0
void showNode(Node *head)
{
    if (!head)
    {
        printf("Error: head is null\n");
    }
    Node *temp = head;
    printf("[ ");
    do
    {
        if (head->next == temp)
        {
            printf("%d ", head->data);
        }
        else
        {
            printf("%d, ", head->data);
        }
        head = head->next;
        if (head == temp)
        {
            break;
        }
    } while (head);
    printf("]\n");
}

// 673380166-0
int sizeNode(Node* head){
    if(!head){
        printf("Node is null!\n");
        return -1;
    }
    int count = 0;

    Node* temp = head;
    do{
        count++;
        head = head->next;
        if(head == temp){
            break;
        }
    }while(head);

    return count;
}

// 673380166-0
Node *addHead(Node *head, int value)
{
    Node *newNode = createNode(value);

    Node* temp = head;

    while (head)
    {   
        if (head->next == temp)
        {
            head->next = newNode;
        }
        head = head->next;
    }
    newNode->next = temp;

    free(newNode);
    return newNode;
}

// 673380166-0
Node* getNext(Node* head, int pos){
    if(pos < 1 || pos > sizeNode(head)){
        printf("Error: pos out of range\n");
        return head;
    }
    for(int i=1;i<pos;i++){
        head = head->next;
    }
    return head->next;
}

int setNext(Node* head, int pos, Node* next){
    if(pos < 1 || pos > sizeNode(head)){
        printf("Error: pos out of range\n");
        return -1;
    }
    for(int i=1;i<pos;i++){
        head = head->next;
    }
    head->next = next;
    return 1;
}

// 673380166-0
int insertNode(Node* head, int pos, int value){
    if(pos <= 1 || pos > sizeNode(head)){
        printf("Error: pos out of range\n");
        return 0;
    }
    Node* newNode = createNode(value);

    Node* next = getNext(head, pos-1);
    setNext(head, pos-1, newNode);
    setNext(head, pos, next);

    free(newNode);
    return 1;
}

// 673380166-0
int addTail(Node* head, int value){
    if(!head){
        printf("Error: Node is null!\n");
        return 0;
    }
    Node* newNode = createNode(value);

    Node* temp = head;
    while(head){
        if(head->next == temp){
            head->next = newNode;
            newNode->next = temp;
            head = temp;
            break;
        }
        head = head->next;
    }

    free(newNode);
}
// 673380166-0
int changeData(Node* node, int pos, int value){
    if(!node){
        printf("Error: Node is null!\n");
        return 0;
    }
    if(pos < 1 || pos > sizeNode(node)){
        printf("Error: pos out of range!\n");
        return 0;
    }
    for(int i=1;i<pos;i++){
        
        node = node->next;
    }
    node->data = value;
    return 1;
}

int deleteNode(Node* head, int pos){
    if(!head){
        printf("Error: Node is null!\n");
        return 0;
    }
    if(pos <= 1 || pos >= sizeNode(head)){
        printf("Error: pos out of range! or can't delete head or tail position\n");
        return 0;
    }
    Node* next = getNext(head, pos);
    setNext(head, pos-1, next);

    return 1;
}

// 673380166-0
int main()
{
    // สร้าง linked list โดยมีข้อมูล 10 -> 20 -> 30 -> 40 -> 50
    Node *head = NULL;
    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);
    Node *node5 = createNode(50);

    // สร้าง Circularly Linklist
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;
    showNode(head);

    // เพิ่มข้อมูล 100 ที่ตำแหน่ง head
    head = addHead(head, 100);
    showNode(head);
    // เพิ่มข้อมูล 110 ที่ตำแหน่งที่ 2
    insertNode(head, 2, 110);
    showNode(head);
    // เพิ่มข้อมูล 120 ที่ตำแหน่ง tail
    addTail(head, 120);
    showNode(head);
    // เปลี่ยนค่าข้อมูลตำแหน่งที่ 4 เป็น 200
    changeData(head, 4, 200);
    showNode(head);
    // ลบข้อมูลตำแหน่งที่ 3
    deleteNode(head, 3);
    showNode(head);
    // 673380166-0
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}

// [ 100, 110, 200, 30, 40, 50, 120 ]