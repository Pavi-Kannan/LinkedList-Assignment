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

void addNode(struct Node** head,int value) {
    struct Node* newNode=create(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next=newNode;
    }
}

struct Node* find(struct Node* head) {
    if (head == NULL) return NULL;
    
    struct Node *slow=head, *fast=head;

    while (fast != NULL&&fast->next!=NULL) {
        slow=slow->next;         
        fast=fast->next->next;    

        if (slow==fast) {
            slow=head;  
            while (slow!=fast) {
                slow=slow->next;  
            }
            return slow;  
        }
    }

    return NULL;
}

void display(struct Node* head) {
    struct Node* temp=head;
    while (temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void createLoop(struct Node* head,int position) {
    if (head==NULL) return;
    struct Node* temp=head;
    struct Node* loopStartNode=NULL;
    int count=1;

    while (temp->next!=NULL) {
        if (count==position) {
            loopStartNode=temp;
        }
        temp=temp->next;
        count++;
    }

    if (loopStartNode!=NULL) {
        temp->next=loopStartNode;  
    }
}

int main() {
    struct Node* head=NULL;
    int n, value,loopPosition;

    printf("Enter the num in the linked list: ");
    scanf("%d",&n);

    printf("Enter the val for linked list:\n");
    for (int i=0;i<n;i++) {
        printf("Node %d value: ",i + 1);
        scanf("%d",&value);
        addNode(&head,value);
    }

    printf("Enter the position for loop: ");
    scanf("%d",&loopPosition);
    if (loopPosition>0) {
        createLoop(head,loopPosition);
    }

    struct Node* loopStart=findLoopStart(head);
    if (loopStart!=NULL) {
        printf("Loop detected! The starting node of the loop is: %d\n",loopStart->data);
    } else {
        printf("No loop detected in the linked list.\n");
    }

}
