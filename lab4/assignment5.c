// 673380166-0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* pre;
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node* )malloc(sizeof(Node));
    if(!newNode){
        printf("Error: Allocation address fialed!\n");
        exit(1);
    }
    newNode->pre = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int nodeIsNull(Node* node){
    if(!node){
        printf("Error: Node is null!\n");
        return 1;
    }
    return 0;
}
// 673380166-0
Node* addToHead(Node* head, int data){
    if(nodeIsNull(head)){
        return head;
    }
    Node* newNode = createNode(data);
    head->pre = newNode;
    newNode->next = head;
    head = newNode;

    free(newNode);
    return head;
}

int showNode(Node* node){
    if(nodeIsNull(node)){
        return 1;
    }
    printf("[ ");
    while(node){
        if(node->next == NULL){
            printf("%d ", node->data);
        }else{
            printf("%d, ", node->data);
        }
        node = node->next;
    }
    printf("]\n");
    return 0;
}
// 673380166-0
int sizeNode(Node* node){
    int count = 0;
    while(node){
        count++;
        node = node->next;
    }
    return count;
}

Node* getPre(Node* head, int pos){
    if(nodeIsNull(head)){
        return head;
    }
    if(pos < 1 || pos > sizeNode(head)){
        printf("Error node out of range!\n");
        return head;
    }
    Node* current = head;
    for(int i=1;i<pos;i++){
        current = current->next;
    }
    return current->pre;
}
// 673380166-0
Node* getNext(Node* head, int pos){
    if(nodeIsNull(head)){
        return head;
    }
    if(pos < 1 || pos > sizeNode(head)){
        printf("Error node out of range!\n");
        return head;
    }
    Node* current = head;
    for(int i=1;i<pos;i++){
        current = current->next;
    }
    return current->next;
}

int setPre(Node* node, int pos, Node* pre){
    if(nodeIsNull(node)){
        return 1;
    }
    if(pos < 1 || pos > sizeNode(node)){
        printf("Error node out of range!\n");
        return 1;
    }
    Node* current = node;
    for(int i=1;i<pos;i++){
        current = current->next;
    }
    current->pre = pre;
    return 0;
}
// 673380166-0
int setNext(Node* node, int pos, Node* next){
    if(nodeIsNull(node)){
        return 1;
    }
    if(pos < 1 || pos > sizeNode(node)){
        printf("Error node out of range!\n");
        return 1;
    }
    Node* current = node;
    for(int i=1;i<pos;i++){
        current = current->next;
    }
    current->next = next;
    return 0;
}
// 673380166-0
int insertNode(Node* head, int pos, int data){
    if(nodeIsNull(head)){
        return 1;
    }
    if(pos <= 1 || pos >= sizeNode(head)){
        printf("Error: you mush be use addToHead or addToTails function\n");
        return 1;
    }
    Node* temp = head;
    Node* next = getNext(temp, pos-1);
    Node* pre = getPre(temp, pos);

    Node* newNode = createNode(data);
    setNext(temp, pos-1, newNode);
    newNode->pre = pre;
    newNode->next = next;
    setPre(temp, pos+1, newNode);

    free(newNode);
    return 1;
}
// 673380166-0
int addToTails(Node* head, int data){
    if(nodeIsNull(head)){
        return 1;
    }
    int size = sizeNode(head);
    Node* temp = head;
    Node* pre = getNext(temp, size-1);

    Node* newNode = createNode(data);
    newNode->pre = pre;
    setNext(temp, size, newNode);
    return 0;
}

int uodateNodeData(Node* node, int pos, int data){
    if(nodeIsNull(node)){
        return 1;
    }
    if(pos < 1 || pos > sizeNode(node)){
        printf("Error: node out of range!\n");
        return 1;
    }
    Node* temp = node;
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    temp->data = data;
    return 0;
}
// 673380166-0
int deleteNode(Node* node, int pos){
    if(nodeIsNull(node)){
        return 1;
    }
    if(pos <=1 || pos >= sizeNode(node)){
        printf("Error: node out of range or you want to delete head, tail node you mush use delHead, delTails\n");
        return 1;
    }
    Node* next = getNext(node, pos);
    Node* pre = getPre(node, pos);

    setNext(node, pos-1, next);
    setPre(node, pos, pre);

    return 0;
}

int main(){
    Node* head = NULL;
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);

    head = node1;
    node1->next = node2;

    node2->pre = node1;
    node2->next = node3;
    
    node3->pre = node2;
    node3->next = node4;
    // 673380166-0
    node4->pre = node3;
    node4->next = node5;
    
    node5->pre = node4;
    showNode(head);

    // เพิ่มข้อมูล 100 ที่ตำแหน่ง head
    head = addToHead(head, 100);
    showNode(head);
    // เพิ่มข้อมูล 110 ที่ตำแหน่งที่ 2
    insertNode(head, 2, 110);
    showNode(head);
    // เพิ่มข้อมูล 120 ที่ตำแหน่ง tail
    addToTails(head,120);
    showNode(head);
    // เปลี่ยนค่าข้อมูลตำแหน่งที่ 4 เป็น 200
    uodateNodeData(head, 4, 200);
    showNode(head);
    // ลบข้อมูลตำแหน่งที่ 3
    deleteNode(head, 3);
    showNode(head);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}