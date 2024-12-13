#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = create(data);
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

void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* slow=head;
    struct Node* fast=head;
   
    while (fast != NULL && fast->next != NULL) {
        slow=slow->next;        
        fast=fast->next->next;  
    }
    
    printf("The middle node is: %d\n",slow->data);
}

int main() {
    struct Node* head=NULL;
    int n, data;

    printf("Enter the num of node: ");
    scanf("%d", &n);
    printf("Enter the data for node:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&data);
        insertNode(&head,data);
    }
    findMiddle(head);
    
}
