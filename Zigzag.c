#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory not allocation!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void addNode(struct Node** head,int value) {
    struct Node* newNode=create(value);
    if (*head==NULL) {
        *head=newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void Zigzag(struct Node* head) {
    if (head==NULL) {
        return;
    }

    struct Node* current=head;
    int flag=1; 

    while (current!=NULL&&current->next!=NULL) {
        if (flag) {
           
            if (current->data > current->next->data) {
              
                int temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
            }
        } else {
          
            if (current->data < current->next->data) {
               
                int temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
            }
        }
        current=current->next;
        flag=!flag;
    }
}

void display(struct Node* head) {
    struct Node* temp=head;
    while (temp != NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int n,value;
    printf("Enter the num in the linked list: ");
    scanf("%d",&n);

    printf("Enter the val for the linked list node: \n");
    for (int i=0;i<n;i++) {
        printf("Node %d value: ",i + 1);
        scanf("%d",&value);
        addNode(&head,value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    Zigzag(head);

    printf("\nRearranged Zigzag Order: \n");
    display(head);

}
