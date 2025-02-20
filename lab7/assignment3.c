// 673380166-0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* create(int data){
    Node* node = (Node *)malloc(sizeof(Node));

    if(!node){
        printf("Error: Allocation failed!");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void freeNode(Node* node){
    if(node == NULL){
        return;
    }
    freeNode(node->left);
    freeNode(node->right);
    free(node);
}
// 673380166-0
void append(Node** node, int data){
    if(*node == NULL){
        *node = create(data);
        return;
    }

    if((*node)->data > data){
        append(&(*node)->left, data);
    }else{
        append(&(*node)->right, data);
    }
}

int height(Node* root){
    if(root == NULL){
        return -1;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}
// 673380166-0
int main(){
    Node* root1 = create(20);
    append(&root1, 10);
    append(&root1, 30);
    append(&root1, 5);
    append(&root1, 15);
    append(&root1, 25);
    append(&root1, 35);

    printf("root1 height is: %d\n", height(root1));

    Node* root2 = create(8);
    append(&root2, 3);
    append(&root2, 10);
    append(&root2, 1);
    append(&root2, 6);
    append(&root2, 14);
    append(&root2, 4);
    append(&root2, 7);
    append(&root2, 13);

    printf("root2 height is: %d\n", height(root2));
// 673380166-0
    struct Node* root3 = create(50);
    append(&root3, 30);
    append(&root3, 20);
    append(&root3, 40);
    append(&root3, 70);
    append(&root3, 60);
    append(&root3, 80);
    append(&root3, 100);
    append(&root3, 120);

    printf("root3 height is: %d\n", height(root3));

    freeNode(root1);
    freeNode(root2);
    freeNode(root3);
}