#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* adNode(int value) {
    struct Node* obj = (struct Node*)malloc(sizeof(struct Node));
    if (!obj) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    obj->data=value;
    obj->next=NULL;
    return obj;
}

void adEnd(struct Node** head, int value) {
    struct Node* obj = adNode(value);
    if (*head==NULL) {
        *head=obj;
        return;
    }
    struct Node* curr_Val=*head;
    while (curr_Val->next!=NULL) {
        curr_Val = curr_Val->next;
    }
    curr_Val->next = obj;
}
void find(struct Node*head,int n) {
    struct Node *mainPtr=head,*refPtr=head;
    int count=0;
    while (count<n) {
        if (refPtr==NULL) {
            printf("The list has more than %d elements.\n", n);
            return;
        }
        refPtr=refPtr->next;
        count++;
    }

    while (refPtr!=NULL) {
        mainPtr=mainPtr->next;
        refPtr=refPtr->next;
    }
    printf("The %dth node from the end is: %d\n", n,mainPtr->data);
}
void display(struct Node* head) {
    struct Node* curr_Val=head;
    if (curr_Val==NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (curr_Val!=NULL) {
        printf("%d -> ",curr_Val->data);
        curr_Val=curr_Val->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    int n,ele,value;
    printf("Enter the element in the linked list: ");
    scanf("%d",&ele);
    printf("Enter %d element for the linked list:\n",ele);
    for (int i = 0; i <ele; i++) {
        scanf("%d", &value);
        adEnd(&head, value);
    }
    printf("\nThe linked list:\n");
    display(head);
    printf("\nEnter the position (n) from the end: ");
    scanf("%d", &n);
    find(head, n);
}
