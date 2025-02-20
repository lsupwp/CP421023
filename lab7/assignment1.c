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

void preorder(Node* node){
    if(!node){
        return;
    }
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}
// 673380166-0
void inorder(Node* node){
    if(!node){
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(Node* node){
    if(!node){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main(){
    Node* root = create(20);
    root->left = create(10);
    root->right = create(30);
    root->left->left = create(5);
    root->left->right = create(15);
    root->right->left = create(25);
    root->right->right = create(35);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    freeNode(root);
}