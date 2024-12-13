#include <stdio.h>

int main() {
    void bubbleSortAlgo(int data[],int size) {
        for (int pass=0;pass<size-1;pass++) {
            for (int idx=0;idx<size-pass-1;idx++) {
                if (data[idx]>data[idx + 1]) {
                    int temp=data[idx];
                    data[idx]=data[idx + 1];
                    data[idx + 1]=temp;
                }
            }
        }
    }
    void selectionSortAlgo(int data[],int size) {
        for (int start=0;start<size-1;start++) {
            int smallest=start;
            for (int current=start+1;current<size; current++) {
                if (data[current]<data[smallest]) {
                    smallest=current;
                }
            }
            
            int temp=data[start];
            data[start]=data[smallest];
            data[smallest]=temp;
        }
    }

    // Function for Insertion Sort
    void insertionSortAlgo(int data[],int size) {
        for (int idx=1;idx<size;idx++) {
            int key =data[idx];
            int prevIdx = idx - 1;
            while (prevIdx>=0&&data[prevIdx]>key) {
                data[prevIdx+1]=data[prevIdx];
                prevIdx--;
            }
            data[prevIdx + 1]=key;
        }
    }

    void displaySortedArray(int data[],int size) {
        printf("Sorted Array: ");
        for (int i=0;i<size;i++) {
            printf("%d ",data[i]);
        }
        printf("\n");
    }

    int size,method;
    printf("Enter the number of items to sort: ");
    scanf("%d",&size);

    if (size<=0) {
        printf("Error: Array size must be positive.\n");
        return 1;
    }

    int elements[size];
    printf("Enter the elements to sort:\n");
    for (int i=0;i<size;i++) {
        scanf("%d",&elements[i]);
    }

    printf("\nSelect the sorting technique:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d",&method);

    switch (method) {
        case 1:
            bubbleSortAlgo(elements,size);
            printf("Sorted using Bubble Sort.\n");
            break;
        case 2:
            selectionSortAlgo(elements,size);
            printf("Sorted using Selection Sort.\n");
            break;
        case 3:
            insertionSortAlgo(elements,size);
            printf("Sorted using Insertion Sort.\n");
            break;
        default:
            printf("Invalid option selected. Exiting.\n");
            return 1;
    }

    displaySortedArray(elements,size);
   
}
