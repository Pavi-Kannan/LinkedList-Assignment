#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void addEnd(struct Node** head,int value) {
    struct Node* newNode = create(value);
    if (*head==NULL) {
        *head=newNode;
    } else {
        struct Node*temp=*head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void display(struct Node* head) {
    struct Node* temp=head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int getLn(struct Node* head) {
    int length=0;
    struct Node* temp=head;
    while (temp!=NULL) {
        length++;
        temp=temp->next;
    }
    return length;
}

void rotateLeft(struct Node** head,int k) {
    if (*head==NULL || k == 0) return;

    int len = getLn(*head);
    k=k % len; 

    if (k == 0) return; 

    struct Node* temp = *head;
    struct Node* newTail=NULL;
    for (int i=1;i<len-k;i++) {
        temp=temp->next;
    }
    newTail = temp;

    struct Node* newHead=newTail->next;
    newTail->next=NULL;
    temp=newHead;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = *head;
    *head = newHead;
}
void rotateRight(struct Node** head,int k) {
    if (*head==NULL||k==0) return;

    int len = getLn(*head);
    k = k % len; 

    if (k == 0) return; 

    struct Node* temp = *head;
    struct Node* newTail=NULL;

    for (int i=1;i<len-k;i++) {
        temp=temp->next;
    }
    newTail=temp;

    struct Node* newHead=newTail->next;
    newTail->next=NULL;

    temp=newHead;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = *head;

    *head=newHead;
}

int main() {
    struct Node* head=NULL;
    int n,value,k,direction;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);

    printf("Enter the values for the nodes:\n");
    for (int i=0;i<n;i++) {
        printf("Node %d: ",i + 1);
        scanf("%d",&value);
        addEnd(&head,value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter the number of positions to rotate: ");
    scanf("%d",&k);

    printf("Enter 1 for left rotation or 2 for right rotation: ");
    scanf("%d",&direction);

    if (direction == 1) {
        rotateLeft(&head, k);
        printf("\nLinked List after left rotation by %d positions:\n", k);
    } else if (direction == 2) {
        rotateRight(&head, k);
        printf("\nLinked List after right rotation by %d positions:\n", k);
    } else {
        printf("Invalid direction.\n");
    }
    display(head);

}
