#include <stdio.h>
int sequentialSearch(int arr[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (arr[i]==key) {
            return i;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[]={4, 2, 7, 1, 9, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=7;
    printf("Array:");
    printArray(arr,n);
    int result=sequentialSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}