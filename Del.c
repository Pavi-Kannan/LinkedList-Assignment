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
void adEnd(struct Node** head,int value) {
    struct Node* obj = adNode(value);
    if (*head == NULL) {
        *head = obj;
        return;
    }
    struct Node* curr_Val=*head;
    while (curr_Val->next!=NULL) {
        curr_Val=curr_Val->next;
    }
    curr_Val->next=obj;
}
void cLoop(struct Node* head,int mp) {
    if (head == NULL || mp <= 0) return;

    struct Node* temp=head;
    struct Node* loopNode=NULL;
    int counter=1;

    while (temp->next != NULL) {
        if (counter==mp) {
            loopNode=temp;
        }
        temp = temp->next;
        counter++;
    }

    if (loopNode !=NULL) {
        temp->next =loopNode;
        printf("Loop created at position %d.\n",mp);
    }
}
int findLoop(struct Node* head) {
    struct Node *slow = head,*fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { 
            printf("Loop detected in the linked list.\n");
            
            slow = head;
            if (slow == fast) { 
                while (fast->next != slow) { 
                    fast = fast->next;
                }
            } else {
                while (slow->next != fast->next) { 
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = NULL; 
            printf("Loop removed from the linked list.\n");
            return 1;
        }
    }

    printf("No loop detected\n");
    return 0;
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
    int n, value, choice,mp;

    printf("Enter the number of elements in linked list: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&value);
        adEnd(&head,value);
    }

    printf("\nLinked list created:\n");
    display(head);

    printf("\nDo you want to create a loop? (1 for Yes, 0 for No): ");
    scanf("%d",&choice);

    if (choice == 1) {
        printf("Enter the position to create a loop (1-based index): ");
        scanf("%d",&mp);
        cLoop(head,mp);
    }

    printf("\nChecking a loop in linked list...\n");
    if (findLoop(head)) {
        printf("\nAfter removing the loop:\n");
        display(head);
    } else {
        printf("\nNo loop found.\n");
        display(head);
    }
}
