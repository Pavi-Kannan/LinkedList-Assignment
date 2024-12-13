#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*next;
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

void adEnd(struct Node** head,int value) {
    struct Node* obj = adNode(value);
    if (*head == NULL) {
        *head = obj;
        return;
    }
    struct Node* curr_Val = *head;
    while (curr_Val->next != NULL) {
        curr_Val = curr_Val->next;
    }
    curr_Val->next = obj;
}

void remDup(struct Node* head) {
    struct Node* curr_Val = head;
    while (curr_Val != NULL&&curr_Val->next !=NULL) {
        struct Node* ma=curr_Val;
        while (ma->next != NULL) {
            if (ma->next->data == curr_Val->data) {
                struct Node* duplicate ma->next;
                ma->next = ma->next->next;
                free(ma); 
            } else {
                ma=ma->next;
            }
        }
        curr_Val = curr_Val->next;
    }
    printf("Duplicates removed.\n");
}

void display(struct Node* head) {
    struct Node* curr_Val = head;
    if (curr_Val == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (curr_Val != NULL) {
        printf("%d -> ", curr_Val->data);
        curr_Val = curr_Val->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    printf("Enter %d elements for the list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        adEnd(&head, value);
    }

    // Print the original list
    printf("\nOriginal list:\n");
    display(head);

    // Remove duplicates
    remDup(head);

    // Print the modified list
    printf("\nList after removing duplicates:\n");
    display(head);

}
