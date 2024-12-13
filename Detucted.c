#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
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

int detectLoop(struct Node* head) {
    struct Node* slow=head;
    struct Node* fast=head;

    while (fast!=NULL&&fast->next!=NULL) {
        slow=slow->next;         
        fast=fast->next->next;    
        
        if (slow==fast) {
            return 1; 
        }
    }
     
}

int find(struct Node* head) {
    struct Node* slow=head;
    struct Node* fast=head;

    while (fast!=NULL&&fast->next!= NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast) { 
            
            int length=1;
            struct Node* temp=slow->next;
            while (temp != slow) {
                length++;
                temp=temp->next;
            }
            return length;
        }
    }

    return 0; 
}

void display(struct Node* head) {
    struct Node* temp=head;
    while (temp != NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int n, value,loopNodeIndex, i;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d",&n);

    printf("Enter the values for the linked list nodes:\n");
    for (i=0;i<n;i++) {
        printf("Node %d value: ",i + 1);
        scanf("%d",&value);
        addNode(&head,value);
    }
    printf("Enter the index of the node: ");
    scanf("%d",&loopNodeIndex);
    
    if (loopNodeIndex != 0) {
        struct Node* temp=head;
        struct Node* loopNode=NULL;
        int index=1;
        
        while (temp!=NULL) {
            if (index==loopNodeIndex) {
                loopNode=temp;
            }
            temp=temp->next;
            index++;
        }
        
        if (loopNode!=NULL) {
            struct Node* lastNode=head;
            while (lastNode->next!=NULL) {
                lastNode=lastNode->next;
            }
            lastNode->next=loopNode;
        }
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    if (detectLoop(head)) {
        printf("\nLoop detected in the linked list.\n");
        
        int loopLength=find(head);
        printf("Length of the loop: %d\n",loopLength);
    } else {
        printf("\nNo loop detected in the linked list.\n");
    }

}
