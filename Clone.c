#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    newNode->random=NULL;
    return newNode;
}

void addNode(struct Node** head,int value) {
    struct Node* newNode=create(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

struct Node* cloneLst(struct Node* head) {
    if (head==NULL) return NULL;

    struct Node* current=head;
    while (current!=NULL) {
        struct Node* copy = create(current->data);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    current = head;
    while (current != NULL) {
        if (current->random != NULL) {
            current->next->random=current->random->next;
        }
        current=current->next->next;
    }

    struct Node* original=head;
    struct Node* copyHead=head->next;
    struct Node* copy=copyHead;

    while (original!=NULL) {
        original->next=original->next->next;
        if (copy->next!=NULL) {
            copy->next=copy->next->next;
        }
        original=original->next;
        copy = copy->next;
    }

    return copyHead;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, ", temp->data);
        if (temp->random != NULL) {
            printf("Random points to: %d\n", temp->random->data);
        } else {
            printf("Random points to: NULL\n");
        }
        temp = temp->next;
    }
}

void Pointer(struct Node* head, int nodeValue, int randomValue) {
    struct Node* temp = head;
    struct Node* randomNode = NULL;

    while (temp != NULL) {
        if (temp->data == nodeValue) {
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL && randomValue != -1) {
        struct Node* randomTemp = head;
        while (randomTemp != NULL) {
            if (randomTemp->data == randomValue) {
                randomNode = randomTemp;
                break;
            }
            randomTemp = randomTemp->next;
        }
        temp->random = randomNode;
    }
}

int main() {
    struct Node* head = NULL;
    int n, value, randomValue, nodeValue;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        addNode(&head, value);
    }

    for (int i = 0; i < n; i++) {
        printf("For node %d, enter the value of the random pointer (-1 for NULL): ", i + 1);
        scanf("%d", &nodeValue);
        Pointer(head, value, nodeValue);
    }

    printf("\nOriginal Linked List with Random Pointers:\n");
    display(head);

    struct Node* clonedList = cloneLst(head);

    printf("\nCloned Linked List with Random Pointers:\n");
    display(clonedList);

}
