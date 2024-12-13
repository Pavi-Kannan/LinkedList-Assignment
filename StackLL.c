#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct QueueNode* createNewNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isQueueEmpty(struct QueueNode* front) {
    return front == NULL;
}

void enqueue(struct QueueNode** front, struct QueueNode** rear, int data) {
    struct QueueNode* newNode = createNewNode(data);
    
    if (isQueueEmpty(*front)) {
        *front = *rear = newNode; 
    } else {
        (*rear)->next = newNode; 
        *rear = newNode; 
    }
    printf("%d added to the queue.\n", data);
}

int dequeue(struct QueueNode** front) {
    if (isQueueEmpty(*front)) {
        printf("Queue underflow! No elements to dequeue.\n");
        return -1; 
    }
    struct QueueNode* temp = *front;
    int dequeuedData = temp->data;
    *front = (*front)->next;  
    free(temp); 
    return dequeuedData;
}

int peekQueue(struct QueueNode* front) {
    if (isQueueEmpty(front)) {
        printf("Queue is empty!\n");
        return -1; 
    }
    return front->data;
}

void displayQueue(struct QueueNode* front) {
    if (isQueueEmpty(front)) {
        printf("Queue is empty.\n");
        return;
    }
    struct QueueNode* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct QueueNode* front = NULL;  
    struct QueueNode* rear = NULL;  
    int choice, data;

    while (1) {
        
        printf("\nQueue Operations using Linked List\n");
        printf("1. Enqueue (Add to Queue)\n");
        printf("2. Dequeue (Remove from Queue)\n");
        printf("3. Peek (View Front of Queue)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;

            case 2:
                data = dequeue(&front);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;

            case 3: 
                data = peekQueue(front);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;

            case 4: 
                displayQueue(front);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

}
