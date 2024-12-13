#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node*adNode(int value) {
    struct Node* obj = (struct Node*)malloc(sizeof(struct Node));
    if (!obj) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    obj->data = value;
    obj->next = NULL;
    return obj;
}

void adEnd(struct Node** head, int value) {
    struct Node* obj = adNode(value);
    if (*head == NULL) {
        *head = obj;
        return;
    }
    struct Node* curr_Val = *head;
    while (curr_Val->next != NULL) {
        curr_Val = curr_Val->next;
    }
    curr_Val->next = obj;
}

void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next=curr->next; 
        curr->next = prev; 
        prev=curr;    
        curr=next;  
    }

    *head=prev; 
    printf("The list reversed.\n");
}

void display(struct Node* head) {
    struct Node* curr_Val=head;
    if (curr_Val==NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (curr_Val != NULL) {
        printf("%d -> ",curr_Val->data);
        curr_Val=curr_Val->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int choice,value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert value into the linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Reverse the linked list\n");
        printf("4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the val: ");
                scanf("%d",&value);
                adEnd(&head,value);
                printf("Value %d inserted linked list.\n",value);
                break;

            case 2:
                display(head);
                break;

            case 3:
                reverse(&head);
                break;

            case 4:
                printf("Exiting...!\n");
                return 0;

            default:
                printf("Invalid choice!.\n");
        }
    }
}
