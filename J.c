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
    newNode->next=newNode;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; 
    }
}

int josephusProblem(struct Node** head, int k) {
    if (*head == NULL) {
        return -1; 
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != temp) {  
        int count = 1;
        while (count != k) {  
            prev = temp;
            temp = temp->next;
            count++;
        }

        prev->next = temp->next;
        printf("Eliminated: %d\n", temp->data);
        free(temp);  
        temp = prev->next;  
    }
    int lastPerson = temp->data;
    free(temp);
    return lastPerson;
}
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int n, k;

    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k (the elimination step): ");
    scanf("%d", &k);

    for (int i = 1; i <= n; i++) {
        insertEnd(&head, i);
    }

    printf("Initial Circular Linked List: ");
    printList(head);

    int lastPerson = josephusProblem(&head, k);

    printf("The last person remaining is: %d\n", lastPerson);

}
