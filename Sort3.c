#include <stdio.h>

#define Size 100  
struct Node {
    int data;    
    int next;     
};

struct Node n[Size]; 
int head = -1;        
int start = 0;      

int newNode(int value) {
    if (start >= Size) {
        printf("Error: Node storage is full.\n");
        return -1;
    }
    int index = start;
    n[index].data = value;
    n[index].next = -1;
    start++;
    return index;
}

void addBegin(int value) {
    int newIndex = newNode(value);
    if (newIndex == -1) return;

    n[newIndex].next = head;
    head = newIndex;
    printf("Inserted %d at the beginning.\n", value);
}

void addEnd(int value) {
    int newIndex = newNode(value);
    if (newIndex == -1) return;

    if (head == -1) {
        head = newIndex;
        printf("Inserted %d as the first node.\n", value);
        return;
    }

    int current = head;
    while (n[current].next != -1) {
        current = n[current].next;
    }
    n[current].next = newIndex;
    printf("Inserted %d at the end.\n", value);
}

void temp(int value, int position) {
    if (position < 1) {
        printf("Error: Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        addBegin(value);
        return;
    }

    int newIndex = newNode(value);
    if (newIndex == -1) return;

    int current = head;
    for (int i = 1; i < position - 1 && current != -1; i++) {
        current = n[current].next;
    }

    if (current == -1) {
        printf("Position exceeds list length. Adding at the end.\n");
        addEnd(value);
        return;
    }

    n[newIndex].next = n[current].next;
    n[current].next = newIndex;
    printf("Inserted %d at position %d.\n", value, position);
}

void display() {
    if (head == -1) {
        printf("The list is empty.\n");
        return;
    }

    printf("List contents: ");
    int current = head;
    while (current != -1) {
        printf("%d -> ", n[current].data);
        current = n[current].next;
    }
    printf("NULL\n");
}

int main() {
    int option, value, position;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                addBegin(value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                addEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                temp(value, position);  // Updated function call
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
