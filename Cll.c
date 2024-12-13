#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory not allocated\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = create(value);
    
    if (*head == NULL) {
      
        *head = newNode;
        newNode->next = *head;
    } else {
  
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next = *head;
    }
}

void delete(struct Node** head, int value) {
    if (*head==NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    if (temp->data==value) {
       
        while (temp->next != *head) {
            temp=temp->next;
        }
        
        if (*head==(*head)->next) {
            
            free(*head);
            *head=NULL;
        } else {
            temp->next = (*head)->next;
            free(*head);
            *head=temp->next;
        }
        return;
    }

    do {
        prev=temp;
        temp=temp->next;
    } while (temp != *head && temp->data != value);

    if (temp == *head) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    prev->next=temp->next;
    free(temp);
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
    printf("(head)\n");
}

void search(struct Node* head,int value) {
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp=head;
    do {
        if (temp->data==value) {
            printf("Node with value %d found.\n", value);
            return;
        }
        temp=temp->next;
    } while (temp != head);

    printf("Node with value %d not found.\n", value);
}

int main() {
    struct Node* head = NULL;
    int choice,value;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1.Insert at the end\n");
        printf("2.Delete a node\n");
        printf("3.Display the list\n");
        printf("4.Search for a node\n");
        printf("5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insertEnd(&head,value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete(&head,value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(head,value);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

}
