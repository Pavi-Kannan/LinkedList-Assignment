#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory allocated!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void append(struct Node** head,int value) {
    struct Node* newNode=create(value);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Forward(struct Node* head) {
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp=head;
    printf("List (Head to Tail): ");
    while (temp!=NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void Backward(struct Node* head) {
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    printf("List (Tail to Head): ");
    while (temp != NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    if (*head==NULL||(*head)->next==NULL) {
        return;  
    }
    struct Node* temp=NULL;
    struct Node* current=*head;
    
    while (current != NULL) {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    
    if (temp!=NULL) {
        *head=temp->prev;
    }
}

int main() {
    struct Node* head=NULL;
    int choice, value;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1.Insert a node at the end\n");
        printf("2.Print list from head to tail\n");
        printf("3.Print list from tail to head\n");
        printf("4.Reverse the doubly linked list\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d",&value);
                append(&head,value);
                break;

            case 2:
                Forward(head);
                break;

            case 3:
                Backward(head);
                break;

            case 4:
                reverse(&head);
                printf("The list has been reversed.\n");
                break;

            case 5:
                printf("Exiting.....\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

}
