#include <stdio.h>
long int factorial(int n);
int main() {
    int n=5;
    printf("The factorial of %d is: %d",n,factorial(n));
    return 0;
}
long int factorial(int n){
    if (n>1){
        return n*factorial(n-1);
    }else{
        return 1;
    }
}
