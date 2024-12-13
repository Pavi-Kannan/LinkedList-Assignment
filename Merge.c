#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* adNode(int value) {
    struct Node*obj=(struct Node*)malloc(sizeof(struct Node));
    if (!obj) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    obj->data=value;
    obj->next=NULL;
    return obj;
}
void adEnd(struct Node** head,int value) {
    struct Node*obj=adNode(value);
    if (*head==NULL) {
        *head=obj;
        return;
    }
    struct Node*curr_Val=*head;
    while(curr_Val->next!=NULL) {
        curr_Val=curr_Val->next;
    }
    curr_Val->next=obj;
}
struct Node* mergeSort(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct Node*mergedHead = NULL;
    if (list1->data <= list2->data) {
        mergedHead=list1;
        mergedHead->next = mergeSort(list1->next,list2);
    } else {
        mergedHead = list2;
        mergedHead->next = mergeSort(list1,list2->next);
    }
    return mergedHead;
}
void display(struct Node* head) {
    struct Node* curr_Val=head;
    if (curr_Val == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (curr_Val != NULL) {
        printf("%d -> ",curr_Val->data);
        curr_Val=curr_Val->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *list1=NULL,*list2=NULL,*mergedList = NULL;
    int n1,n2,value;
    printf("Enter the num of elements in the first sorted list: ");
    scanf("%d",&n1);
    printf("Enter %d elements for the first sorted list:\n", n1);
    for (int i=0;i<n1;i++) {
        scanf("%d",&value);
        adEnd(&list1,value);
    }
    printf("Enter the number of elements in the second sorted list: ");
    scanf("%d",&n2);
    printf("Enter %d elements for the second sorted list:\n", n2);
    for (int i=0;i<n2;i++) {
        scanf("%d",&value);
        adEnd(&list2,value);
    }
    printf("\nFirst sorted list:\n");
    display(list1);
    printf("\nSecond sorted list:\n");
    display(list2);
    mergedList = mergeSort(list1, list2);
    printf("\nMerged sorted list:\n");
    display(mergedList);
}
