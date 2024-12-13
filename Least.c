#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
};

struct LeastAdd {
    int capacity;
    int size;
    struct Node* head;
    struct Node* tail;
    struct Node** hashMap;
};

struct Node* create(int key,int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key=key;
    newNode->value=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

struct LeastAdd* createLeast(int capacity) {
    struct LeastAdd* cache = (struct LeastAdd*)malloc(sizeof(struct LeastAdd));
    cache->capacity = capacity;
    cache->size=0;
    cache->head=create(0, 0);  
    cache->tail=create(0, 0); 
    cache->head->next=cache->tail;
    cache->tail->prev=cache->head;
    cache->hashMap = (struct Node**)calloc(capacity, sizeof(struct Node*));
    return cache;
}

void removeNode(struct Node* node, struct LeastAdd* cache) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    cache->size--;
}

void insertAtFront(struct Node* node, struct LeastAdd* cache) {
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
    cache->size++;
}

int get(struct LeastAdd* cache, int key) {
    int index = key % cache->capacity;
    struct Node* node = cache->hashMap[index];
    
    if (node == NULL) {
        return -1;  
    }

    removeNode(node, cache);
    insertAtFront(node, cache);

    return node->value;
}

void put(struct LeastAdd* cache, int key, int value) {
    int index = key % cache->capacity;
    struct Node* node = cache->hashMap[index];

    if (node != NULL) {
      
        node->value = value;
        removeNode(node, cache);
        insertAtFront(node, cache);
    } else {
        if (cache->size == cache->capacity) {
           
            struct Node* lruNode = cache->tail->prev;
            cache->hashMap[lruNode->key % cache->capacity] = NULL;
            removeNode(lruNode, cache);
            free(lruNode);
        }
        
       
        node = create(key, value);
        cache->hashMap[index] = node;
        insertAtFront(node, cache);
    }
}

void printCache(struct LeastAdd* cache) {
    struct Node* temp = cache->head->next;
    printf("Cache: ");
    while (temp != cache->tail) {
        printf("(%d: %d) <-> ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int capacity, numOperations;
    printf("Enter the capacity of the cache: ");
    scanf("%d", &capacity);

    struct LeastAdd* cache = createLeast(capacity);

    printf("Enter the number of operations: ");
    scanf("%d", &numOperations);

    for (int i=0;i<numOperations;i++) {
        int opType,key,value;
        printf("Enter operation type (1 for put, 2 for get): ");
        scanf("%d",&opType);

        if (opType == 1) {
            printf("Enter key and value for put operation: ");
            scanf("%d %d",&key,&value);
            put(cache,key,value);
            printCache(cache);  
        } else if (opType==2) {
            printf("Enter key for get operation: ");
            scanf("%d",&key);
            int result=get(cache, key);
            if (result == -1) {
                printf("Key not found in cache\n");
            } else {
                printf("Value for key %d: %d\n",key,result);
            }
            printCache(cache);  
        } else {
            printf("Invalid operation\n");
        }
    }

}
