#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct BSTNode {
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct BSTNode* createBSTNode(int value) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BSTNode* arrayToBST(int* arr, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int middle = (start + end) / 2;
    struct BSTNode* root = createBSTNode(arr[middle]);
    root->left = arrayToBST(arr, start, middle - 1);
    root->right = arrayToBST(arr, middle + 1, end);
    return root;
}

int* linkedListToArray(struct Node* head, int* length) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int* arr = (int*)malloc(count * sizeof(int));
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->value;
        temp = temp->next;
    }

    *length = count;
    return arr;
}


void inorderTraversal(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int numElements, value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &numElements);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    int length;
    int* array = linkedListToArray(head, &length);

    struct BSTNode* root = arrayToBST(array, 0, length - 1);

    printf("Inorder Traversal of the Balanced BST: ");
    inorderTraversal(root);
    printf("\n");

    free(array);

}
