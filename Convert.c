#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct TreeNode* create(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data=value;
    newNode->left=newNode->right = NULL;
    return newNode;
}

struct DLLNode* createDLL(int value) {
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data=value;
    newNode->prev=newNode->next = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root==NULL) {
        return create(value);
    }

    if (value < root->data) {
        root->left=insert(root->left, value);
    } else {
        root->right=insert(root->right, value);
    }

    return root;
}

void convertToDLL(struct TreeNode* root, struct DLLNode** head, struct DLLNode** tail) {
    if (root==NULL) {
        return;
    }

    convertToDLL(root->left,head,tail);

    struct DLLNode* newNode=createDLL(root->data);
    if (*tail==NULL) {
        *head = *tail = newNode; 
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;  
    }

    convertToDLL(root->right, head, tail);
}

void printDLL(struct DLLNode* head) {
    struct DLLNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct TreeNode* root=NULL;
    struct DLLNode* head=NULL;
    struct DLLNode* tail=NULL;
    int n, value;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d",&n);

    printf("Enter the values for the binary tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root,value);
    }

    convertToDLL(root,&head,&tail);

    printf("Doubly Linked List: ");
    printDLL(head);

}
