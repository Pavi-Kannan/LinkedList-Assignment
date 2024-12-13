#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;  
    struct Node* down;  
    struct Node* prev;  
};

struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocation!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    newNode->down=NULL;
    newNode->prev=NULL; 
    return newNode;
}

void addToMainList(struct Node** head,int value) {
    struct Node* newNode = createNode(value);
    if (*head==NULL) {
        *head=newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;  
    }
}

void addToDownList(struct Node* node,int value) {
    struct Node* newNode = createNode(value);
    if (node->down==NULL) {
        node->down=newNode;
    } else {
        struct Node* temp=node->down;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;  
    }
}

struct Node* flatten(struct Node* head) {
    if (head == NULL) return NULL;
    
    struct Node* current=head;
    
    while (current!=NULL) {
        if (current->down!=NULL) {
   
            struct Node* downList=flatten(current->down);
            
            struct Node* nextNode=current->next;
            
            current->next=downList;
            if (downList!=NULL) {
                downList->prev=current; 
            }
            while (current->next!=NULL) {
                current=current->next;
            }
            
            current->next=nextNode;
            if (nextNode!=NULL) {
                nextNode->prev=current; 
            }
        }
        
        current=current->next;
    }
    
    return head;
}
void display(struct Node* head) {
    struct Node* temp=head;
    if (temp==NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int n,value,downNodes,downValue;

    printf("Enter the number of nodes in list1: ");
    scanf("%d",&n);

    printf("Enter the values for the main list nodes:\n");
    for (int i=0;i<n;i++) {
        printf("Node %d value: ",i + 1);
        scanf("%d",&value);
        addToMainList(&head,value);
        
        printf("Enter the number of down list nodes for node %d: ",i + 1);
        scanf("%d",&downNodes);
        
        for (int j=0;j<downNodes;j++) {
            printf("Down list node %d value: ",j + 1);
            scanf("%d", &downValue);
            addToDownList(head,downValue);  
        }
    }

    printf("\nOriginal Multilevel Doubly Linked List:\n");
    display(head);

    head = flatten(head);

    printf("\nFlattened List:\n");
    display(head);

}
