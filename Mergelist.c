#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void addNode(struct Node** head,int value) {
    struct Node* newNode = createNode(value);
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

struct Node* addLists(struct Node* l1,struct Node* l2) {
    struct Node* result=NULL; 
    struct Node* temp=NULL;  
    struct Node* prev=NULL;  
    int carry=0,sum;

    while (l1!=NULL || l2 !=NULL||carry) {
        sum = carry;
        
        if (l1 !=NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        struct Node* newNode=createNode(sum % 10);
        
        if (result==NULL) {
            result=newNode;
        } else {
            prev->next=newNode;
        }
        
        prev=newNode;
    }
    
    return result;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp==NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* l1=NULL;
    struct Node* l2=NULL;
    struct Node* result=NULL;
    int n,value;

    printf("Enter the number of digits in the first number: ");
    scanf("%d", &n);
    printf("Enter the digits for the first number: \n");
    for (int i=0;i<n;i++) {
        printf("Digit %d: ",i+1);
        scanf("%d",&value);
        addNode(&l1,value);
    }

    printf("Enter the number of digits in the second number: ");
    scanf("%d",&n);
    printf("Enter the digits for the second number (least significant digit first):\n");
    for (int i=0;i<n;i++) {
        printf("Digit %d: ",i + 1);
        scanf("%d",&value);
        addNode(&l2,value);
    }

    printf("\nFirst Number (Linked List 1): ");
    display(l1);
    printf("Second Number (Linked List 2): ");
    display(l2);

    result = addLists(l1,l2);

    printf("\nSum of the two numbers (Linked List): ");
    display(result);

}
