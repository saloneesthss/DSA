#include<stdio.h>
int sum=0, rem;
int reverse_function (int num)
{
    if(num) {
        rem=num%10;
        sum=sum*10+rem;
        reverse_function(num/10);
    }
    else {
        return sum;
    }
}
int main()
{
    int num=1456, reverse_number;   
    //Calling user defined function to perform reverse
    reverse_number=reverse_function(num);
    printf("The reverse of entered number is: %d",reverse_number);
    return 0;
}