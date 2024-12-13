#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* nextNode;
    struct Node* prevNode;
};

struct Node* create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocate error!\n");
        exit(1);
    }
    node->value=data;
    node->nextNode=NULL;
    node->prevNode=NULL;
    return node;
}

void append(struct Node** head,int data) {
    struct Node* newNode=create(data);
    
    if (*head==NULL) {
        *head=newNode;
    } else {
        struct Node* temp = *head;
        while (temp->nextNode!=NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode=newNode;
        newNode->prevNode=temp;
    }
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = create(data);
    
    if (*head==NULL) {
        *head=newNode;
    } else {
        newNode->nextNode = *head;
        (*head)->prevNode=newNode;
        *head=newNode;
    }
}
void removeNode(struct Node** head,int data) {
    if (*head==NULL) {
        printf("List is empty, cannot perform deletion.\n");
        return;
    }
    
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->value == data) {
          
            if (temp == *head) {
                *head = temp->nextNode;
                if (*head != NULL) {
                    (*head)->prevNode = NULL;
                }
            } else {
                if (temp->nextNode != NULL) {
                    temp->nextNode->prevNode = temp->prevNode;
                }
                if (temp->prevNode != NULL) {
                    temp->prevNode->nextNode = temp->nextNode;
                }
            }
            free(temp);
            printf("Node with value %d removed successfully.\n", data);
            return;
        }
        temp = temp->nextNode;
    }
    printf("Node with value %d not found.\n", data);
}

void Forward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List from head to tail: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->nextNode;
    }
    printf("NULL\n");
}

void Backward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    
    printf("List from tail to head: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->prevNode;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int choice,value;

    while (1) {
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1.Add node at the end\n");
        printf("2.Add node at the beginning\n");
        printf("3.Remove a node by value\n");
        printf("4.Display list (head to tail)\n");
        printf("5.Display list (tail to head)\n");
        printf("6.Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Enter value to add at the end: ");
                scanf("%d", &value);
                append(&head, value);
                break;
            case 2:
                
                printf("Enter value to add at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 3:
               
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeNode(&head, value);
                break;
            case 4:
              
                Forward(head);
                break;
            case 5:
                
                Backward(head);
                break;
            case 6:
                
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

}
