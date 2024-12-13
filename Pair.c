#include <stdio.h>
#include <stdlib.h>

struct Node1 {
    int data;
    struct Node1* next;
    struct Node1* prev;
};

struct Node1* create(int value) {
    struct Node1* newNode = (struct Node1*)malloc(sizeof(struct Node1));
    if (newNode==NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

int insertEnd(struct Node1** head,int value) {
    struct Node1* newNode=create(value);  
    if (*head==NULL) {
        *head=newNode;
    } else {
        struct Node1* temp = *head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void List(struct Node1* head) {
    struct Node1* temp=head;
    while (temp!=NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void Pair(struct Node1* head,int target) {
    struct Node1* start=head;
    struct Node1* end=head;

    while (end!=NULL&&end->next!=NULL) {
        end=end->next;
    }

    int found=0;
 
    while (start != NULL && end != NULL && start != end && start->prev != end) {
        int sum=start->data + end->data;
        if (sum==target) {
            printf("Pair found: (%d, %d)\n", start->data, end->data);
            found=1;
            start=start->next;
            end=end->prev;
        } else if (sum < target) {
            start=start->next;
        } else {
            end=end->prev;
        }
    }

    if (!found) {
        printf("No pairs found with sum %d\n",target);
    }
}


int main() {
    struct Node1* head=NULL;
    int n,value,target;
    
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the values for the doubly linked list:\n");
    for (int i=0;i<n;i++) {
        printf("Enter value for node %d: ",i + 1);
        scanf("%d",&value);
        insertEnd(&head,value); 
    }

    printf("Enter the target sum: ");
    scanf("%d",&target);

    printf("Doubly Linked List: ");
    List(head); 
    Pair(head,target);

}
