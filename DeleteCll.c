#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=newNode; 
    return newNode;
}
void insertEnd(struct Node** head, int value) {
    struct Node* newNode=create(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next = *head; 
    }
}

void deleteKthNode(struct Node** head, int k) {
    if (*head==NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev=NULL;

    if (k == 1) {
        
        if (temp->next == *head) {
            free(*head);
            *head=NULL;
        } else {
           
            while (temp->next != *head) {
                temp=temp->next;
            }
            temp->next = (*head)->next;
            free(*head);
            *head=temp->next;
        }
        return;
    }

    for (int i=1;i<k && temp != NULL;i++) {
        prev=temp;
        temp=temp->next;
    }

    if (temp==NULL) {
        printf("The position is out of range.\n");
        return;
    }

    prev->next=temp->next;
    free(temp);
}

void printList(struct Node* head) {
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp=head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head=NULL;
    int n,value,k;

    printf("Enter the num of node: ");
    scanf("%d",&n);

    printf("Enter the values for the circular linked list:\n");
    for (int i=0;i<n;i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d",&value);
        insertEnd(&head,value);
    }

    printf("Original Circular Linked List: ");
    printList(head);

    printf("Enter the place of  node to delete: ");
    scanf("%d", &k);

    deleteKthNode(&head, k);

    printf("Circular Linked List after deleting node %d: ", k);
    printList(head);

}
