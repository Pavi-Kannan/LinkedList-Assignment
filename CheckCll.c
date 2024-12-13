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
    newNode->next=NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = create(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int isCircular(struct Node* head) {
    if (head == NULL) {
        return 0; 
    }
    
    struct Node *slow = head, *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      
        fast = fast->next->next;  
        
        if (slow==fast) {     
            return 1;
        }
    }
  
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void makeCircular(struct Node* head) {
    struct Node* temp =head;
    while (temp->next != NULL) {
        temp=temp->next;
    }
    temp->next=head; 
}

int main() {
    struct Node* head=NULL;
    int n,value,circularTest;

    printf("Enter num of nodes: ");
    scanf("%d",&n);

    printf("Enter the values for the linked list:\n");
    for (int i=0;i<n;i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d",&value);
        insertEnd(&head,value);
    }

    printf("you want to create the list circular? (1 for Yes, 0 for No): ");
    scanf("%d", &circularTest);
    if (circularTest == 1) {
        makeCircular(head);
        printf("The list is circular.\n");
    }

    if (isCircular(head)) {
        printf("linked list is circular.\n");
    } else {
        printf("linked list is not circular.\n");
    }
}
