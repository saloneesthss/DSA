/*Program to calculate sum of n numbers entered by the user*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i, *ptr, sum=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));

    //if memory cannot be allocated
    if(ptr==NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }
    
    printf("Enter elements: ");
    for(i=0; i<n; ++i) {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("Sum=%d",sum);

    free(ptr);  //Deallocating the memory
    return 0;
}