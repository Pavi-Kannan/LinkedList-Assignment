#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adNode(int value) {
    struct Node* obj = (struct Node*)malloc(sizeof(struct Node));
    if (!obj) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    obj->data = value;
    obj->next = NULL;
    return obj;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* obj = adNode(value);
    if (*head == NULL) {
        *head = obj;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = obj;
}

int search(struct Node* head, int target) {
    int curr_Val = 1; 
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == target) {
            return curr_Val;
        }
        temp = temp->next;
        curr_Val++;
    }
    return -1; 
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice,value,target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert value into the linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Search for a value in the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Value %d inserted into the linked list.\n",value);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &target);
                int curr_Val=search(head,target);
                if (curr_Val != -1) {
                    printf("Value %d found at position %d.\n", target,curr_Val);
                } else {
                    printf("Value %d not found in list.\n",target);
                }
                break;

            case 4:
                printf("Exiting...!\n");
                return 0;

            default:
                printf("Invalid choice!.\n");
        }
    }
}
