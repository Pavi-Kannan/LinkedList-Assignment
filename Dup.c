#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory not allocation!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void addEnd(struct Node**head,int value) {
    struct Node* newNode=create(value);
    if (*head==NULL) {
        *head=newNode;
        return;
    }

    struct Node* temp =*head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}
void remDup(struct Node* head) {
    struct Node *current=head,*prev=NULL,*curr = NULL;

    while (current!=NULL&&current->next!=NULL) {
        prev = current;
        curr = current->next;

        while (curr!= NULL) {
            if (current->data==curr->data) {
                prev->next=curr->next;
                free(curr);  
                curr= prev->next; 
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        current = current->next;
    }
    printf("Duplicate have Removed\n");
}
void display(struct Node*head) {
    struct Node*temp=head;
    if (temp==NULL) {
        printf("list is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int n, value;
    printf("Enter the elements in linked list: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&value);
        addEnd(&head,value);
    }
    printf("\nOriginal List:\n");
    display(head);
    remDup(head);
    printf("\nList after remove duplicate:\n");
    display(head);
}
