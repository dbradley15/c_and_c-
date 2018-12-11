/* CS261- Assignment 1 - Basic Pointers Practice*/
/* Name: Dan Bradley
 * Date: 12.11.18
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value is: %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
     printf("The address is: %p\n", iptr);
     
     /*Print the address of iptr itself*/
     printf("The address of the pointer itself is: %p\n\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 1;
    
    /*print the address of x*/
    printf("The address of x is: %p\n\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("The value of x is: %d\n\n", x);
    
    return 0;
}
