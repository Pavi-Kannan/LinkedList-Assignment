#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=newNode;  
    return newNode;
}
void addEnd(struct Node** head,int value) {
    struct Node* newNode=create(value);
    if (*head==NULL) {
        *head = newNode;
    } else {
        struct Node* temp=*head;
        while (temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=*head;  
    }
}

void display(struct Node* head) {
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp=head;
    do {
        printf("%d -> ",temp->data);
        temp=temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
void splitCircular(struct Node* head, struct Node** firstHalf, struct Node** secondHalf) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* slow=head;
    struct Node* fast=head;
    while (fast->next!=head&&fast->next->next!=head) {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *firstHalf=head;
    *secondHalf=slow->next;
    
    slow->next=head;
    struct Node* temp=*secondHalf;
    while (temp->next!=head) {
        temp=temp->next;
    }
    temp->next = *secondHalf;
}
int main() {
    struct Node* head=NULL;
    struct Node* firstHalf=NULL;
    struct Node* secondHalf=NULL;
    int n,value;
    printf("Enter the number of node: ");
    scanf("%d",&n);

    printf("Enter the values for the nodes: \n");
    for (int i=0;i<n;i++) {
        printf("Node %d: ",i+1);
        scanf("%d",&value);
        addEnd(&head,value);
    }
    printf("\nOriginal Circular Linked List: \n");
    display(head);

    splitCircular(head,&firstHalf,&secondHalf);
    
    printf("\nFirst Half of the Circular Linked List: \n");
    display(firstHalf);
    
    printf("\nSecond Half of the Circular Linked List: \n");
    display(secondHalf);
}
