#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertNode(struct Node** head,int data) {
    struct Node* newNode = createNode(data);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next=newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp==NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteKey(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev=NULL;

    while (temp != NULL && temp->data == key) {
        *head = temp->next;  
        free(temp);  
        temp = *head; 
    }

    while (temp != NULL) {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp==NULL) {
            return;  
        }

        prev->next=temp->next;  
        free(temp);  
        temp = prev->next;  
    }
}

int main() {
    struct Node* head = NULL;
    int n, data, key;

    printf("Enter the num of node: ");
    scanf("%d", &n);

    printf("Enter the data for node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original linked list:\n");
    printList(head);

    printf("Enter the key to delete: ");
    scanf("%d",&key);

    deleteKey(&head,key);

    printf("Linked list after deleting all occurrences of %d:\n",key);
    printList(head);

}
