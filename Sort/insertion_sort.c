#include<stdio.h>
int main()
{
    int arr[]={5,4,6,2,11};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    //Main logic starts here
    for (int i=1;i<n;i++) {
        int current=arr[i];
        int j=i-1;
        while (j>=0 && current<arr[j]) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    //Main logic ends here

    printf("\nSorted array: ");
    for (int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}