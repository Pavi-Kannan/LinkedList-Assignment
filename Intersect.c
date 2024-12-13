#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory not allocated!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEnd(struct Node** head,int value) {
    struct Node* newNode = create(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp=*head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

int getLn(struct Node* head) {
    int length=0;
    struct Node* temp=head;
    while (temp!=NULL) {
        length++;
        temp=temp->next;
    }
    return length;
}

struct Node* Intersect(struct Node* head1,struct Node* head2) {
    int len1=getLn(head1);
    int len2=getLn(head2);
    int diff=abs(len1 - len2);
    struct Node* ptr1=head1;
    struct Node* ptr2=head2;

    if (len1 > len2) {
        for (int i=0;i<diff;i++) {
            ptr1=ptr1->next;
        }
    } else {
        for (int i=0;i<diff;i++) {
            ptr2=ptr2->next;
        }
    }

    while (ptr1!=NULL&&ptr2!=NULL) {
        if (ptr1==ptr2) {
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return NULL;
}

void display(struct Node* head) {
    struct Node*temp=head;
    if (temp==NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp!=NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node*head1=NULL;
    struct Node*head2=NULL;
    int n1,n2,value,intersectionIndex;

    printf("Enter for the first linked list: ");
    scanf("%d",&n1);

    printf("Enter for the first linked list:\n");
    for (int i=0;i<n1;i++) {
        printf("Node %d: ",i+1);
        scanf("%d",&value);
        addEnd(&head1,value);
    }
    printf("Enter for the second linked list: ");
    scanf("%d",&n2);

    printf("Enter the values for the second linked list:\n");
    for (int i=0;i<n2;i++) {
        printf("Node %d: ",i+1);
        scanf("%d",&value);
        addEnd(&head2,value);
    }
    printf("Enter the intersection point index (0 for no intersection): ");
    scanf("%d", &intersectionIndex);
    if (intersectionIndex>0&&intersectionIndex<=n1) {
        struct Node*temp1=head1;
        struct Node* temp2=head2;
        for (int i=1;i<intersectionIndex;i++) {
            temp1=temp1->next;
        }
        while (temp2->next!=NULL) {
            temp2=temp2->next;
        }
        temp2->next=temp1; 
    }
    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);
    struct Node* intersection = Intersect(head1, head2);
    if (intersection != NULL) {
        printf("\nIntersection found at node with value: %d\n", intersection->data);
    } else {
        printf("\nNo intersection point found.\n");
    }

}
