#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocation!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEnd(struct Node** head, int value) {
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

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapNode(struct Node** head,int x,int y) {
    if (x == y) return; 
    
    struct Node* prevX=NULL, *currX = *head;
    struct Node* prevY=NULL, *currY = *head;
    
    while (currX!=NULL&&currX->data != x) {
        prevX=currX;
        currX=currX->next;
    }
    
    while (currY!=NULL&&currY->data != y) {
        prevY=currY;
        currY=currY->next;
    }
    if (currX==NULL||currY==NULL) {
        printf("One or both elements not found in the list.\n");
        return;
    }
    if (prevX!=NULL) {
        prevX->next=currY;
    } else {
        *head=currY; 
    }
    
    if (prevY!=NULL) {
        prevY->next=currX;
    } else {
        *head=currX;
    }
    
    struct Node* temp=currX->next;
    currX->next=currY->next;
    currY->next=temp;
}

int main() {
    struct Node* head=NULL;
    int n,value,x,y;

    printf("Enter the no of node in the linked list: ");
    scanf("%d",&n);

    printf("Enter the value for the node :\n");
    for (int i=0;i<n;i++) {
        printf("Node %d: ",i+1);
        scanf("%d",&value);
        addEnd(&head,value);
    }
    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter the value of the two nodes to swap: ");
    scanf("%d %d",&x,&y);

    swapNode(&head,x,y);

    printf("\nLinked List after swapping node with value %d and %d:\n", x,y);
    display(head);

}
